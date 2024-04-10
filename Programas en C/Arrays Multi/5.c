#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	int i = 0, j = 0, k, pal = 0;
	char text[1000], vec[500][20], aux[20];
	gets(text);
	
	do {
		if(isalpha(text[i])) {
			if(pal == 0) {
				k = 0;
				pal = 1;
			}
			vec[j][k] = text[i];
			k++;
			if(!isalpha(text[i+1])) {
				vec[j][k] = '\0'
					j++;
				pal = 0;
			}
		}
		i++;
	} while(text[i] != '\0');
	
	for(i = 0; i < j; i++) {
		printf("\n%d - %s", i, vec[i]);
	}
	return 0;
}


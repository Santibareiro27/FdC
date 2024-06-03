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
		}
		else {
			if(pal == 1) {
				vec[j][k] = '\0';
				j++;
				pal = 0;
			}
		}
		i++;
	} while(text[i] != '\0');
	k = j;
	for(i = 0; i < k; i++) {
		for(j = 0; j < k-1; j++) {
			if(strcmp(vec[j],vec[j+1]) > 0) {
				strcpy(aux,vec[j]);
				strcpy(vec[j],vec[j+1]);
				strcpy(vec[j+1],aux);
			}
		}
	}
	for(i = 0; i < k; i++) {
		printf("\n%d - %s", i, vec[i]);
	}
	return 0;
}

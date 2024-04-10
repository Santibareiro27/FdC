#include <stdio.h>
#include <string.h>
#define N 30

int main(int argc, char *argv[]) {
	int i, ban = -1;
	char cad1[N], cad2[N];
	gets(cad1);
	for(i = 0; i <= strlen(cad1); i++) {
		if(ban == -1) {
			if(cad1[i] != ' ') {
				ban = i;
				i--;
			}
		}
		else {
			cad2[i-ban] = cad1[i];
		}
	}
	printf("\n%d", strlen(cad2));
	for(i = strlen(cad2)-1; i >= 0; i--) {
		if(cad2[i] != ' ') {
			cad2[i+1] = '\0';
			break;
		}
	}
	printf("\n%d", strlen(cad2));
	return 0;
}

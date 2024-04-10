#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int n, ban = 1;
	char cad[20];
	gets(cad);
	n = strlen(cad);
	for(int i = 0; i < n; i++) {
		if(cad[i] != cad[n-1-i]) {
			ban = 0;
		}
	}
	if(ban == 1) {
		printf("\nLa palabra \"%s\" es un palindromo", cad);
	}
	else {
		printf("\nLa palabra \"%s\" no es un palindromo", cad);
	}
	return 0;
}


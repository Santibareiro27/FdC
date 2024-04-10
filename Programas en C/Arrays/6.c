#include <stdio.h>
#include <string.h>
#define N 20

int main(int argc, char *argv[]) {
	char cad[N], aux;
	gets(cad);
	int n = strlen(cad);
	for(int i = 0; i < n/2; i++) {
		aux = cad[i];
		cad[i] = cad[n-1-i];
		cad[n-1-i] = aux;
	}
	puts(cad);
	return 0;
}


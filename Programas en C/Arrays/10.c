#include <stdio.h>
#include <string.h>
#define N 30

int main(int argc, char *argv[]) {
	int j, ind = -1;
	char cad1[N], cad2[N];
	printf("Ingrese la cadena 1: "), gets(cad1);
	printf("Ingrese la cadena 2: "), gets(cad2);
	if(strlen(cad1) > strlen(cad2)) {
		for(int i = 0; i < strlen(cad1); i++) {
			if(cad1[i] == cad2[0]) {
				for(j = 0; j < strlen(cad2); j++) {
					if(cad1[j+i] != cad2[j]) {
						break;
					}
				}
				if(j == strlen(cad2)){
					ind = i;
				}
			}
		}
		if(ind == -1)
			printf("La cadena 2 no esta incluida en la cadena 1");
		else
			printf("El indice donde comienza la cadena 2 es %d", ind);
	}
	else {
		printf("\nLa cadena 2 no puede ser mas larga que la cadena 1");
	}
	return 0;
}

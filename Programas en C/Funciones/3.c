#include <stdio.h>
#include <string.h>

void ordenar(char car[]) {
	char aux;
	for(int i = 0; i < strlen(car); i++) {
		for(int j = 0; j < strlen(car)-1; j++) {
			if(car[j] > car[j+1]) {
				aux = car[j];
				car[j] = car[j+1];
				car[j+1] = aux;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	char cad[20];
	scanf("%s",cad);
	ordenar(cad);
	puts(cad);
	return 0;
}


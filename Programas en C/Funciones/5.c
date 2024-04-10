#include <stdio.h>

int main(int argc, char *argv[]) {
	char cad[100];
	int c[26][2], ind[5] = {-1,-1,-1,-1,-1};
	gets(cad);
	//Carga de la matriz contadora
	for(int i = 0; i < 26; i++) {
		c[i][0] = i + (int)'a';
		c[i][1] = 0;
	}
	//Contar
	for(int i = 0; cad[i] != '\0'; i++) {
		for(int j = 0; j < 26; j++) {
			if((char)c[j][0] == cad[i]) {
				c[j][1]++;
			}
		}
	}
	//Buscar 5 mayores
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 5; j++) {
			if(ind[j] == -1 || c[i][1] > c[ind[j]][1]) {
				for (int k = 4; k > j; k--) {
					ind[k] = ind[k - 1];
				}
				ind[j] = i;
				break;
			}
		}
	}
	//Mostrar
	printf("\nLetras mas repetidas:");
	for(int j = 0; j < 5; j++) {
		printf("\n%c: %d",(char)c[ind[j]][0],c[ind[j]][1]);
	}
	return 0;
}


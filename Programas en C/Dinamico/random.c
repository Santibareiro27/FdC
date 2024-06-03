#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MOSTRAR(int f, int c, int **mat) {
	for(int i = 0; i < f; i++) {
		printf("\n|");
		for(int j = 0; j < c; j++) {
			printf("%d|",*(*(mat+i)+j));
		}
	}
}

int GEN() {
	return rand()%10;
}

int main(int argc, char *argv[]) {
	int **mat, n, m;
	srand(time(NULL));
	printf("Ingrese la cantidad de filas: ");
	scanf("%d",&n);
	printf("Ingrese la cantidad de columnas: ");
	scanf("%d",&m);
	mat = (int**)malloc(n*sizeof(int*));
	for(int i = 0; i < n; i++) {
		*(mat+i) = (int*)malloc(m*sizeof(int));
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			*(*(mat+i)+j) = GEN();
		}
	}
	MOSTRAR(n,m,mat);
	for(int i = 0; i < n; i++) {
		free(*(mat+i));
	}
	free(mat);
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int **mat, N, M;
	printf("Ingrese la cantidad de filas: ");
	scanf("%d",&N);
	printf("Ingrese la cantidad de columnas: ");
	scanf("%d",&M);
	mat = (int**)malloc(N*sizeof(int*));
	for(int i = 0; i < N; i++) {
		*(mat+i) = (int*)malloc(M*sizeof(int));
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			printf("Elemento %dx%d:", i, j);
			scanf("%d",(*(mat+i))+j);
		}
	}
	for(int i = 0; i < N; i++) {
		printf("\n|");
		for(int j = 0; j < M; j++) {
			printf("%d|",*((*(mat+i))+j));
		}
	}
	for(int i = 0; i < N; i++) {
		free(*(mat+i));
	}
	free(mat);
	return 0;
}


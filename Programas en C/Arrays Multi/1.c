#include <stdio.h>
#define N 3

int main(int argc, char *argv[]) {
	float mat1[N][N], mat2[N][N];
	int i, j, k;
	float aux;
	printf("\nIngrese la 1ra matriz:\n");
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("Elemento [%d][%d]: ", i, j);
			scanf("%f", &mat1[i][j]);
		}
	}
	printf("\nIngrese la 2da matriz:\n");
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("Elemento [%d][%d]: ", i, j);
			scanf("%f", &mat2[i][j]);
		}
	}
	printf("\nSuma:\n");
	for(i = 0; i < N; i++) {
		printf("\n|");
		for(j = 0; j < N; j++) {
			printf("%f|", mat1[i][j]+mat2[i][j]);
		}
	}
	printf("\nMultiplicacion:\n");
	for(i = 0; i < N; i++) {
		printf("\n|");
		for(j = 0; j < N; j++) {
			aux = 0;
			for(k = 0; k < N; k++) {
				aux += mat1[i][k]*mat2[k][j];
			}
			printf("%f|", aux);
		}
	}
	return 0;
}


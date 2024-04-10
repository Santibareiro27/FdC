#include <stdio.h>
#define N 4
#define M 5

int main(int argc, char *argv[]) {
	int i, j;
	float mat[N][M], vec[N], sum;
	for(i = 0; i < N; i++) {
		sum = 0;
		for(j = 0; j < M; j++) {
			printf("Ingrese el elemento [%d][%d]: ",i,j);
			scanf("%f",&mat[i][j]);
			sum += mat[i][j];
		}
		vec[i] = sum;
	}
	printf("\nMatriz:\n");
	for(i = 0; i < N; i++) {
		printf("\n|");
		for(j = 0; j < M; j++) {
			printf("%f|",mat[i][j]);
		}
	}
	printf("\n\nVector de sumas: |");
	for(i = 0; i < N; i++) {
		printf("%f|",vec[i]);
	}
	return 0;
}


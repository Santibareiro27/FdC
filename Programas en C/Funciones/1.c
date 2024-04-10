#include <stdio.h>
#define N 3

float MAT[N][N], TS[N][N], TI[N][N], DI[N][N];

void desTS() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i < j) {
				TS[i][j] = MAT[i][j];
			}
			else {
				TS[i][j] = 0;
			}
		}
	}
}

void desTI() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i > j) {
				TI[i][j] = MAT[i][j];
			}
			else {
				TI[i][j] = 0;
			}
		}
	}
}

void desDI() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i == j) {
				DI[i][j] = MAT[i][j];
			}
			else {
				DI[i][j] = 0;
			}
		}
	}
}

void mostrar(float mat[][N]) {
	printf("\n|");
	for(int i = 0; i < N; i++) {
		printf("\n|");
		for(int j = 0; j < N; j++) {
			printf("%f|",mat[i][j]);
		}
	}
}

int main() {
	printf("Ingrese una matriz de %dx%d:\n",N,N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("\nIngrese el elemento [%d][%d]: ",i,j);
			scanf("%f", &MAT[i][j]);
		}
	}
	desTS();
	desTI();
	desDI();
	mostrar(MAT);
	mostrar(TS);
	mostrar(TI);
	mostrar(DI);
	
	
	return 0;
}


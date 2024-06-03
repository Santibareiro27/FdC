#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(int argc, char *argv[]) {
	int *vec = (int*)malloc(N*sizeof(int));
	for(int i = 0; i < N; i++) {
		*(vec+i) = i+1;
	}
	for(int i = 0; i < N; i++) {
		printf("\n%d",*(vec+i));
	}
	return 0;
}


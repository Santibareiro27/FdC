#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int *vec, n;
	printf("Ingrese la cantidad de elementos: ");
	scanf("%d",&n);
	vec = (int*)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++) {
		printf("\nElemento %d: ",i+1);
		scanf("%d",vec+i);
	}
	printf("\nVector = |");
	for(int i = 0; i < n; i++) {
		printf("%d|",*(vec+i));
	}
	free(vec);
	return 0;
}


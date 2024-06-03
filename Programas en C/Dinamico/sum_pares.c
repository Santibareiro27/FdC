#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int *vec, n, sum = 0;
	printf("Ingrese el tamaño del vector: ");
	scanf("%d",&n);
	vec = (int*)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++) {
		printf("\nElemento %d: ",i+1);
		scanf("%d",vec+i);
	}
	for(int i = 0; i < n; i++) {
		if((*(vec+i))%2 == 0) {
			sum += (*(vec+i));
		}
	}
	printf("\nVector = |");
	for(int i = 0; i < n; i++) {
		printf("%d|",*(vec+i));
	}
	printf("\n\nLa suma de los elementos pares es: %d",sum);
	return 0;
}


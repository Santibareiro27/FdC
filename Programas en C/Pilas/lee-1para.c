#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo {
	int dato;
	nodo *sig;
};

int main(int argc, char *argv[]) {
	nodo *pri = NULL, *nn;
	do {
		nn = (nodo*)malloc(sizeof(nodo));
		printf("Ingrese un dato numerico: ");
		scanf("%d",&nn->dato);
		if(nn->dato != -1) {
			nn->sig = pri;
			pri = nn;
		}
	} while(nn->dato != -1);
	free(nn);
	printf("\nPila:");
	while(pri != NULL) {
		printf("\n%d",pri->dato);
		nn = pri;
		pri = pri->sig;
		free(nn);
	}
	return 0;
}


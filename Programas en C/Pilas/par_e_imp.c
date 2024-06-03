#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodo nodo;

struct nodo {
	int dato;
	nodo *sig;
};

void MOSTRAR(nodo *pila) {
	while(pila != NULL) {
		printf("\n%d",pila->dato);
		pila = pila->sig;
	}
	printf("\n");
}

void VACIAR(nodo **pila) {
	nodo *aux;
	while(*pila != NULL) {
		aux = *pila;
		*pila = (*pila)->sig;
		free(aux);
	}
}

int main(int argc, char *argv[]) {
	nodo *pri = NULL, *nn;
	do {
		nn = (nodo*)malloc(sizeof(nodo));
		printf("\nIngrese un dato numerico: ");
		scanf("%d",&nn->dato);
		nn->sig = pri;
		pri = nn;
		printf("Ingrese x para finalizar la carga: ");
		fflush(stdin);
	} while(tolower(getchar()) != 'x');
	printf("\nPila inicial:");
	MOSTRAR(pri);
	nodo *par = NULL, *imp = NULL, *aux = pri;
	while(aux != NULL) {
		nn = (nodo*)malloc(sizeof(nodo));
		nn->dato = aux->dato;
		if(aux->dato%2 == 0) {
			nn->sig = par;
			par = nn;
		}
		else {
			nn->sig = imp;
			imp = nn;
		}
		aux = aux->sig;
	}
	printf("\nPila par:");
	MOSTRAR(par);
	printf("\nPila impar:");
	MOSTRAR(imp);
	VACIAR(&pri);
	VACIAR(&par);
	VACIAR(&imp);
	return 0;
}

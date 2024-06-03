#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo {
	int daa;
	nodo * sig;
	nodo * ant;
}*pri = NULL, *ult = NULL;

int main(int argc, char *argv[]) {
	nodo *nn, *aux;;
	//CREAR LISTA
	for(int i = 0; i < 5; i++) {
		nn = (nodo*)malloc(sizeof(nodo));
		nn->daa = i+1;
		if(pri == NULL) {
			pri = nn;
			ult = nn;
			nn->sig = NULL;
			nn->ant = NULL;
		}
		else {
			ult->sig = nn;
			nn->ant = ult;
			nn->sig = NULL;
			ult = nn;
		}
	}
	//MOSTRAR LISTA
	printf("\nLista: |");
	nn = pri;
	while(nn != NULL) {
		printf("%d|", nn->daa);
		nn = nn->sig;
	}
	//INVERTIR LISTA
	nn = pri;
	pri = ult;
	ult = nn;
	while(nn != NULL) {
		aux = nn->sig;
		nn->sig = nn->ant;
		nn->ant = aux;
		nn = nn->ant;
	}
	//MOSTRAR LISTA INVERTIDA
	printf("\nLista: |");
	nn = pri;
	while(nn != NULL) {
		printf("%d|", nn->daa);
		nn = nn->sig;
	}
	return 0;
}


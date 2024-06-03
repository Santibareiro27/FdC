#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo{
	float peso;
	nodo *sig;
}*pri = NULL, *ult = NULL;

void LISTAR() {
	nodo *aux = pri;
	int c = 1;
	printf("\nLista:\n");
	do {
		printf("|%p|Posicion %d: %.2f Kg\n", (void*)aux, c, aux->peso);
		c++;
		aux = aux->sig;
	} while(aux != pri);
}

nodo *LOCALIZAR(int pos) {
	nodo *act = pri;
	int c = 1;
	do {
		if(c == pos) {
			return act;
		}
		act = act->sig;
		c++;
	} while(act != pri);
	return NULL;
}

nodo *BUSCAR(float p) {
	nodo *aux = pri;
	do {
		if(aux->peso == p) {
			return aux;
		}
		aux = aux->sig;
	} while(aux != pri);
	return NULL;
}

void BORRAR(float p) {
	nodo *ant, *aux = pri;
	do {
		if(aux->peso == p) {
			goto borrador;
		}
		ant = aux;
		aux = aux->sig;
	} while(aux != pri);
	return;
	borrador:
	if(pri == ult) {
		pri = NULL;
		ult = NULL;
	}
	else if(aux == pri) {
		pri = pri->sig;
		ult->sig = pri;
	}
	else if(aux == ult) {
		ult = ant;
		ult->sig = pri;
	}
	else {
		ant->sig = aux->sig;
	}
	free(aux);
}

void INSERTAR(int pos) {
	nodo *ant = NULL, *act = pri;
	int c = 1;
	do {
		if(c == pos) {
			goto ins;
		}
		ant = act;
		act = act->sig;
		c++;
	} while(act != pri);
	if(c != pos) {
		return;
	}
	ins:
	act = (nodo*)malloc(sizeof(nodo));
	printf("\nPeso: ");
	scanf("%f", &act->peso);
	if(pri == NULL) {
		act->sig = act;
		pri = act;
		ult = pri;
	}
	else if(ant == NULL) {
		act->sig = pri;
		pri = act;
		ult->sig = pri;
	}
	else if(ant == ult) {
		ult->sig = act;
		ult = act;
		ult->sig = pri;
	}
	else {
		act->sig = ant->sig;
		ant->sig = act;
	}
}

void ORDENAR() {
	nodo *aux1, *aux2, nn;
	aux1 = pri;
	while(aux1 != ult) {
		aux2 = aux1->sig;
		while(aux2 != pri) {
			if(aux2->peso < aux1->peso) {
				nn = *aux1;
				*aux1 = *aux2;
				*aux2 = nn;
				aux2->sig = aux1->sig;
				aux1->sig = nn.sig;
			}
			aux2 = aux2->sig;
		}
		aux1 = aux1->sig;
	}
}

int main(int argc, char *argv[]) {
	int num;
	float pes;
	nodo *nn;
	do {
		printf("Ingrese la cantidad de pesos: ");
		scanf("%d",&num);
	} while(num < 1);
	for(int i = 0; i < num; i++) {
		nn = (nodo*)malloc(sizeof(nodo));
		printf("\nPeso %d: ", i+1);
		scanf("%f", &nn->peso);
		if(pri == NULL) {
			pri = nn;
			ult = nn;
			nn->sig = pri;
		}
		else {
			ult->sig = nn;
			ult = nn;
			nn->sig = pri;
		}
	}
	for(;;) {
		printf("\n\nMenu");
		printf("\n1 - Listar pesos");
		printf("\n2 - Buscar peso");
		printf("\n3 - Borrar peso");
		printf("\n4 - Insertar en lista");
		printf("\n5 - Localizar posicion");
		printf("\n6 - Ordenar pesos");
		printf("\nS - Salir");
		printf("\nOpcion: ");
		fflush(stdin);
		switch(getchar()) {
			
		case'1':
			if(pri != NULL) {
				LISTAR();
			}
			else {
				printf("\nERROR: La lista esta vacia\n");
			}
			break;
			
		case'2':
			if(pri != NULL) {
				printf("\nIngrese el peso que desea buscar: ");
				scanf("%f", &pes);
				nn = BUSCAR(pes);
				if(nn != NULL) {
					printf("\nEl peso %.2f Kg esta en la posicion %p", pes, (void*)nn);
				}
				else {
					printf("\nERROR: No hay tal peso cargado en la lista\n");
				}
			}
			else {
				printf("\nERROR: La lista esta vacia\n");
			}
			break;
			
		case'3':
			if(pri != NULL) {
				printf("\nIngrese el peso que desea borrar: ");
				scanf("%f", &pes);
				BORRAR(pes);
			}
			else {
				printf("\nERROR: La lista esta vacia\n");
			}
			break;
			
		case'4':
			num = 1;
			if(pri != NULL) {
				do {
					printf("\nIngrese la posicion del nodo: ");
					scanf("%d",&num);
				} while(num < 1);
			}
			INSERTAR(num);
			break;
			
		case'5':
			if(pri != NULL) {
				printf("\nIngrese la posicion del nodo: ");
				scanf("%d",&num);
				nn = LOCALIZAR(num);
				if(nn != NULL) {
					printf("\nEl peso de la posicion %d es: %f Kg\n", num, nn->peso);
				}
				else {
					printf("\nERROR: No existe un nodo en esa posicion\n");
				}
			}
			else {
				printf("\nERROR: La lista esta vacia\n");
			}
			break;
			
		case'6':
			if(pri != NULL) {
				ORDENAR();
			}
			else {
				printf("\nERROR: La lista esta vacia\n");
			}
			break;
			
		case'S':
		case's':
			return 0;
			break;
			
		default:
			printf("\nERROR: La lista esta vacia\n");
			break;
		}
	}
}


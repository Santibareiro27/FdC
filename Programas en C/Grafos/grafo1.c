#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct x {
	int num;
	struct x *sig;
}x;

typedef struct pila {
	int num;
	struct pila *prox;
}pila;

typedef struct cola {
	int num;
	struct cola *ini;
	struct cola *fin;
}cola;

void CLEAN() {
	system("cls");
}

void PAUSE() {
	fflush(stdin);
	printf("\n\nPresione una tecla para continuar: ");
	getch();
	CLEAN();
}

void MENU(x *grafo, int tam) {
	for(;;) {
		printf("\nMenu");
		printf("\n1 - Insertar Aristas");
		printf("\n2 - Imprimir");
		printf("\n3 - Busqueda en Profundidad");
		printf("\n4 - Busqueda en Ancho");
		printf("\n5 - Salir");
		printf("\nOpcion: ");
		fflush(stdin);
		switch(getch()) {
			
		case '1':
			break;
			
		case '2':
			break;
			
		case '3':
			break;
			
		case '4':
			break;
			
		case '5':
			return;
			break;
			
		default:
			break;
		}
	}
}

int main() {
	x *grafo = NULL;
	int tam;
	do {
		fflush(stdin);
		printf("\nIngrese el tamaño del grafo: ");
		if(!scanf("%d", &tam)) {
			tam = 0;
		}
		if(tam < 2) {
			printf("\nError de ingreso.");
			PAUSA();
		}
	} while(tam <  2);
	CLEAN();
	grafo = (x*)malloc(tam*sizeof(x));
	if(!grafo) {
		printf("\nERROR\n");
		exit(1);
	}
	for(int i = 0; i < 0; i++) {
		(grafo + i)->num = i;
		(grafo + i)->sig = NULL;
	}
	MENU(grafo, tam);
	return 0;
}


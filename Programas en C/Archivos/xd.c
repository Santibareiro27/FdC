#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 40

typedef struct nodo nodo;

struct nodo{
	char nom[N+1];
	char cod[4];
	float pre;
	nodo *sig;
}*lista = NULL;

int VERIFICAR(char fname[20]) {
	FILE *veri;
	if((veri = fopen(fname, "r"))) {
		fclose(veri);
		return 0;
	}
	else {
		return 1;
	}
}

void CREAR_ARCHIVO(char fname[20]) {
	FILE *newf;
	if((newf = fopen(fname, "w"))) {
		fclose(newf);
	}
	else {
		exit(1);
	}
}

void RECUPERAR(char fname[20]) {
	struct nodo *nn;
	FILE *read;
	if (!(read = fopen(fname, "r"))) {
		printf("\nERROR al recuperar el archivo\n");
		exit(1);
	}
	
	char buffer[256];
	while (fgets(buffer, sizeof(buffer), read)) {
		nn = (struct nodo*)malloc(sizeof(struct nodo));
		if (nn == NULL) {
			printf("\nERROR: No se pudo asignar memoria\n");
			fclose(read);
			exit(1);
		}
		
		// Leer y almacenar el nombre
		strcpy(nn->nom, strtok(buffer, "\n"));
		
		// Leer y almacenar el código
		if (fgets(buffer, sizeof(buffer), read) != NULL) {
			strcpy(nn->cod, strtok(buffer, "\n"));
		} else {
			free(nn);
			break;
		}
		
		// Leer y almacenar el precio
		if (fscanf(read, "%f\n", &nn->pre) != 1) {
			free(nn);
			break;
		}
		
		nn->sig = lista;
		lista = nn;
	}
	fclose(read);
}

void GUARDAR(char fname[20]) {
	FILE *save;
	if(!(save = fopen(fname, "w"))) {
		printf("No se pudo guardar el archivo");
		return;
	}
	nodo *aux = lista;
	while(lista != NULL) {
		aux = lista;
		lista = lista->sig;
		printf("\n%s", aux->nom);
		printf("\n%s", aux->cod);
		printf("\n%.2f", aux->pre);
		fflush(stdin);
		fprintf(save,"%s\n", aux->nom);
		fflush(stdin);
		fprintf(save,"%s\n", aux->cod);
		fflush(stdin);
		fprintf(save,"%f\n", aux->pre);
		free(aux);
	}
	fclose(save);
}

void INSERTAR() {
	nodo *nn = (nodo*)malloc(sizeof(nodo));
	printf("\nIngrese el nombre del producto: ");
	fflush(stdin);
	fgets(nn->nom,N,stdin);
	strcpy(nn->nom, strtok(nn->nom, "\n"));
	do {
		printf("\nIngrese el codigo de producto: ");
		fflush(stdin);
		fgets(nn->cod,4,stdin);
	} while(!isdigit(nn->cod[0]) || !isdigit(nn->cod[1]) || !isdigit(nn->cod[2]));
	do {
		printf("\nIngrese el precio del producto: ");
		fflush(stdin);
		if(!scanf("%f",&nn->pre)) {
			nn->pre = 0;
		}
	} while(nn->pre <= 0);
	nn->sig = lista;
	lista = nn;
}

int main(int argc, char *argv[]) {
	char fname[20] = "products.txt";
	if(VERIFICAR(fname)) {
		CREAR_ARCHIVO(fname);
	}
	else {
		RECUPERAR(fname);
	}
	INSERTAR();
	GUARDAR(fname);
	return 0;
}

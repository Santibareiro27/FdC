#include <stdio.h>
#define P 2
#define E 5

void mostrar(char mat[P][E]) {
	for(int i = 0; i < P; i++) {
		printf("\n|");
		for(int j = 0; j < E; j++) {
			printf("%c|",mat[i][j]);
		}
	}
	printf("\n");
}

void carga(char mat[P][E]) {
	int i, j;
	do {
		printf("\nIngrese un espacio a ocupar");
		printf("\nPiso: ");
		scanf("%d",&i);
		printf("Espacio: ");
		scanf("%d",&j);
		if(!(i >= 1 && i <= P && j >= 1 && j <= E)) {
			printf("\nERROR: Ingrese nuevamente\n");
		}
	} while(!(i >= 1 && i <= P && j >= 1 && j <= E));
	mat[i-1][j-1] = 'O';
}

void liberar(char mat[P][E]) {
	char op;
	int i, j;
	do {
		printf("\nIngrese un espacio a liberar");
		printf("\nPiso: ");
		scanf("%d",&i);
		printf("Espacio: ");
		scanf("%d",&j);
		if(!(i >= 1 && i <= P && j >= 1 && j <= E)) {
			printf("\nERROR: Ingrese nuevamente\n");
		}
	} while(!(i >= 1 && i <= P && j >= 1 && j <= E));
	i--;
	j--;
	if(mat[i][j] == 'O') {
		do {
			printf("\nSeguro que quiere liberar el espacio?(1->si / 0->no): ");
			fflush(stdin);
			op = getchar();
			if(op == '1') {
				printf("\nEspacio liberado, debe pagar la suma de $500");
				mat[i][j] = 'L';
			}
			else if(op == '0') {
				printf("\nSe ha cancelado la operacion");
			}
			else {
				printf("\nERROR: Ingrese nuevamente\n");
			}
		} while(op != '1' && op != '0');
	}
	else {
		printf("\nEl espacio ya estaba libre");
	}
}

int main(int argc, char *argv[]) {
	char mat[P][E], opc;
	int i, j, o = 0, l = 0;
	for(i = 0; i < P; i++)
		for(j = 0; j < E; j++)
			mat[i][j] = 'L';
	do {
		printf("\nIngrese un espacio que este ocupado (piso 9 para salir.)");
		printf("\nPiso: ");
		scanf("%d",&i);
		if(i == 9) {
			break;
		}
		printf("Espacio: ");
		scanf("%d",&j);
		if(i >= 1 && i <= P && j >= 1 && j <= E) {
			i--;
			j--;
			mat[i][j] = 'O';
		}
	} while(1);
	printf("\n--Menu--\n");
	printf("1. Ocupar espacio\n");
	printf("2. Liberar espacio\n");
	printf("3. Cerrar turno\n");
	printf("Opcion: ");
	fflush(stdin);
	opc = getchar();
	switch(opc) {
		
	case '1':
		mostrar(mat);
		carga(mat);
		break;
		
	case '2':
		mostrar(mat);
		liberar(mat);
		break;
		
	case '3':
		for(i = 0; i < P; i++) {
			for(j = 0; j < E; j++) {
				if(mat[i][j] == 'O')
					o++;
				else
					l++;
			}
		}
		printf("\nNumero de espacios ocupados: %d/%d",o,P*E);
		printf("\nNumero de espacios libres: %d/%d\n",l,P*E);
		break;
	}
	mostrar(mat);
	return 0;
}


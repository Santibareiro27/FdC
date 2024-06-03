#include <stdio.h>
#include <stdlib.h>

int SUMA(int a, int b) {
	return a+b;
}

int REST(int a, int b) {
	return a-b;
}

int MULT(int a, int b) {
	return a*b;
}

int (*PTRF)(int a, int b);

int main(int argc, char *argv[]) {
	int x, y;
	printf("\n\nIngrese dos valores:\n");
	printf("\nValor x: ");
	scanf("%d",&x);
	printf("\nValor y: ");
	scanf("%d",&y);
	for(;;) {
		PTRF = NULL;
		printf("\nDesea sumar, restar o multiplicar los valores?");
		printf("\n1 - SUMAR");
		printf("\n2 - RESTAR");
		printf("\n3 - MULTIPLICAR");
		printf("\n4 - CAMBIAR VALORES");
		printf("\ns - SALIR");
		printf("\nOpcion: ");
		fflush(stdin);
		switch(getchar()) {
			
		case'1':
			PTRF = SUMA;
			break;
			
		case'2':
			PTRF = REST;
			break;
			
		case'3':
			PTRF = MULT;
			break;
			
		case'4':
			printf("\nValor x: ");
			scanf("%d",&x);
			printf("\nValor y: ");
			scanf("%d",&y);
			break;
			
		case's':
			exit(0);
			break;
			
		default:
			printf("\nERROR\n");
			break;
		}
		if(PTRF != NULL) {
			printf("\nResultado: %d\n",(*PTRF)(x,y));
		}
	}
	return 0;
}


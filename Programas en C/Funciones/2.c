#include <stdio.h>

void tabla(float pen, float ord, int ini, int fin) {
	float f;
	printf("\n|    x    |   f(x)  |");
	for(int i = ini; i <= fin; i++) {
		f = (float)i * pen + ord;
		if(i < 0) {
			if((float)i * pen + ord < 0)
				printf("\n|%d|%f|",(float)i,f);
			else
				printf("\n|%d| %f|",(float)i,f);
		}
		else {
			if((float)i * pen + ord < 0)
				printf("\n| %d|%f|",(float)i,f);
			else
				printf("\n| %d| %f|",(float)i,f);
		}
	}
}

int main(int argc, char *argv[]) {
	float a, b, c;
	int ini, fin;
	printf("Ingrese la ecuacion de una recta en forma ax+by=c:\n");
	printf("a = ");
	scanf("%f", &a);
	printf("b = ");
	scanf("%f", &b);
	printf("c = ");
	scanf("%f", &c);
	if(b == 0) {
		puts("ERROR: b no puede ser 0");
		return 1;
	}
	printf("\nPendiente = %f\nOrdenada = %f",-a/b,c/b);
	printf("\n\nIngrese un intervalo:\nInicio: ");
	scanf("%d",&ini);
	printf("Final: ");
	scanf("%d",&fin);
	tabla(-a/b,c/b,ini,fin);
	return 0;
}


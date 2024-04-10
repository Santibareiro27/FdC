#include <stdio.h>
#define N 30

int main(int argc, char *argv[]) {
	char n[N], a1[N], a2[N], nc[100];
	printf("\nIngrese el nombre: ");
	gets(n);
	printf("\nIngrese el primer apellido: ");
	gets(a1);
	printf("\nIngrese el segundo apellido: ");
	gets(a2);
	sprintf(nc, "%s%s, %s", a1, a2, n);
	puts(nc);
	return 0;
}


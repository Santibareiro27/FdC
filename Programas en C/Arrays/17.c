#include <stdio.h>
#include <string.h>
#define N 30

int main(int argc, char *argv[]) {
	char cad1[N], cad2[N];
	printf("ingrese una cadena: ");
	gets(cad1);
	printf("ingrese otra cadena: ");
	gets(cad2);
	if(strcmp(cad1,cad2) <= 0)
		printf("\nMenor o igual");
	return 0;
}


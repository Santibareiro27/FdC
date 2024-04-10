#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char nom[60], a1[20], a2[20];
	printf("Ingrese el nombre: ");
	scanf("%s", nom);
	printf("Ingrese el primer apellido: ");
	scanf("%s", a1);
	printf("Ingrese el segundo apellido: ");
	scanf("%s", a2);
	
	strcat(nom," ");
	strcat(nom,a1);
	strcat(nom," ");
	strcat(nom,a2);
	
	puts(nom);
	return 0;
}


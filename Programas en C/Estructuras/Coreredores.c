#include <stdio.h>
#include <ctype.h>

struct corredor {
	char nombre[40];
	int edad;
	char sexo;
	char club[20];
};

int main(int argc, char *argv[]) {
	struct corredor cor1;
	printf("\nIngrese su Nombre: ");
	gets(cor1.nombre);
	fflush(stdin);
	do {
		printf("Ingrese su edad: ");
		scanf("%d",&cor1.edad);
		fflush(stdin);
	} while(cor1.edad < 13 || cor1.edad > 80);
	do {
		printf("Ingrese su sexo(M/F): ");
		cor1.sexo = toupper(getchar());
		fflush(stdin);
	} while(cor1.sexo != 'M' && cor1.sexo != 'F');
	printf("Ingrese su club: ");
	gets(cor1.club);
	fflush(stdin);
	if(cor1.edad <= 18) {
		printf("\nSu categoria asignada es Juvenil");
	}
	else if(cor1.edad <= 40) {
		printf("\nSu categoria asignada es Senior");
	}
	else if(cor1.edad > 40) {
		printf("\nSu categoria asignada es Veterano\n");
	}
	printf("\nNombre: %s",cor1.nombre);
	printf("\nEdad: %d",cor1.edad);
	printf("\nSexo: %c",cor1.sexo);
	printf("\nClub: %s",cor1.club);
	return 0;
}


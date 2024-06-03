#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char str1[] = "miau el otro dia miau, si es que miau";
	char str2[20], *ptr;
	int cont;
	for(;;) {
		cont = 0;
		ptr = str1;
		printf("\n\nTexto: miau el otro dia miau, si es que miau\n");
		printf("\nIngrese una palabra a buscar (\"exit\" par salir): ");
		fflush(stdin);
		gets(str2);
		fflush(stdin);
		if(!strcmp(str2,"exit")) {
			return 0;
		}
		while((ptr = strstr(ptr,str2)) != NULL) {
			cont++;
			ptr += strlen(str2);
		}
		if(cont == 0) {
			printf("\nNo se encontro\n");
		}
		else {
			printf("\nSe encontro %d veces\n",cont);
		}
	}
}


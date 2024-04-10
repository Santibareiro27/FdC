#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char verb[20], con[100] = "Yo ", tipo;
	do {
		printf("\nIngrese un verbo regular infinitivo: ");
		gets(verb);
		tipo = verb[strlen(verb) - 2];
		verb[strlen(verb) - 2] = '\0';
		if(strlen(verb) <= 1)
			printf("\nERROR\n");
	} while(strlen(verb) <= 1);
	strcat(con, verb);
	strcat(con, "o, tu ");
	switch(tipo) {
		
	case 'a':
		strcat(con, verb);
		strcat(con, "as, el ");
		strcat(con, verb);
		strcat(con, "a");
		break;
		
	case 'e':
		strcat(con, verb);
		strcat(con, "es, el ");
		strcat(con, verb);
		strcat(con, "e");
		break;
		
	case 'i':
		strcat(con, verb);
		strcat(con, "es, el ");
		strcat(con, verb);
		strcat(con, "e");
		break;
		
	default:
		printf("\nNo se ingreso un verbo infinitivo");
		return 1;
		break;
	}
	puts(con);
	return 0;
}


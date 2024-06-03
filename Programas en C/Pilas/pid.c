#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

typedef struct task {
	char name[20];
	int pid;
	char user[10];
	struct task *sig;
}task;

int PIDGEN(task *man) {
	task *act;
	int pid_temp, ban;
	do {
		ban = 0;
		pid_temp = rand()%100;
		act = man;
		while(act != NULL) {
			if(act->pid == pid_temp) {
				ban = 1;
			}
			act = act->sig;
		}
	} while(ban);
	return pid_temp;
}

void APILAR(task **man) {
	task *nn;
	char opc;
	nn = (task*)malloc(sizeof(task));
	printf("\nIngrese el nombre de la tarea: ");
	gets(nn->name);
	fflush(stdin);
	nn->pid = PIDGEN(*man);
	do {
		printf("\nUsuario: ");
		printf("\n| 1 - USER | 2 - SYSTEM | 3 - VIRUS |: ");
		opc = getchar();
		switch(opc) {
			
		case'1':
			sprintf(nn->user,"USER       ");
			break;
			
		case'2':
			sprintf(nn->user,"SYSTEM     ");
			break;
			
		case'3':
			sprintf(nn->user,"VIRUS      ");
			break;
			
		default:
			printf("\nERROR\n");
			break;
		}
	} while(opc != '1' && opc != '2' && opc != '3');
	nn->sig = *man;
	*man = nn;
}

void MOSTRAR(task *man) {
	printf("\n ______________________________________");
	printf("\n|   OWNER   | PID |        NAME        |");
	while(man != NULL) {
		printf("\n|-----------|-----|--------------------|");
		printf("\n|%s|",man->user);
		if(man->pid < 10) {
			printf("0");
		}
		printf("%d   |%s",man->pid,man->name);
		for(int i = 20; i > strlen(man->name); i--) {
			putchar(' ');
		}
		putchar('|');
		man = man->sig;
	}
	printf("\n|___________|_____|____________________|\n");
}

void DESAPILAR(task **man) {
	if(*man == NULL) {
		return;
	}
	task *aux;
	aux = *man;
	*man = (*man)->sig;
	free(aux);
}

void APAGAR(task **man) {
	int cont = 0;
	MOSTRAR(*man);
	while(*man != NULL) {
		DESAPILAR(man);
		cont++;
	}
	printf("\nFaltaron %d tareas por finalizar.\n",cont);
	exit(1);
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	task *manager = NULL;
	char opc;
	for(;;) {
		printf("\nMenu\n");
		printf("1- Apilar\n");
		printf("2- Generar PID\n");
		printf("3- Mostrar stack\n");
		printf("4- Desapilar\n");
		printf("5- Apagar\n");
		printf("Opcion: ");
		fflush(stdin);
		scanf("%c",&opc);
		fflush(stdin);
		opc = toupper(opc);
		switch(opc) {
			
		case '1':
			APILAR(&manager);
			break;
			
		case '2':
			printf("\nUn PID valido es: %d\n",PIDGEN(manager));
			break;
			
		case '3':
			MOSTRAR(manager);
			break;
			
		case '4':
			DESAPILAR(&manager);
			break;
			
		case '5':
			APAGAR(&manager);
			break;
			
		default:
			break;
		}
	}
	return 0;
}


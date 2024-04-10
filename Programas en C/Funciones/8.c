#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

char tabla[3][3];

void CLEAR() {
	for(int i = 0; i < 100; i++) {
		putchar('\n');
	}
}

void CONTINUAR() {
	printf("\nPresione cualquier tecla para continuar: ");
	getche();
}

void TABLERO() {
	for(int i = 0; i < 13; i++) {
		if(i%2 == 1) {
			printf("|       |       |       |");
		}
		else if(i%4 == 0) {
			printf("+-------+-------+-------+");
		}
		else {
			printf("|   %c   |   %c   |   %c   |",tabla[i/5][0],tabla[i/5][1],tabla[i/5][2]);
		}
		printf("\n");
	}
	printf("\n\n\n\n\n\n\n");
}

void TURNO_O() {
	char cas;
	while(1) {
		TABLERO();
		printf("Ingrese el numero de la casilla que desea ocupar: ");
		fflush(stdin);
		cas = getche();
		int i = ((int)cas-'1')/3, j = ((int)cas-'1')%3;
		if(tabla[i][j] != 'X' && tabla[i][j] != 'O') {
			tabla[i][j] = 'O';
			break;
		}
		else {
			printf("\nEsa posicion ya esta ocupada\n");
			CONTINUAR();
			CLEAR();
		}
	}
}

void TURNO_X() {
	int ind;
	while(1) {
		ind = rand()%9;
		if(tabla[ind/3][ind%3] != 'X' && tabla[ind/3][ind%3] != 'O') {
			tabla[ind/3][ind%3] = 'X';
			break;
		}
	}
}

char WINER(char player) {
	char win ;
	int j, k;
	
	win = player;
	for(j = 0; j < 3; j++) {
		if(tabla[j][j] != player) {
			win = 'N';
		}
	}
	if(win == player) {
		return player;
	}
	
	win = player;
	k = 2;
	for(j = 0; j < 3; j++) {
		if(tabla[j][k] != player) {
			win = 'N';
		}
		k--;
	}
	if(win == player) {
		return player;
	}
	
	for(j = 0; j < 3; j++) {
		win = player;
		for(k = 0; k < 3; k++) {
			if(tabla[j][k] != player) {
				win = 'N';
			}
		}
		if(win == player) {
			return player;
		}
	}
	
	for(j = 0; j < 3; j++) {
		win = player;
		for(k = 0; k < 3; k++) {
			if(tabla[k][j] != player) {
				win = 'N';
			}
		}
		if(win == player) {
			return player;
		}
	}
	
	return 'N';
}

void PARTIDA() {
	char winer = 'N';
	printf("La maquina comenzara y usara X, usted sera O\n");
	CONTINUAR();
	for(int i = 0; i < 4; i++) {
		CLEAR();
		TURNO_O();
		winer = WINER('O');
		if(winer == 'O') {
			break;
		}
		CLEAR();
		TURNO_X();
		winer = WINER('X');
		if(winer == 'X') {
			break;
		}
	}
	CLEAR();
	TABLERO();
	switch(winer) {
		
	case 'N':
		printf("Ha sido un empate\n");
		break;
		
	case 'O':
		printf("Ganaste!\n");
		break;
		
	case 'X':
		printf("Perdiste...\n");
		break;
	}
	CONTINUAR();
}

int main(int argc, char *argv[]) {
	char opc;
	srand(time(NULL));
	while(1) {
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				tabla[i][j] = (char)(i*3+j) + '1';
			}
		}
		tabla[1][1] = 'X';
		CLEAR();
		printf("_______               _______  _____       _______  ___\n");
		printf("   |      /\\             |    |               |      |\n");
		printf("   |     /__\\    ____    |    |_____  ____    |      |\n");
		printf("   |    /    \\           |    |               |      |\n");
		printf("   |   /      \\          |    |_____          |     _|_\n");
		printf("\n\n\nPresione 'J' para jugar y 'E' para salir: ");
		opc = tolower(getche());
		if(opc == 'e') {
			break;
		}
		else if(opc == 'j') {
			CLEAR();
			PARTIDA();
		}
		else {
			continue;
		}
	}
	return 0;
}


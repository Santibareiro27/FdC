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

void TURNO_J(char jugador) {
	char cas;
	while(1) {
		TABLERO();
		printf("Ingrese el numero de la casilla que desea ocupar: ");
		fflush(stdin);
		cas = getche();
		if(cas < '1' || cas > '9') {
			CLEAR();
			continue;
		}
		int i = ((int)cas-'1')/3, j = ((int)cas-'1')%3;
		if(tabla[i][j] != 'X' && tabla[i][j] != 'O') {
			tabla[i][j] = jugador;
			break;
		}
		else {
			printf("\nEsa posicion ya esta ocupada\n");
			CONTINUAR();
			CLEAR();
		}
	}
}

void TURNO_IA(char ia, char ju) {
	char pl, maywin = 'N';
	int i, j, con, cord[2];
	for(int c = 0; c < 2; c++) {
		if(c == 0) {
			pl = ia;
		}
		else {
			pl = ju;
		}
		
		con = 0;
		for(i = 0; i < 3; i++) {
			if(tabla[i][i] == pl) {
				con++;
			}
			else {
				cord[0] = i;
				cord[1] = i;
			}
		}
		if(con == 2 && tabla[cord[0]][cord[1]] != 'X' && tabla[cord[0]][cord[1]] != 'O') {
			maywin = pl;
			break;
		}
		
		con = 0;
		j = 2;
		for(i = 0; i < 3; i++) {
			if(tabla[i][j] == pl) {
				con++;
			}
			else {
				cord[0] = i;
				cord[1] = j;
			}
			j--;
		}
		if(con == 2 && tabla[cord[0]][cord[1]] != 'X' && tabla[cord[0]][cord[1]] != 'O') {
			maywin = pl;
			break;
		}
		
		for(i = 0; i < 3; i++) {
			con = 0;
			for(j = 0; j < 3; j++) {
				if(tabla[i][j] == pl) {
					con++;
				}
				else {
					cord[0] = i;
					cord[1] = j;
				}
			}
			if(con == 2 && tabla[cord[0]][cord[1]] != 'X' && tabla[cord[0]][cord[1]] != 'O') {
				maywin = pl;
				break;
			}
		}
		if(maywin != 'N') {
			break;
		}
		
		for(i = 0; i < 3; i++) {
			con = 0;
			for(j = 0; j < 3; j++) {
				if(tabla[j][i] == pl) {
					con++;
				}
				else {
					cord[0] = j;
					cord[1] = i;
				}
			}
			if(con == 2 && tabla[cord[0]][cord[1]] != 'X' && tabla[cord[0]][cord[1]] != 'O') {
				maywin = pl;
				break;
			}
		}
		if(maywin != 'N') {
			break;
		}
	}
	if(maywin != 'N') {
		tabla[cord[0]][cord[1]] = ia;
	}
	else {
		while(1) {
			con = rand()%9;
			if(tabla[con/3][con%3] != 'X' && tabla[con/3][con%3] != 'O') {
				tabla[con/3][con%3] = ia;
				break;
			}
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

void PARTIDA(char jugador, char ia) {
	CLEAR();
	char winer = 'N';
	int f;
	if(ia == 'X') {
		f = rand()%4;
		tabla[(f/2)*2][(f%2)*2] = 'X';
		f = 8;
	}
	else {
		f = 9;
	}
	for(int i = 0; i < f; i++) {
		if(i%2 == 0) {
			CLEAR();
			TURNO_J(jugador);
			winer = WINER(jugador);
		}
		else {
			CLEAR();
			TURNO_IA(ia, jugador);
			winer = WINER(ia);
		}
		if(winer != 'N') {
			break;
		}
	}
	CLEAR();
	TABLERO();
	if(winer == jugador) {
		printf("Ganaste!\n");
	}
	else if(winer == ia) {
		printf("Perdiste...\n");
	}
	else {
		printf("Ha sido un empate\n");
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
		CLEAR();
		printf("_______               _______  _____       _______  ___\n");
		printf("   |      /\\             |    |               |      |\n");
		printf("   |     /__\\    ____    |    |_____  ____    |      |\n");
		printf("   |    /    \\           |    |               |      |\n");
		printf("   |   /      \\          |    |_____          |     _|_\n");
		printf("\n\n\nPresione 'J' para jugar y 'S' para salir: ");
		opc = tolower(getche());
		if(opc == 's') {
			break;
		}
		else if(opc == 'j') {
			do {
				CLEAR();
				printf("Presione 'X' para comenzar, 'O' para que comience");
				printf(" la maquina o 'S' para salir: ");
				switch(tolower(getche())) {
					
				case'x':
					PARTIDA('X','O');
					break;
					
				case'o':
					PARTIDA('O','X');
					break;
					
				case's':
					exit(0);
					break;
					
				default:
					continue;
					break;
				}
			} while(0);
		}
	}
	return 0;
}


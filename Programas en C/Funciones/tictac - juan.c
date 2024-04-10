#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Tjugador(char j[]);

void Tmaquina(char j[]);

void estado(int *w, char j[]);

void pausa();

int main(int argc, char *argv[]) {
	char juego[9]={0};
	int win=0,cont=0;
	juego[4]='X';
	do{
	if(win==0){
	Tjugador(juego);
	estado(&win,juego);}
	if(win==0){Tmaquina(juego);
	estado(&win,juego);}
	cont++;
	if(cont==4){
		win=3;
	}
	} while(win==0);
	switch(win){
	case 1:printf("GANASTE");break;
	case 2:printf("PERDISTE");break;
	case 3:printf("EMPATE");break;
	}
	printf("\n+---+---+---+\n");
	printf("+ %c + %c + %c +\n",juego[0],juego[1],juego[2]);
	printf("+---+---+---+\n");
	printf("+ %c + %c + %c +\n",juego[3],juego[4],juego[5]);
	printf("+---+---+---+\n");
	printf("+ %c + %c + %c +\n",juego[6],juego[7],juego[8]);
	printf("+---+---+---+\n");
	pausa();
	return 0;
}

void Tjugador(char j[]){
	char v[9];
	int opc;
	for(int i=0;i<9;i++){
		if(j[i]==0){
		v[i]='1'+i;
		}
		else{
			v[i]=j[i];
		}
	}
		do{
		printf("\n+---+---+---+\n");
		printf("+ %c + %c + %c +\n",v[0],v[1],v[2]);
		printf("+---+---+---+\n");
		printf("+ %c + %c + %c +\n",v[3],v[4],v[5]);
		printf("+---+---+---+\n");
		printf("+ %c + %c + %c +\n",v[6],v[7],v[8]);
		printf("+---+---+---+\n");
		printf("INGRESE SU JUGADA: ");
		scanf("%i",&opc);
		if(opc>9 || opc<1){
			printf("CASILLA FUERA DE LOS LIMITES\n");
			pausa();
		}
		if(j[opc-1]!=0){
			printf("CASILLA OCUPADA\n");
			pausa();
		}
		
	}while(j[opc-1]!=0 || (opc>9 || opc<1));
	j[opc-1]='O';
}

void Tmaquina(char j[]){
	srand(time(NULL));
	int opc;
	do{
		opc=1+rand()%9;
	} while(j[opc-1]!=0);
	j[opc-1]='X';
}

void estado(int *w, char j[]){
	if(j[0]==j[1]){
		if(j[0]==j[2]){
			if(j[0]=='O'){
				*w=1;
			}
			else{
				if(j[0]=='X'){
					*w=2;
				}
			}
		}
	}
	if(j[3]==j[4]){
		if(j[3]==j[5]){
			if(j[3]=='O'){
				*w=1;
			}
			else{
				if(j[3]=='X'){
					*w=2;
				}
			}
		}
	}
	if(j[6]==j[7]){
		if(j[6]==j[8]){
			if(j[6]=='O'){
				*w=1;
			}
			else{
				if(j[6]=='X'){
					*w=2;
				}
			}
		}
	}
	if(j[0]==j[3]){
		if(j[0]==j[6]){
			if(j[0]=='O'){
				*w=1;
			}
			else{
				if(j[0]=='X'){
					*w=2;
				}
			}
		}
	}
	if(j[1]==j[4]){
		if(j[1]==j[7]){
			if(j[1]=='O'){
				*w=1;
			}
			else{
				if(j[1]=='X'){
					*w=2;
				}
			}
		}
	}
	if(j[2]==j[5]){
		if(j[2]==j[8]){
			if(j[2]=='O'){
				*w=1;
			}
			else{
				if(j[2]=='X'){
					*w=2;
				}
			}
		}
	}
	if(j[0]==j[5]){
		if(j[0]==j[8]){
			if(j[0]=='O'){
				*w=1;
			}
			else{
				if(j[0]=='X'){
					*w=2;
				}
			}
		}
	}
	if(j[2]==j[5]){
		if(j[2]==j[6]){
			if(j[2]=='O'){
				*w=1;
			}
			else{
				if(j[2]=='X'){
				*w=2;
				}
			}
		}
	}
}
	
void pausa(){
	char a;
	fflush(stdin);
	scanf("%c",&a);
}


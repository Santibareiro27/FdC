#include <stdio.h>

int main(int argc, char *argv[]) {
	float notas[5][2][3]; //cant. de estudiantes|parciales|parcial,recu y mejor
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 5; j++) {
			printf("\nNota del parcial n%d del estudiante %d: ",i+1,j+1);
			scanf("%f",&notas[j][i][0]);
			printf("\nNota del recuperatorio n%d del estudiante %d: ",i+1,j+1);
			scanf("%f",&notas[j][i][1]);
			if(notas[j][i][0] > notas[j][i][1]) {
				notas[j][i][2] = notas[j][i][0];
			}
			else {
				notas[j][i][2] = notas[j][i][1];
			}
		}
	}
	for(int i = 0; i < 5; i++) {
		printf("\nEstudiante numero %d:\n",i+1);
		printf("1er parcial: %.2f\n",notas[i][0][2]);
		printf("2do parcial: %.2f\n",notas[i][1][2]);
	}
	return 0;
}


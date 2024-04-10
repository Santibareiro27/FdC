#include <stdio.h>
#include <stdlib.h>

float COE[2][3];

void cramer() {
	float s, y, x;
	s = COE[0][0]*COE[1][1] - COE[1][0]*COE[0][1];
	if(s == 0) {
		printf("\nEl determinante del sistema no puede ser 0");
		exit(1);
	}
	x = (COE[0][2]*COE[1][1] - COE[1][2]*COE[0][1])/s;
	y = (COE[0][0]*COE[1][2] - COE[1][0]*COE[0][2])/s;
	printf("\nx = %f\ny = %f",x,y);
}

int main(int argc, char *argv[]) {
	printf("\nIngrese la primera ecuacion(ax + by = c):\n");
	printf("a = ");
	scanf("%f",&COE[0][0]);
	printf("b = ");
	scanf("%f",&COE[0][1]);
	printf("c = ");
	scanf("%f",&COE[0][2]);
	printf("\nIngrese la segunda ecuacion(ax + by = c):\n");
	printf("a = ");
	scanf("%f",&COE[1][0]);
	printf("b = ");
	scanf("%f",&COE[1][1]);
	printf("c = ");
	scanf("%f",&COE[1][2]);
	cramer();
	return 0;
}


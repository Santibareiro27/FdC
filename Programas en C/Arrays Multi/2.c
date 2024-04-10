#include <stdio.h>
#define D 3
#define H 4

int main(int argc, char *argv[]) {
	int i, j, m30 = 0;
	float max, min, med, tem[D][H];
	max = -100;
	min = 100;
	med = 0;
	for(i = 0; i < D; i++) {
		for(j = 0; j < H; j++) {
			printf("Ingrese la temperatura del dia %d a las %dhs: ",i+1,j);
			scanf("%f",&tem[i][j]);
			if(tem[i][j] > max) {
				max = tem[i][j];
			}
			if(tem[i][j] < min) {
				min = tem[i][j];
			}
			med += tem[i][j];
		}
	}
	med /= D*H;
	printf("\nTemperaturas |med: %f|max: %f|min: %f|\n",med,max,min);
	for(i = 0; i < D; i++) {
		med = 0;
		max = -100;
		min = 100;
		for(j = 0; j < H; j++) {
			if(tem[i][j] > max) {
				max = tem[i][j];
			}
			if(tem[i][j] < min) {
				min = tem[i][j];
			}
			med += tem[i][j];
		}
		med /= H;
		if(med > 30) {
			m30++;
		}
		printf("\nTemp. dia %d |med: %f|max: %f|min: %f|\n",i+1,med,max,min);
	}
	printf("\nCantidad de dias con media mayor de 30: %d\n",m30);
	
	return 0;
}


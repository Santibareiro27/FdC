#include <stdio.h>

int main(int argc, char *argv[]) {
	int rec[10], i, j, rep;
	float kmt = 0, car[10][10] = {
		{0,1,2,3,4,5,6,7,8,9},
		{1,0,2,3,4,5,6,0,8,9},
		{2,2,0,3,4,5,6,7,8,9},
		{3,3,3,0,4,5,6,7,8,9},
		{4,1,2,3,0,5,6,7,8,9},
		{5,1,2,3,4,0,6,7,8,9},
		{6,1,2,3,4,5,0,7,8,9},
		{7,1,2,3,4,5,6,0,8,9},
		{8,1,2,3,4,5,6,7,0,9},
		{9,1,2,3,4,5,6,7,8,0},
	};
	for(i = 0; i < 10; i++) {
		do {
			rep = 0;
			printf("Ciudad %d: ",i+1);
			scanf("%d",&rec[i]);
			if(rec[i] < 0 || rec[i] > 9) {
				rep = 1;
				printf("\nNo hay una ciudad %d\n",rec[i]);
			}
			else {
				for(j = 0; j < i; j++) {
					if(rec[j] == rec[i]) {
						rep = 1;
						printf("\nCiudad repetida\n");
						break;
					}
				}
			}
		} while(rep);
	}
	for(i = 0; i < 9; i++) {
		if(car[rec[i]][rec[i+1]] == 0) {
			printf("\nRecorrido no valido\n");
			break;
		}
		else {
			kmt += car[rec[i]][rec[i+1]];
		}
	}
	if(i == 9) {
		printf("\nRecorrido total: %f\n",kmt);
	}
	return 0;
}


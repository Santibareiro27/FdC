#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	char enf[10][20] = {"AA","AB","AC","AD","AE","AF","AG","AH","AI","AJ"},
	sin[10][20] = {"abc","def","ghi","jab","cde","fgh","ija","bcd","efg","hij"};
	bool sinpa[10],
	tabla[10][10] = {
		{1,0,0,1,0,0,1,0,0,0},
		{1,0,0,1,0,0,0,1,0,0},
		{1,0,0,0,1,0,0,1,0,0},
		{0,1,0,0,1,0,0,1,0,0},
		{0,1,0,0,1,0,0,0,1,0},
		{0,1,0,0,0,1,0,0,1,0},
		{0,0,1,0,0,1,0,0,1,0},
		{0,0,1,0,0,1,0,0,0,1},
		{0,0,1,0,0,0,1,0,0,1},
		{0,0,0,1,0,0,1,0,0,1}
	};
	int ind;
	printf("\nA continuacion seleccione los sintomas que esta sufriendo:\n");
	for(int i = 0; i < 10; i++) {
		printf("\nEsta sufriendo el sintoma %s? (si -> 1 / no -> 0): ",sin[i]);
		scanf("%d",&sinpa[i]);
	}
	for(int i = 0; i < 10; i++) {
		ind = i;
		for(int j = 0; j < 10; j++) {
			if(tabla[i][j] != sinpa[j]) {
				ind = -1;
				break;
			}
		}
		if(ind == i) {
			break;
		}
	}
	
	if(ind == -1) {
		printf("\nNo se pudo emitir un diagnostico confiable");
	}
	else {
		printf("\nUsted padece de %s", enf[ind]);
	}
	return 0;
}


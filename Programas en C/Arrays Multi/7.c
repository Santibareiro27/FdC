#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	char bar[40][20], aux[20], palo[4][11] ={"oros","copas","espadas","bastos"};
	int i, j;
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 10; j++) {
			switch(j) {
			case 0:
				sprintf(bar[(i*10)+j],"as de %s",palo[i]);
				break;
				
			case 7:
				sprintf(bar[(i*10)+j],"sota de %s",palo[i]);
				break;
				
			case 8:
				sprintf(bar[(i*10)+j],"caballo de %s",palo[i]);
				break;
				
			case 9:
				sprintf(bar[(i*10)+j],"rey de %s",palo[i]);
				break;
				
			default:
				sprintf(bar[(i*10)+j],"%d de %s",j+1,palo[i]);
				break;
			}
		}
	}
	printf("\nBaraja:\n");
	for(i = 0; i < 40; i++) {
		printf("%d - %s\n",i+1,bar[i]);
	}
	srand(time(NULL));
	for(i = 0; i < 40; i++) {
		j = rand() % 40;
		sprintf(aux,"%s",bar[i]);
		sprintf(bar[i],"%s",bar[j]);
		sprintf(bar[j],"%s",aux);
	}
	printf("\nBaraja mezclada:\n");
	for(i = 0; i < 40; i++) {
		printf("%d - %s\n",i+1,bar[i]);
	}
	return 0;
}


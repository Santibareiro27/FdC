#include <stdio.h>
#define N 20

int main(int argc, char *argv[]) {
	char cad[N];
	int p = 0, l = 1;
	for(int i = 0; i < N; i++) {
		cad[i] = getchar();
		switch(cad[i]) {
		case '\t':
		case ' ':
			break;
			
		case '\n':
			l++;
			break;
			
		default:
			if(i != 0) {
				switch(cad[i-1]) {
				case '\t':
				case '\n':
				case ' ':
					p++;
					break;
				}
			}
			else
			   p++;
			break;
		}
	}
	printf("\nCantidad de caracteres: %d", N);
	printf("\nCantidad de palabras: %d", p);
	printf("\nCantidad de lineas: %d", l);
	return 0;
}


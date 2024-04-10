#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	char a[10];
	int n, b10 = 0, d, p;
	
	do {
		printf("Ingrese una base: ");
		scanf("%d", &n);
	} while(n < 2 || n > 16);
	
	printf("Ingrese una cadena: ");
	scanf("%s", a);
	
	for(int i = strlen(a)-1; i >= 0; i--) {
		if(isdigit(a[i])) {
			d = a[i]-'0';
		}
		else if(isalpha(a[i])) {
			d = 10 + toupper(a[i])-'A';
		}
		else {
			d = n;
		}
		if(d < 0 || d >= n) {
			b10 = -1;
			printf("No existe %c en el sistema en base %d", a[i], n);
			break;
		}
		else {
			p = 1;
			for(int j = 1; j < strlen(a)-i; j++) {
				p *= n;
			}
			b10 += d*p;
		}
	}
	if(b10 != -1) {
		printf("\n%d",b10);
	}
	
	return 0;
}


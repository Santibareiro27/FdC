#include <stdio.h>
#include <string.h>
#define N 80

int main(int argc, char *argv[]) {
	char a[N], b[N];
	int n = 0;
	printf("ingrese una cadena: ");
	gets(a);
	printf("ingrese otra cadena: ");
	gets(b);
	for(int i = 0;;i++) {
		if(a[i] < b[i]) {
			n = -1;
			break;
		}
		else if(a[i] > b[i]) {
			n = 1;
			break;
		}
		if(a[i] == '\0' || b[i] == '\0')
			break;
	}
	printf("\n%d", n);
	return 0;
}


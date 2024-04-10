#include <stdio.h>
#define N 20

int main(int argc, char *argv[]) {
	int i = 0;
	char cad[N], enc[N];
	gets(cad);
	while(cad[i] != '\0') {
		if(cad[i] != 'z' && cad[i] != 'Z') 
			enc[i] = cad[i] + 1;
		else
			enc[i] = cad[i] - 25;
		i++;
	}
	enc[i] = '\0';
	puts(enc);
	return 0;
}


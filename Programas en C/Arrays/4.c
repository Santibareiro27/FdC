#include <stdio.h>
#include <ctype.h>
#define N 20

int main(int argc, char *argv[]) {
	int i = 0;
	char cad1[N], cad2[N];
	gets(cad1);
	while(cad1[i] != '\0') {
		if(isupper(cad1[i])) 
			cad2[i] = tolower(cad1[i]);
		else
			cad2[i] = cad1[i];
		i++;
	}
	cad2[i] = '\0';
	puts(cad2);
	return 0;
}

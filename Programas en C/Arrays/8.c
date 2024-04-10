#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	int i, j, ban = 1;
	char cad[20];
	gets(cad);
	i = 0;
	j = strlen(cad)-1;
	
	while(i != strlen(cad) && j != -1) {
		if(!isalnum(cad[i])) {
			i++;
			continue;
		}
		if(!isalnum(cad[j])) {
			j--;
			continue;
		}
		if(cad[i] != cad[j]) {
			ban = 0;
		}
		i++;
		j--;
	}
	
	if(ban == 1) {
		printf("\nLa frase \"%s\" es un palindromo", cad);
	}
	else {
		printf("\nLa frase \"%s\" no es un palindromo", cad);
	}
	
	printf("\n%s", strrev(cad));
	
	return 0;
}

#include <stdio.h>
#include <ctype.h>
#define N 30

int main(int argc, char *argv[]) {
	char cad[N], let[N] = "\0";
	gets(cad);
	int ban, c = 0;
	for(int i = 0; cad[i] != '\0'; i++) {
		ban = 1;
		if(isalpha(cad[i])) {
			for(int j = c; j >= 0; j--) {
				if(cad[i] == let[j])
					ban = 0;
			}
			if(ban) {
				let[c] = cad[i];
				let[c+1] = '\0';
				c++;
			}
		}
		else
			ban = 0;
	}
	puts(let);
	return 0;
}


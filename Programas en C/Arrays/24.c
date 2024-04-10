#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	char text[1000];
	int cont[26] = {0};
	gets(text);
	for(int i = 0; text[i] != '\0'; i++) {
		if(isalpha(text[i])) {
			if(isupper(text[i])) {
				cont[text[i]-'A']++;
			}
			else {
				cont[text[i]-'a']++;
			}
		}
	}
	for(int i = 0; i < 26; i++) {
		printf("\nRepeticiones de la letra %c: %d", 'A'+i, cont[i]);
	}
	return 0;
}

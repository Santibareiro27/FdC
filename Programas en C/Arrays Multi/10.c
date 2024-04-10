#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	char text[40], morse[200], tabla[36][6] = {".-","-...","-.-.","-..",".",
	"..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",
	".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----",
	"..---","...--","....-",".....","-....","--...","---..","----."};
	int i;
	gets(text);
	morse[0] = '\0';
	for(i = 0; text[i] != '\0'; i++) {
		if(isalnum(text[i])) {
			if(isalpha(text[i])) {
				strcat(morse,tabla[toupper(text[i])-'A']);
			}
			else {
				strcat(morse,tabla[text[i]-'0']);
			}
			if(isalnum(text[i+1]) || text[i+1] == '.') {
				strcat(morse," ");
			}
		}
		else if(text[i] == '.') {
			strcat(morse,"... - --- .--.");
			if(isalnum(text[i+1]) || text[i+1] == '.') {
				strcat(morse," ");
			}
		}
		else if(text[i] == ' ') {
			strcat(morse,"   ");
		}
	}
	puts(morse);
	return 0;
}


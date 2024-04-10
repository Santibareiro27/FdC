#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, p;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		p = 1;
		for(int j = 2; j < i; j++) {
			if(i%j == 0) {
				p = 0;
				break;
			}
		}
		if(p == 1)
			printf("%d\n",i);
	}
	return 0;
}


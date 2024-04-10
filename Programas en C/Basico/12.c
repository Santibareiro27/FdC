#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, max, min;
	for(int i = 0; i < 5; i++) {
		scanf("%d",&n);
		if(i != 0) {
			if(n > max)
				max = n;
			if(n < min)
				min = n;
		}
		else {
			max = n;
			min = n;
		}
	}
	printf("\nEl numero mas chico fue %d y el mas grande %d", min, max);
	return 0;
}


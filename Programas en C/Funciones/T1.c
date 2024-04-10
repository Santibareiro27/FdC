#include <stdio.h>
#define N 5

int suma(int v[]) {
	int s = 0;
	for(int i = 0; i < N; i++) {
		s += v[i];
	}
	return s;
}

int main(int argc, char *argv[]) {
	int vec[N];
	for(int i = 0; i < N; i++) {
		scanf("%d",&vec[i]);
	}
	printf("\nLa suma de sus elementos es: %d",suma(vec));
	return 0;
}


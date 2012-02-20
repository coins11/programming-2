#include <stdio.h>

int main() {
	int n, i, j, k;

	scanf("%d", &n);

	for (i=1; i<=n; i++) {
		k = 0;
		for (j=0; j<(n*2-1); j++) {
			if ( j >= ((n*2-1) - (i*2-1))/2 && k < (i*2-1) ) { 
				printf("*");
				k++;
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}

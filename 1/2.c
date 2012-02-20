#include <stdio.h>

int main() {
	int n, i, j, k;

	scanf("%d", &n);

	i = 1;
	while (i<=n) {
		k = 0;
		j = 0;
		while (j<(n*2-1)) {
			if ( j >= ((n*2-1) - (i*2-1))/2 && k < (i*2-1) ) { 
				printf("*");
				k++;
			} else {
				printf(" ");
			}
			j++;
		}
		printf("\n");
		i++;
	}

	return 0;
}

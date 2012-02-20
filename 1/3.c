#include <stdio.h>

int main() {
	int n, q, r,
		p = 10;

	scanf("%d", &n);

	while (n > 0) {
		r = n % p;
		n /= p;
		
		printf("%d", r);
	}

	puts("");

	return 0;
}

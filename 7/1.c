#include <stdio.h>

int n;
int route[100][100];

int distance (int i, int j, int path[], int count);

int main(void)
{
	int i, j;
	int path[100];

	for (i = 0; i < 100; i++) {
		path[i] = -1;
	}

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &route[i][j]);
		}
	}

	distance(0, n-1, path, 0);

	printf("0, ");
	for (i = 0; path[i] > 0; i++) {
		
		printf("%d, ", path[i]);
		if (path[i] == n-1) {
			break;
		}
	}

	puts("");

	return 0;
}

int distance (int i, int j, int path[], int count)
{
	int d, k, min;

	min = 1000;

	if (i == j) {
		return 0;
	}

	for (k = 0; k < n; k++) {
		if (route[i][k] == 0) {
			continue;
		} else {
			d = route[i][k] + distance(k, j, path, count+1);
		}

		if (d < min) {
			min = d;
			path[count] = k;
		}
	}

	return min;
}

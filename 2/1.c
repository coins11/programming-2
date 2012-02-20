#include <stdio.h>

#define N 100

int main(void)
{
	double a[N][N], b[N][N], kai[N], ans[N], tmp;
	int i, j, k, n;

	scanf("%d", &n);

	for (j = 0; j < n; j++) {
		for (i = 0; i < n; i++) {
			a[j][i] = 0.0;
			b[j][i] = 0.0;
		}
		kai[i] = 0.0;
	}

	for (i = 0; i < n; i++)
		b[i][i] = 1.0;

	for (j = 0; j < n; j++) {
		for (i = 0; i < n; i++) {
			scanf("%lf", &a[j][i]);
		}
		scanf("%lf", &kai[j]);
	}

	for (k = 0; k < n; k++) {
		tmp = a[k][k];
		for (i = 0; i < n; i++) {
			a[k][i] /= tmp;
			b[k][i] /= tmp;
		}
		for (j = 0; j < n; j++) {
			if (j != k) {
				tmp = a[j][k];
				for (i = 0; i < n; i++) {
					a[j][i] -= a[k][i] * tmp;
					b[j][i] -= b[k][i] * tmp;
				}
			}
		}
	}

	for (i=0; i<n; i++) {
		tmp = 0.0;
		for (j=0; j<n; j++) {
			tmp += kai[j] * b[i][j];
		}
		printf("%lf\n", tmp);
	}

	return 0;
}

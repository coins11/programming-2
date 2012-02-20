#include <stdio.h>
#define N 100

int main(void) {
   double A[N][N+1];
   int i, j, k, n;

   scanf("%d", &n);
   // input matrix
   for (i = 0; i < n; ++i) {
      for (j = 0; j <= n; ++j) {
        scanf("%lf", &A[i][j]);
      }
   }
   // calculate by Gauss-Jordan
   for (k = 0; k < n; ++k) {
      double tmp = A[k][k];
      for (i = 0; i <= n; ++i) A[k][i] /= tmp;
      for (i = 0; i < n; ++i) {
         if (i == k) continue;
         tmp = A[i][k];
         for (j = 0; j <= n; ++j) {
            A[i][j] -= A[k][j] * tmp;
         }
      }
   }
   // print result vector
   for(i = 0; i < n; ++i) printf("%f\n", A[i][n]);
   return 0;
}


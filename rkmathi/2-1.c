#include <stdio.h>
int main(void)
{
    int n, i, j;
    printf("Input number (>=1): ");
    scanf ("%d", &n);
    printf("n = %d\n", n);
    for (i=1; i<=n; i++) {
        for (j=1; j<=n-i; j++) {
            printf(" ");
        }
        for (j=1; j<=2*i-1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

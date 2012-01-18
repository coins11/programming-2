#include <stdio.h>

#define N 100

int main()
{
    double a[N][N], b[N][N], result[N], result2[N], tmp;
    int i, j, k, n;

    printf("input matrix size:\n");
    scanf("%d", &n);

    for (j = 0; i < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            a[j][i] = 0.0;
            b[j][i] = 0.0;
        }
    }

    for (i = 0; i < n; i++)
        b[i][i] = 1.0;

    for (i = 0; i < n; i++)
        result2[i] = 0.0;

    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%lf", &a[j][i]);
        }
        scanf("%lf", &result[j]);
    }

    printf("matrix: \n");
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
            printf("%f\t", a[j][i]);
        printf("\n");
    }

    // inverse matrix
    for (k = 0; k < n; k++)
    {
        tmp = a[k][k];
        for (i = 0; i < n; i++)
        {
            a[k][i] /= tmp;
            b[k][i] /= tmp;
        }
        for (j = 0; j < n; j++)
        {
            if (j != k)
            {
                tmp = a[j][k];
                for (i = 0; i < n; i++)
                {
                    a[j][i] -= a[k][i] * tmp;
                    b[j][i] -= b[k][i] * tmp;
                }
            }
        }
    }

    // A(inv) * result
    for (j = 0; j < n; j++)
    {
        tmp = 0;
        for (i = 0; i < n; i++)
        {
            tmp += b[j][i] * result[i];
        }
        result2[j] = tmp;
    }

    printf("after calculation matrix: \n");
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            printf("%f\t", b[j][i]);
        }
        printf("\n");
    }

    printf("result: ");
    for (i = 0; i < n; i++)
    {
        printf(" %f\t", result2[i]);
    }
    printf("\n");

    return 0;
}


#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    size_t n, i;
    double **matrix;
    scanf("%d", &n);
    matrix = malloc(sizeof(double *) * n);
    if(!matrix){
        return 0;
    }
    i = 0;
    while(i != n){
        matrix[i] = malloc(sizeof(double) * (n+1));
        if(!matrix[i]){
            while(i){
                i--;
                free(matrix[i]);
            }
            free(matrix);
            return 0;
        }
        i++;
    }
    i = 0;
    while(i != n){
        size_t j = 0;
        while(j != n+1){
            scanf("%lf", &(matrix[i][j]));
            j++;
        }
        i++;
    }
    i = 0;
    while(i != n){
        size_t j = i+1;
        while(j != n){
            double ratio = matrix[j][i] / matrix[i][i];
            size_t k = i+1;
            matrix[j][i] = 0;
            while(k != n+1){
                matrix[j][k] -= matrix[i][k] * ratio;
                k++;
            }
            j++;
        }
        i++;
    }
    while(i){
        size_t j = i-1;
        i--;
        while(j){
            j--;
            matrix[j][n] -= matrix[i][n] * (matrix[j][i] / matrix[i][i]);
            matrix[j][i] = 0;
        }
    }
    i = 0;
    while(i != n){
        size_t j = 0;
        while(j != n+1){
            printf("%f ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    i = 0;
    while(i != n){
        printf("%f\n", matrix[i][n] / matrix[i][i]);
        i++;
    }
    return 0;
}

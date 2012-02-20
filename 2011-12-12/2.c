#include<stdio.h>

int main(void)
{
    int n, digit = 0;
    scanf("%d", &n);
    while(n){
        n /= 10;
        digit++;
    }
    printf("%d\n", digit);
    return 0;
}

#include <stdio.h>

int main()
{
    int n, tmp;
    int digit;

    printf("input number: ");
    scanf("%d", &n);
    
    tmp = n;
    digit = 0;

    while(tmp > 0)
    {
        printf("%d", tmp % 10);
        tmp /= 10;
    }

    printf("\n");

    return 0;
}

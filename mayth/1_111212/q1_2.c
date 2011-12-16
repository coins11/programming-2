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
        tmp /= 10;
        digit++;
    }

    printf("%d is the %d-digit number\n", n, digit);

    return 0;
}

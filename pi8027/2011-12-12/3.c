#include<stdio.h>

int main(void)
{
    int n, digit = 0;
    scanf("%d", &n);
    while(n){
        putc('0'+n%10, stdout);
        n /= 10;
        digit++;
    }
    putc('\n', stdout);
    return 0;
}

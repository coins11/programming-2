#include<stdio.h>

int main(void)
{
    int n, i = 0;
    scanf("%d", &n);
    while(i != n){
        int j = 0;
        while(j != n*2-1){
            putc(n <= i+j+1 && j-i < n ? '*' : ' ', stdout);
            j++;
        }
        putc('\n', stdout);
        i++;
    }
    return 0;
}

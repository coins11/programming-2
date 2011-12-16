#include  <stdio.h>
int main(void)
{
    int n, i, j, tmp, digit, ans[100];
    char str[100];
    printf("Input number: ");
    scanf("%d", &n);
    tmp = n;
    digit = 0;
    sprintf(str, "%d", n);
    while (tmp > 0) {
        tmp /= 10;
        ++digit;
    }
    for (i=1; i<=digit; i++) {
        printf("%c", str[digit-i]);
    }
    printf("\n");
    return 0;
}

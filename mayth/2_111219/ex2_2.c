#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int i, j;

    printf("input string: ");
    scanf("%s", str1);

    i = 0;
    j = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] < '0' || str1[i] > '9')
        {
            str2[j] = str1[i];
            j++;
        }
        i++;
    }
    str2[j] = '\0';

    printf("output string = %s\n", str2);

    return 0;
}

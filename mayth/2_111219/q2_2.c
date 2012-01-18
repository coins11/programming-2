#include <stdio.h>

int main()
{
    char str1[100], str2[100], result[100];
    int i, j, k, contains;

    printf("input string: ");
    scanf("%s", str1);
    printf("input string: ");
    scanf("%s", str2);

    i = 0;
    k = 0;
    while (str1[i] != '\0')
    {
        j = 0;
        contains = 0;
        while (str2[j] != '\0')
            if (str1[i] == str2[j++])
                contains = 1;
        if (!contains)
            result[k++] = str1[i];
        i++;
    }
    result[k] = '\0';

    printf("output string = %s\n", result);

    return 0;
}

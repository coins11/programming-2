#include <stdio.h>

#define MAX_INPUT 100

int main()
{
    char input[MAX_INPUT];
    int i, size;

    printf("input string: ");
    scanf("%s", input);

    // get input size
    while(input[i++] != '\0')
        size++;

    for(i = 0; i < size; i++)
    {
        if (input[i] != input[size - 1 - i])
        {
            printf("false\n");
            return 0;
        }
    }

    printf("true\n");
    return 0;
}

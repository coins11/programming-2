#include <stdio.h>

int main()
{
    int i, j;
    int height, width;

    printf("width = ");
    scanf("%d", &width);
    printf("height = ");
    scanf("%d", &height);

    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}


#include <stdio.h>

int main()
{
    int i, j;
    int height, require;

    printf("height = ");
    scanf("%d", &height);

    int base_width = 2 + (height - 1) * 2;

    for(i = 0, require = 1; i < height; i++, require += 2)
    {
        int skip = (base_width - require) / 2;
        for (j = 0; j < skip; j++)
            printf(" ");
        for (j = 0; j < require; j++)
            printf("*");

        printf("\n");
    }

        return 0;
}


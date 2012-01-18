#include <stdio.h>

int main(int argc, char *argv[])
{
    int count;
    FILE *fp;

    if (argc != 2)
    {
        printf("missing file argument.\n");
        return 1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("can't open %s\n", argv[1]);
        return 1;
    }

    count = 0;
    while (fgetc(fp) != EOF)
        count++;

    printf("%d chars\n", count);
    fclose(fp);

    return 0;
}

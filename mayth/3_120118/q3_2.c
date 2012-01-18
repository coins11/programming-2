#include <stdio.h>

int main(int argc, char *argv[])
{
    int ch;
    FILE *sfp, *dfp;

    if (argc != 3)
    {
        printf("missing file argument.\n");
        return 1;
    }

    if ((sfp = fopen(argv[1], "r")) == NULL)
    {
        printf("can't open %s", argv[1]);
        return 1;
    }

    if ((dfp = fopen(argv[2], "w")) == NULL)
    {
        printf("can't open %s", argv[2]);
        fclose(sfp);
        return 1;
    }

    while ((ch = fgetc(sfp)) != EOF)
        if ('a' <= ch && ch <= 'z')
            fputc(ch - 0x20, dfp);
        else
            fputc(ch, dfp);

    fclose(dfp);
    fclose(sfp);

    return 0;
}

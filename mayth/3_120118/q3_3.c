#include <stdio.h>
#include <limits.h>

#define MAX_ITEM 100
#define MAX_NAME_LENGTH 256

int main(int argc, char *argv[])
{
    int i, j, count;
    int min_score, min_score_idx;
    char name[MAX_ITEM][MAX_NAME_LENGTH];
    int score[MAX_ITEM];
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

    i = 0;
    while(fscanf(fp, "%s %d", name[i], &score[i]) != EOF)
        i++;
    count = i;

    fclose(fp);

    printf("File contains %d items.\n", count);

    // show data sort by score
    printf("Name\tScore\n");
    for(j = 0; j < count; j++)
    {
        min_score = INT_MAX;
        min_score_idx = 0;
        for(i = 0; i < count; i++)
        {
            if (0 <= score[i] && score[i] < min_score)
            {
                min_score = score[i];
                min_score_idx = i;
            }
        }
        printf("%s\t%d\n", name[min_score_idx], score[min_score_idx]);
        score[min_score_idx] = -1;
    }

    return 0;
}

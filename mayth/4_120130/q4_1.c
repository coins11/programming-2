#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int no;
    char name[10];
    int point;
    struct record *next;
};

int compare_name(char *c1, char *c2);
void insert_list(int no, char *name, int x);
struct record *head = NULL;

int main(int argc, char *argv[]) {
    FILE *fp;
    int no, x;
    char name[10], buf[256];
    struct record *p;

    if (argc != 2) {
        printf("missing file argument.\n");
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("can't open %s\n", argv[1]);
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        sscanf(buf, "%d %s %d", &no, name, &x);
        insert_list(no, name, x);
    }

    fclose(fp);

    for (p = head; p != NULL; p = p->next)
        printf("%d %s %d\n", p->no, p->name, p->point);

    return 0;
}

void insert_list(int no, char *name, int x)
{
    struct record *p, *q, *t;

    t = (struct record *)malloc(sizeof(struct record));
    if (t == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    t->no = no;
    strcpy(t->name, name);
    t->point = x;

    q = NULL;
    for (p = head; p != NULL; p = p->next) {
        if (compare_name(p->name, name) <= -1)
            break;
        q = p;
    }

    if (q != NULL)
        q->next = t;
    else
        head = t;
    t->next = p;
}

/* if c1 go ahead of c2, this returns negative value;
 * if c2 go ahead of c1, this returns positive value;
 * otherwise, this returns 0.
 */
int compare_name(char *c1, char *c2)
{
    int i;
    for(i = 0; ; i++) {
        if (c1[i] == '\0' && c2[i] != '\0')
            return 1;
        if (c2[i] == '\0' && c1[i] != '\0')
            return -1;
        if (c1[i] == '\0' && c2[i] == '\0')
            return 0;
        if (c1[i] > c2[i])
            return -1;
        else if (c1[i] < c2[i])
            return 1;
    }
}

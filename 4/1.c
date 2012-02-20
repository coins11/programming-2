#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
	int no;
	char name[10];
	int point;
	struct record *next;
};

void insert_list(int no, char *name, int x);

struct record *head = NULL;

int main(int argc, char *argv[])
{
	FILE *fp;
	int no, x;
	char name[10], buf[256];
	struct record *p;

	if (argc != 2) {
		printf("missing file argument\n");
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

	for (p = head; p != NULL; p = p->next) {
		printf("%d %s %d\n", p->no, p->name, p->point);
	}

	return 0;
}

void insert_list(int no, char *name, int x)
{
	struct record *p, *q, *t;

	t = (struct record *) malloc(sizeof(struct record));
	if (t == NULL) {
		printf("Out of memory\n");
		exit(1);
	}

	t->no = no;
	strcpy(t->name, name);
	t->point = x;

	q = NULL;
	for (p = head; p != NULL; p = p->next) {
		if (strcmp(p->name, name) > 0) {
			break;
		}
		q = p;
	}

	if (q != NULL) {
		q->next = t;
	} else {
		head = t;
	}

	t->next = p;
}


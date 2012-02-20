#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct record {
	char word[20];
	int count;
	struct record *next;
};

int read_word(FILE *fp, char *word);
void add_word(char *word);

struct record *head = NULL;

int main(int argc, char *argv[])
{
	FILE *fp;
	char word[20];
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

	while (read_word(fp, word)) {
		add_word(word);
	}

	fclose(fp);

	for (p = head; p != NULL; p = p->next)
		printf("%s %d\n", p->word, p->count);

	return 0;
}

int read_word(FILE *fp, char *word) {
	int i = 0;
	char c;
	
	while ( (c = fgetc(fp)) != EOF ) {
		if ( isalnum(c) || c == '-' || c == '\'' ) {
			word[i] = c;
			i++;
		} else if (i == 0) {
			continue;
		} else {
			word[i] = '\0';
			return 1;
		}
	}

	return 0;
}

void add_word (char *word) {
	struct record *p, *q, *t;

	for (p = head; p != NULL; p = p->next) {
		if (strcmp(p->word, word) == 0) {
			p->count++;
			break;
		}
	}

	if (p == NULL) {
		t = (struct record *) malloc(sizeof(struct record));

		if (t == NULL) {
			printf("Out of memory\n");
			exit(1);
		}

		t->count = 1;
		strcpy(t->word, word);
	
		q = NULL;
		for (p = head; p != NULL; p = p->next) {
			if (strcmp(p->word, word) > 0) {
				break;
			}
			q = p;
		}

		if (q != NULL) { 
			t->next = p;			
			q->next = t;
		} else {
			head = t;
			t->next = p;
		}
	}
}


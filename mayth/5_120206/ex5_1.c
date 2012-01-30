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
    printf("%s\t\t%d\n", p->word, p->count);

  return 0;
}

int read_word(FILE *fp, char *word)
{
  return fscanf(fp, " %[a-zA-Z0-9'-]", word) != EOF;
}

void add_word(char *word)
{
  struct record *p = NULL,  *q = NULL, *new = NULL;
  for (p = head; p != NULL; p = p->next)
  {
    if (strcmp(word, p->word) == 0)
    {
      p->count++;
      break;
    }
  }
  if (p == NULL)
  {
    new = (struct record *)malloc(sizeof(struct record));
    if (new == NULL)
    {
      printf("out of memory\n");
      exit(1);
    }
    strcpy(new->word, word);
    new->count = 1;
    for (p = head; p != NULL; p = p->next)
    {
      // p->word, word, hoge
      if (strcmp(word, p->word) < 0)
        break;
      q = p;
    }

    if (q != NULL)
      q->next = new;
    else
      head = new;

    new->next = p;
  }
}  


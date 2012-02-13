#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 20

struct record {
  char word[WORD_LENGTH];
  int count;
  struct record *next;
};

int read_word(FILE *fp, char *word);
void add_word(char *word);
int compare_by_freq(const void *s1, const void *s2);

struct record *head = NULL;

int main(int argc, char *argv[])
{
  FILE *fp;
  char word[WORD_LENGTH];
  struct record *p;
  int list_size = 0;
  struct record *sorted = NULL;
  int i = 0;

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
    list_size++;

  sorted = (struct record*)malloc(sizeof(struct record) * list_size);
  if (sorted == NULL)
  {
    printf("couldn't allocate memory for sorted list.\n");
    return 1;
  }

  for (p = head; p != NULL; p = p->next)
    sorted[i++] = *p;

  qsort(sorted, list_size, sizeof(struct record), compare_by_freq);

  for (i = 0; i < list_size; i++)
    printf("%s\t%d\n", sorted[i].word, sorted[i].count);

  return 0;
}

int read_word(FILE *fp, char *word)
{
  int c;
  int cur = 0;
  while(1)
  {
    c = fgetc(fp);
    if (isalnum(c) || c == '-' || c == '\'')
    {
      word[cur++] = (char)c;
    }
    else
    {
      if (cur == 0 && c == EOF)
        return 0;
      word[cur] = '\0';
      return 1;
    }
  }
}

void add_word(char *word)
{
  struct record *p = NULL,  *q = NULL, *new = NULL;
  
  if (word[0] == '\0') return;

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

    new->next = p;

    if (q != NULL)
      q->next = new;
    else
      head = new;
  }
}  

int compare_by_freq(const void *s1, const void *s2)
{
  return ((struct record*)s2)->count - ((struct record*)s1)->count;
}


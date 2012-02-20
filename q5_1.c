#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct record {
  char word[20];
  int count;
  struct record *next;
};
struct record head = {NULL, 0, NULL};

int read_word(FILE *fp, char *word) {
   char *p = word;
   char ch;
   // skip whitespaces
   while(!isalnum(ch = fgetc(fp))) {
      if(ch == EOF) return 0;
   }
   // read word
   while(isalnum(ch) || ch == '-' || ch == '\'') {
      *(p++) = tolower(ch);
      if((ch = fgetc(fp)) == EOF) break;
   }
   // delete end of apostrophe
   if(*(p-1) == '\'') *(p-1) = '\0';
   else *p = '\0';
   return 1;
}

void add_word(const char *word) {
   struct record *p, *q;
   for(q = &head, p = head.next; p != NULL; p = p->next) {
      int cmp = strcmp(p->word, word);
      if(cmp == 0) {
         p->count++;
         return;
      } else if(cmp > 0) break;
      q = p;
   }
   struct record *t;
   // create new record when it doesn't exist
   if((t = (struct record*)malloc(sizeof(struct record))) == NULL) {
      fprintf(stderr, "out of memory!\n");
      exit(EXIT_FAILURE);
   }
   strcpy(t->word, word);
   t->count = 1;
   q->next = t;
   t->next = p;
}

int main(int argc, char *argv[]) {
  FILE *fp;
  char word[20];

  if (argc != 2) {
    printf("missing file argument\n");
    return 1;
  }

  if((fp = fopen(argv[1], "r")) == NULL) {
    printf("can't open %s\n", argv[1]);
    return 1;
  }

  // read sequentially
  while (read_word(fp, word)) {
     add_word(word);
  }
  for(struct record *p = head.next; p != NULL; p = p->next) {
     printf("%-18s %d\n", p->word, p->count);
  }
  fclose(fp);
  return 0;
}


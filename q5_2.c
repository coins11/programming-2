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

int  add_word(const char *word) {
   struct record *p, *t;
   for(p = head.next; p != NULL; p = p->next) {
      if(!strcmp(p->word, word)) {
         p->count++;
         return 0;
      }
   }
   // create new record when it doesn't exist
   if((t = (struct record*)malloc(sizeof(struct record))) == NULL) {
      fprintf(stderr, "out of memory!\n");
      exit(EXIT_FAILURE);
   }
   strcpy(t->word, word);
   t->count = 1;
   t->next = head.next;
   head.next = t;
   return 1;
}

int cmp_count(const void *a, const void *b) {
   struct record *ta = *(struct record**)a;
   struct record *tb = *(struct record**)b;
   int ret = tb->count - ta->count;
   if(ret) return ret;
   else return strcmp(ta->word, tb->word);
}

int main(int argc, char *argv[]) {
  FILE *fp;
  if (argc != 2) {
    printf("missing file argument\n");
    return 1;
  }
  if((fp = fopen(argv[1], "r")) == NULL) {
    printf("can't open %s\n", argv[1]);
    return 1;
  }
  // read sequentially
  char word[20];
  int num_records = 0;
  while (read_word(fp, word)) {
     if(add_word(word)) ++num_records;
  }
  // map linked-list to vector
  struct record **words;
  if((words = (struct record **)malloc(sizeof(struct record*) * num_records)) == NULL) {
     fprintf(stderr, "out of memory\n");
     exit(EXIT_FAILURE);
  }
  struct record **dst, *src; = words;
  for(dst = words, src = head.next; src != NULL; src = src->next) {
     *(dst++) = src;
  }
  // sort and print
  qsort(words, num_records, sizeof(struct record*), cmp_count);
  for(int i = 0; i < num_records; ++i) {
     printf("%-18s%d\n", words[i]->word, words[i]->count);
  }
  free(words);
  fclose(fp);
  return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct record {
   int no;
   char name[10];
   int point;
   struct record *next;
};
struct record head = {0, '\0', 0, NULL};
void insert_list(int no, char *name, int point) {
   struct record *t;
   if((t = (struct record*)malloc(sizeof(struct record))) == NULL) {
      fprintf(stderr, "Out of memory\n");
      exit(EXIT_FAILURE);
   }
   /* compose node */
   t->no    = no;
   t->point = point;
   strcpy(t->name, name);
   /* search and insert */
   struct record *cur  = head.next;
   struct record *prev = &head;
   while(cur && cur->point > point) {
      prev = cur;
      cur  = cur->next;
   }
   t->next = cur;
   prev->next = t;
}
int main(int argc, char *argv[]) {
   FILE *fp;
   char buf[256];
   if(argc != 2) {
      puts("missing file argument");
      return 1;
   }
   if((fp = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "failed to open %s\n", argv[1]);
      return 1;
   }
   while(fgets(buf, sizeof(buf), fp)) {
      int no, point;
      char name[10];
      sscanf(buf, "%d %s %d", &no, name, &point);
      if(point >= 60) insert_list(no, name, point);
   }
   fclose(fp);
   for(struct record *p = head.next; p != NULL; p = p->next) {
      printf("%2d %-10s %d\n", p->no, p->name, p->point);
   }
   return 0;
}



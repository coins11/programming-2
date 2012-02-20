#include <stdio.h>
#include <stdlib.h>
#define MAX 500
struct student {
   char name[64];
   int score;
};

int comp(const void *a, const void *b) {
   struct student *ta = (struct student*)a;
   struct student *tb = (struct student*)b;
   return ta->score - tb->score;
}

int main(int argc, char *argv[]) {
   FILE *fp;
   int idx; // number of students
   struct student students[MAX];
   if(argc != 2) {
      fprintf(stderr, "missing argument: source file\n");
      return 1;
   }
   if((fp = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "failed to open %s\n", argv[1]);
      return 1;
   }
   for(idx = 0; idx < MAX; ++idx) {
      fscanf(fp, "%s", students[idx].name);
      fscanf(fp, "%d", &students[idx].score);
      if(feof(fp)) break;
   }
   qsort(students, idx, sizeof(struct student), comp);

   for(int i = 0; i < idx; ++i) {
      printf("%-10s %d\n", students[i].name, students[i].score);
   }
   return 0;
}


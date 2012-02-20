#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
   int count, ch;
   FILE *fp;
   if(argc != 2) {
      fprintf(stderr, "missing argument: specify the file name\n");
      return 1;
   }
   if((fp = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "failed to open %s\n", argv[1]);
      return 1;
   }
   count = 0;
   while((ch = fgetc(fp))!= EOF) {
      if(isprint(ch)) count++;
   }
   printf("%d characters\n", count);
   fclose(fp);
   return 0;
}


#include <stdio.h>

int main(int argc, char *argv[]) {
   if(argc != 2) return 1;
   int level = atoi(argv[1]);
   for(int i = 0; i < level; ++i) {
      for(int j = 0; j < level-i; ++j) putchar(' ');
      for(int j = 0; j < i*2+1; ++j) putchar('*');
      putchar('\n');
   }
   return 0;
}


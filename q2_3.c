#include <stdio.h>

int main(int argc, char *argv[]) {
   char *p, *q;
   if(argc != 2) return 1;
   p = &argv[1][0];
   q = &argv[1][strlen(argv[1])-1];
   for(; p < q; ++p, --q) {
      if(*p == *q) continue;
      puts("not palindrome");
      return 0;
   }
   puts("palindrome");
   return 0;
}


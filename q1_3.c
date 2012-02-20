#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if(argc != 2) return 1;
   unsigned num = atoi(argv[1]);
   while(num > 0) {
      putchar('0' + num % 10);
      num /= 10;
   }
   putchar('\n');
   return 0;
}


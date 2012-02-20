#include <stdio.h>

int main(void) {
   int n, tmp;
   int digit;
   printf("input number ");
   scanf("%d", &n);
   tmp = n;
   digit = 0;

   while(1) {
      tmp /= 10;
      digit++;
      if(tmp == 0) break;
   } 

   printf("%d is the %d-digit number\n", n, digit);
   return 0;
}

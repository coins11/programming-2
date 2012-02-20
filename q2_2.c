#include <stdio.h>
#include <string.h>

int main(void) {
   char str1[256], str2[256];
   gets(str1);
   gets(str2);
   for(char *p = str1; *p != '\0'; ++p) {
      if(strchr(str2, *p)) putchar(*p);
   }
   return 0;
}


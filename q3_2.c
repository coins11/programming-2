#include <stdio.h> 
#include <ctype.h> 
 
int main(int argc, char *argv[]) { 
   int ch; 
   FILE *sfp, *dfp; // source, destination 
   if(argc != 3) { 
      fprintf(stderr, "missing arguments: src dst\n"); 
      return 1;  
   }   
   if((sfp = fopen(argv[1], "r")) == NULL) { 
      fprintf(stderr, "failed to open %s\n", argv[1]); 
      return 1;  
   }   
   if((dfp = fopen(argv[2], "w")) == NULL) { 
      fprintf(stderr, "failed to open %s\n", argv[2]); 
      fclose(sfp); 
      return 1;  
   }   
   while((ch = fgetc(sfp)) != EOF) { 
      if(islower(ch)) ch = toupper(ch); 
      fputc(ch, dfp); 
   }   
 
   return 0;  
}


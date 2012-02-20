
#include<stdio.h>

int main(int argc, char *argv[])
{
    if(3 <= argc){
        FILE *input = fopen(argv[1], "r");
        FILE *output = fopen(argv[2], "w");
        if(!input || !output){
            if(input) fclose(input);
            if(output) fclose(output);
            return -1;
        }
        while(1){
            int c;
            if(feof(input)) break;
            c = fgetc(input);
            if(ferror(input)) break;
            fputc(c, output);
            if(ferror(output)) break;
        }
        fclose(input);
        fclose(output);
    }
    return 0;
}


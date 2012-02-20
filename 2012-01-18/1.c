
#include<stdio.h>

int main(int argc, char *argv[])
{
    if(2 <= argc){
        int i = 0;
        FILE *input = fopen(argv[1], "r");
        if(!input){
            return -1;
        }
        while(1){
            int c;
            if(feof(input)) break;
            c = fgetc(input);
            if(c == EOF) break;
            i++;
        }
        printf("%d\n", i);
        fclose(input);
    }
    return 0;
}


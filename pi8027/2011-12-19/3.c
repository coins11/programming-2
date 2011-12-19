#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *fgetline(FILE *input)
{
    char *buf = NULL;
    size_t iter = 0;
    while(1){
        char *temp = realloc(buf, (iter + 1) * 32 + 1);
        if(!temp){
            free(buf);
            return NULL;
        }
        buf = temp;
        fgets(&buf[iter * 32], 32 + 1, input);
        if(ferror(stdin)){
            free(buf);
            return NULL;
        }
        {
            size_t len = strlen(&buf[iter * 32]);
            if(buf[iter * 32 + len - 1] == '\n'){
                buf[iter * 32 + len - 1] = '\0';
                return buf;
            }
            if(len != 32){
                return buf;
            }
        }
        iter++;
    }
}

int kaibun(char *str)
{
    size_t i = 0, j = 0;
    while(str[j]) j++;
    while(i < j){
        j--;
        if(str[i] != str[j]) return 0;
        i++;
    }
    return 1;
}

int main(void)
{
    char *str;
    str = fgetline(stdin);
    if(!str) return 0;
    fputs(kaibun(str) ? "T\n" : "F\n" , stdout);
    return 0;
}

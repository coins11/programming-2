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

int elem(char c, char *str)
{
    size_t i = 0;
    while(str[i]){
        if(str[i] == c) return 1;
        i++;
    }
    return 0;
}

int main(void)
{
    char *s1, *s2;
    size_t i = 0;
    s1 = fgetline(stdin);
    s2 = fgetline(stdin);
    if(!s1 || !s2){
        free(s1);
        free(s2);
        return 0;
    }
    while(s1[i]){
        if(elem(s1[i], s2)) fputc(s1[i], stdout);
        i++;
    }
    fputc('\n', stdout);
    return 0;
}

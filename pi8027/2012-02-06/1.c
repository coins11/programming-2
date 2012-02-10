
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct rec{char *w; int c; struct rec *n;} rec_t;

int main(int argc, char *argv[]){
    FILE *input;
    rec_t *head = NULL, *cur, *prev, *ne;
    char c, *buf = NULL;
    size_t bufsize = 0;
    if(argc != 2 || !(input = fopen(argv[1], "r")))return 1;
    while(1){
        size_t len = 0;
        if(ferror(input))goto ERR;
        while(!isalnum(c = fgetc(input)) && c != '-' && c != '\'' && c != EOF);
        if(ungetc(c, input) == EOF)break;
        while(isalnum(c = fgetc(input)) || c == '-' || c == '\''){
            if(bufsize == len){
                char *tmp = realloc(buf, bufsize+16);
                if(!tmp && (free(buf), 1))goto ERR;
                buf = tmp, bufsize +=16;
            }
            buf[len++] = c;
        }
        buf[len] = '\0';
        prev = NULL, cur = head;
        while(1){
            int r = cur ? strcmp(cur->w, buf) : 1;
            if(!r){
                cur->c++;
                break;
            }
            else if(0 < r){
                if(!(ne = malloc(sizeof(rec_t))) && (free(buf),1))goto ERR;
                ne->w = buf, ne->c = 1;
                prev ? (prev->n = ne, ne->n = cur) : (head = ne, ne->n = NULL);
                buf = NULL, bufsize = 0;
                break;
            }
            prev = cur, cur = cur->n;
        }
    }
    fclose(input);
    cur = head;
    while(cur){
        rec_t *tmp = cur->n;
        printf("%s %d\n", cur->w, cur->c);
        free(cur->w);
        free(cur);
        cur = tmp;
    }
    return 0;
ERR:
    while(cur){
        rec_t *tmp = cur->n;
        free(cur->w);
        free(cur);
        cur = tmp;
    }
    return 1;
}


#include<stdlib.h>
#include<stdio.h>

typedef struct{
    char *name;
    int score;
} scoreinfo_t;

int skipspace(FILE *input)
{
    while(1){
        int c = fgetc(input);
        if(ferror(stdin)){
            return -1;
        }
        if(feof(input)){
            return 0;
        }
        if(!isspace(c)){
            ungetc(c, input);
            return 0;
        }
    }
}

char *fgetword(FILE *input)
{
    char *buf = NULL;
    size_t iter = 0;
    while(1){
        int c = fgetc(input);
        if(ferror(input)){
            free(buf);
            return NULL;
        }
        if(!(iter&16)){
            char *temp = realloc(buf, iter+16);
            if(!temp){
                free(buf);
                return NULL;
            }
            buf = temp;
        }
        if(isspace(c) || feof(input)){
            buf[iter] = '\0';
            return buf;
        }
        buf[iter] = c;
        iter++;
    }
}

int fgetnum(int *d, FILE *input)
{
    int r = 0;
    int err;
    while(1){
        int c = fgetc(input);
        if(ferror(input)){
            return -1;
        }
        if('0' <= c && c <= '9'){
            r = r*10+c-'0';
        }
        else{
            ungetc(c, input);
            *d = r;
            return 0;
        }
    }
}

int compare_scoreinfo(const void *a, const void *b)
{
	return ((scoreinfo_t *)a)->score - ((scoreinfo_t *)b)->score;
}

int main(int argc, char *argv[])
{
    if(2 <= argc){
        scoreinfo_t *arr = NULL;
        size_t iter = 0, iter_ = 0;
        FILE *input = fopen(argv[1], "r");
        if(!input){
            return -1;
        }
        while(1){
            if(skipspace(input)){
                while(iter) free(arr[--iter].name);
                free(arr);
                return 0;
            }
            if(feof(input)){
                break;
            }
            if(!(iter&16)){
                scoreinfo_t *temp = realloc(arr, sizeof(scoreinfo_t)*(iter+16));
                if(!temp){
                    while(iter) free(arr[--iter].name);
                    free(arr);
                    return 0;
                }
                arr = temp;
            }
            if(!(arr[iter].name = fgetword(input))){
                while(iter) free(arr[--iter].name);
                free(arr);
                return 0;
            }
            if(skipspace(input)){
                while(iter) free(arr[--iter].name);
                free(arr);
                return 0;
            }
            if(fgetnum(&arr[iter].score, input)){
                while(iter) free(arr[--iter].name);
                free(arr);
                return 0;
            }
            iter++;
        }
        qsort(arr,iter,sizeof(scoreinfo_t),compare_scoreinfo);
        while(iter_ != iter){
            printf("%s %d\n", arr[iter_].name, arr[iter_].score);
            iter_++;
        }
    }
    return 0;
}


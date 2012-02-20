#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
    struct tree *left, *right;
    int value;
} tree_t;

tree_t *insert(tree_t *t, int v)
{
    if(!t){
        t = malloc(sizeof(tree_t));
        if(!t) return NULL;
        t->left = t->right = NULL;
        t->value = v;
    }
    else{
        tree_t *t_;
        if(v < t->value){
            t_ = insert(t->left, v);
            if(!t_) return NULL;
            t->left = t_;
        }
        else if(t->value < v){
            t_ = insert(t->right, v);
            if(!t_) return NULL;
            t->right = t_;
        }
    }
    return t;
}

int sum_tree(tree_t *t)
{
    return t ? sum_tree(t->left) + t->value + sum_tree(t->right) : 0;
}

int main(int argc, char *argv[])
{
    FILE *input;
    int i, x;
    tree_t *root = NULL;
    if(argc != 2){
        fputs("missing file argument\n", stderr);
        return 1;
    }
    input = fopen(argv[1], "r");
    if(!input){
        fputs("missing file argument\n", stderr);
        return 1;
    }
    for(i = 0; i < 20; i++){
        fscanf(input, "%d", &x);
        root = insert(root, x);
        if(!root) return 1;
    }
    printf("%d\n", sum_tree(root));
    fclose(input);
    return 0;
}

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

int search_tree(tree_t *t, int v)
{
    return t && (t->value == v || (v < t->value ?
        search_tree(t->left, v) : search_tree(t->right, v)));
}

int print_tree(tree_t *t)
{
    if(t){
        print_tree(t->left);
        printf("%d\n", t->value);
        print_tree(t->right);
    }
    return 0;
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
    print_tree(root);
    while(1){
        scanf("%d", &x);
        if(x <= 0) break;
        printf("%d: %s\n", x, search_tree(root, x) ? "Found" : "Not found");
    }
    fclose(input);
    return 0;
}

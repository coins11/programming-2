#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *left;
   struct node *right;
};

struct node *insert_data(int x, struct node *p);
int sum_tree(struct node *p);

int sum_tree(struct node *p) {
   if(p == NULL) return 0;
   return p->data + sum_tree(p->left) + sum_tree(p->right);
}

int main(int argc, char *argv[]) {
   FILE *fp;
   char buffer[256];
   struct node *root = NULL;

   if(argc != 2) {
      fprintf(stderr, "missing file argument\n");
      return 1;
   }
   if((fp = fopen(argv[1], "r")) == NULL) {
      printf("can't open %s\n", argv[1]);
      return 1;
   }
   while(fgets(buffer, sizeof(buffer), fp)) {
      int x;
      sscanf(buffer, "%d", &x);
      root = insert_data(x, root);
   }
   printf("%d\n", sum_tree(root));

   fclose(fp);
   return 0;
}

struct node *insert_data(int x, struct node *p) {
   if(p == NULL) {
      if((p =(struct node *) malloc(sizeof(struct node))) == NULL) {
         printf("Out of memory\n");
         exit(1);
      }
      p->data  = x;
      p->left  = NULL;
      p->right = NULL;
      return p;
   }

   if(x == p->data) return p;
   if(x < p->data) p->left  = insert_data(x, p->left);
   else            p->right = insert_data(x, p->right);
   return p;
}


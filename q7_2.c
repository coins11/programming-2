#include <stdio.h>
#define MAX_ROUTELEN 1000
#define EOP -1

int n;
int route[100][100];
int path[100];

int trace(int from, int to) {
   if(from == to) return 0;
   for(int i = 0; i < n; ++i) {
      if(route[from][i] == 0) continue;
      path[from] = i;
      trace(i, to);
      if(i == n-1) {
         for(int p = 0; p != EOP; p = path[p]) {
            printf("%d-> ", p);
         }
         putchar('\n');
      }
   }
   return 0;
}

int main(int argc, char *argv[]) {
   scanf("%d", &n);
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
         scanf("%d", &route[i][j]);
      }
   }
   path[n-1] = EOP;
   trace(0, n-1);
   return 0;
}


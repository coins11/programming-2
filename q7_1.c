#include <stdio.h>
#define MAX_ROUTELEN 1000
#define EOS -1

int n;
int route[100][100];
int stack[100];
int *sp = &stack[0];

int distance(int from, int to) {
   int d, min = MAX_ROUTELEN;
   *(sp++) = from;
   if(from == to) {
      *sp = EOS;
      return 0;
   }
   for(int i = 0; i < n; ++i) {
      if(route[from][i] == 0) continue;
      else {
         d = route[from][i] + distance(i, to);
         --sp;
      }
      if(d < min) {
         min = d;
         if(from != 0) continue;
         for(int i = 0; stack[i] != EOS; ++i) {
            printf(stack[i] == to? "%d\n":"%d -> ", stack[i]);
         }
      }
   }
   return min;
}

int main(int argc, char *argv[]) {
   scanf("%d", &n);
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
         scanf("%d", &route[i][j]);
      }
   }
   distance(0, n-1);
   return 0;
}


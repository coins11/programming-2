#include <stdio.h>
#include <string.h>
#define MAX_ROUTELEN 1000
#define EOS -1

int n;
int route[100][100];
int stack[100];
int min_route[100];
int *sp = &stack[0];
int global_min = MAX_ROUTELEN;

int distance(int acc, int from, int to) {
   int d, min = MAX_ROUTELEN;
   *(sp++) = from;
   if(from == to) {
      *sp = EOS;
      if(acc < global_min) {
         global_min = acc;
         memcpy(min_route, stack, sizeof(int) * (sp-stack+1));
      }
      return 0;
   }
   for(int i = 0; i < n; ++i) {
      if(route[from][i] == 0) continue;
      else {
         d = route[from][i] + distance(acc+route[from][i], i, to);
         --sp;
      }
      if(d < min) min = d;
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
   distance(0, 0, n-1);
   for(int *p = min_route; *p != EOS; ++p) {
      printf(*p == n-1? "%d\n":"%d -> ", *p);
   }
   return 0;
}


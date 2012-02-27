#include <stdio.h>
#define MAX_ROUTELEN 1000
#define EOP -1

int n;
int route[100][100];
int next[100];

int distance(int from, int to) {
   int d, min = MAX_ROUTELEN;
   if(from == to) return 0;
   for(int i = 0; i < n; ++i) {
      if(route[from][i] == 0) continue;
      d = route[from][i] + distance(i, to);
      if(d < min)  {
         min = d;
         next[from] = i;
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
   next[n-1] = EOP;
   distance(0, n-1);
   for(int p = 0; p != EOP; p = next[p]) {
      printf("%d ", p);
   }
   return 0;
}


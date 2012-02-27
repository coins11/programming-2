#include <stdio.h>
#define ROUTE_MAX 100
#define DISTANCE_MAX 1000

int n;
int route[ROUTE_MAX][ROUTE_MAX];

int distance(int i, int j);

int main()
{
  int i, j;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &route[i][j]);
    }
  }

  printf("minimum distance = %d\n", distance(0, n - 1));

  return 0;
}

int distance(int i, int j)
{
  int d, k, min;

  min = DISTANCE_MAX;

  if (i == j)
    return 0;

  for (k = 0; k < n; k++) {
    if (route[i][k] == 0)
      continue;
    else
      d = route[i][k] + distance(k, j);
    if (d < min)
      min = d;
  }

  return min;
}

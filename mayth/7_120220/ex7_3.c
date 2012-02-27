#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROUTE_MAX 100
#define DISTANCE_MAX 1000

typedef struct path_data {
  int pos;
  int distance;
} PathData;

int n;
int route[ROUTE_MAX][ROUTE_MAX];
int stack_idx = 0;
PathData stack[ROUTE_MAX];

int distance(int i, int j);
void push(PathData p);
void print_stack();
PathData pop();
PathData* create_pathdata(int pos, int distance);
int sum_distance();

int main()
{
  int i, j;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &route[i][j]);
    }
  }

  printf("pos: distance\n");
  distance(0, n - 1);

  return 0;
}

void push(PathData p)
{
  stack[stack_idx++] = p;
}

PathData pop()
{
  PathData p;
  if (stack_idx == 0) {
    printf("stack error\n");
    exit(EXIT_FAILURE);
  }
  p = stack[stack_idx];
  memset(&stack[stack_idx], 0, sizeof(PathData));
  stack_idx--;
  return p;
}

void print_stack()
{
  int i;
  for (i = 0; i < stack_idx; i++)
    printf("%d: %d\n", stack[i].pos, stack[i].distance);
}

int sum_distance()
{
  int i, sum = 0;
  for (i = 0; i < stack_idx; i++)
    sum += stack[i].distance;
  return sum;
}

PathData* create_pathdata(int pos, int distance)
{
  PathData *p;
  p = (PathData *)malloc(sizeof(PathData));
  if (p == NULL) {
    printf("can't allocate memory.\n");
    exit(EXIT_FAILURE);
  }
  p->pos = pos;
  p->distance = distance;
  return p;
}

int distance(int i, int j)
{
  int d, k, min;

  min = DISTANCE_MAX;

  if (i == j) {
    if (i == n - 1)
      push(*create_pathdata(i, route[i][j]));
    print_stack();
    printf("distance = %d\n", sum_distance());
    pop();
    printf("\n");
    return 0;
  }

  for (k = 0; k < n; k++) {
    if (route[i][k] == 0)
      continue;
    else {
      push(*create_pathdata(i, route[i][k]));
      d = route[i][k] + distance(k, j);
    }
    if (d < min) {
      min = d;
      pop();
    }
  }

  return min;
}

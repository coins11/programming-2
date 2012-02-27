#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROUTE_MAX 100
#define DISTANCE_MAX 1000

typedef struct path_data {
  int pos;
  int distance;
} PathData;

typedef struct route_info {
  PathData *paths;
  int path_length;
  int distance;
} RouteInfo;

int n;
int route[ROUTE_MAX][ROUTE_MAX];
int stack_idx = 0;
int route_idx = 0;
PathData stack[ROUTE_MAX];
RouteInfo routes[ROUTE_MAX];

int distance(int i, int j);
void push(PathData p);
void print_stack();
PathData pop();
PathData* create_pathdata(int pos, int distance);
void add_routeinfo(PathData *paths, int path_length, int distance);
int sum_distance();

int main()
{
  int i, j, k = 0, min = DISTANCE_MAX;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &route[i][j]);
    }
  }

  printf("pos: distance\n");
  distance(0, n - 1);

  for (i = 0; i < route_idx; i++) {
    if (routes[i].distance < min) {
      min = routes[i].distance;
      k = i;
    }
  }
  for (i = 0; i < routes[k].path_length; i++)
    printf("route: %d\n", routes[k].paths[i].pos);
  printf("distance: %d\n", routes[k].distance);

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

void add_routeinfo(PathData *paths, int path_length, int distance)
{
  RouteInfo *p;
  p = (RouteInfo *)malloc(sizeof(RouteInfo));
  if (p == NULL) {
    printf("can't allocate memory.\n");
    exit(EXIT_FAILURE);
  }
  p->paths = paths;
  p->path_length = path_length;
  p->distance = distance;
  routes[route_idx++] = *p;
}

int distance(int i, int j)
{
  int d, k, min, m;
  PathData *p;

  min = DISTANCE_MAX;

  if (i == j) {
    if (i == n - 1)
      push(*create_pathdata(i, route[i][j]));
    /* make path */
    p = (PathData *)malloc(sizeof(PathData) * stack_idx + 1);
    if (p == NULL) {
      printf("can't allocate memory.\n");
      exit(EXIT_FAILURE);
    }
    for(m = 0; m < stack_idx; m++)
      p[m] = stack[stack_idx];
    add_routeinfo(p, m + 1, sum_distance());
    pop();
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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<alloca.h>

typedef struct {
    size_t nodes;
    unsigned int *edges;
} graph_t;

#define GET_EDGE(graph, x, y) ((graph)->edges[(graph)->nodes*(x)+(y)])

graph_t *read_graph(FILE *input)
{
    graph_t *graph;
    size_t nodes, i = 0;
    unsigned int *edges;
    scanf("%d", &nodes);
    graph = malloc(sizeof(graph_t));
    edges = malloc(sizeof(unsigned int) * nodes * nodes);
    if(!graph || !edges){
        free(graph);
        free(edges);
        return NULL;
    }
    for(; i != nodes * nodes; i++) scanf("%d", &edges[i]);
    graph->nodes = nodes;
    graph->edges = edges;
    return graph;
}

int pa(graph_t *graph, int *used, size_t *path,
    size_t depth, size_t p1, size_t p2)
{
    size_t i = 0;
    if(used[p1]) return 0;
    if(p1 == p2){
        for(; i != depth; i++){
            printf("%d ", path[i]);
        }
        printf("%d\n", p1);
        return 0;
    }
    used[p1] = 1;
    path[depth] = p1;
    for(; i != graph->nodes; i++)
        if(GET_EDGE(graph, p1, i)) pa(graph, used, path, depth + 1, i, p2);
    used[p1] = 0;
    return 0;
}

int path_all(graph_t *graph, size_t p1, size_t p2)
{
    int *used = alloca(sizeof(int) * graph->nodes);
    size_t *path = alloca(sizeof(size_t) * graph->nodes);
    memset(used, 0, sizeof(int) * graph->nodes);
    pa(graph, used, path, 0, p1, p2);
    return 0;
}

int main(void)
{
    graph_t *graph = read_graph(stdin);
    if(!graph) return 1;
    path_all(graph, 0, graph->nodes-1);
    return 0;
}

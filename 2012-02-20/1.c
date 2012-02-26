
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

int sp(graph_t *graph, int *used, size_t p1, size_t p2){
    int min = -1;
    size_t i = 0;
    if(used[p1]) return -1;
    if(p1 == p2) return 0;
    used[p1] = 1;
    for(; i != graph->nodes; i++){
        int edge = GET_EDGE(graph, p1, i), tmp;
        if(edge){
            tmp = sp(graph, used, i, p2);
            if(tmp != -1 && (min == -1 || tmp + edge < min)) min = tmp + edge;
        }
    }
    used[p1] = 0;
    return min;
}

int shortest_path(graph_t *graph, size_t p1, size_t p2)
{
    int *used;
    used = alloca(sizeof(int) * graph->nodes);
    memset(used, 0, sizeof(int) * graph->nodes);
    return sp(graph, used, p1, p2);
}

int main(void)
{
    graph_t *graph = read_graph(stdin);
    if(!graph) return 1;
    printf("%d\n", shortest_path(graph, 0, graph->nodes-1));
    return 0;
}

#include "../headers/graph.h"

struct Graph{
    int numVertices;
    int numEdges;
    Vertex** vertices;
    Edge** edges;
};

Graph* createGraph(int numVertices, int numEdges){
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->vertices = malloc(numVertices * sizeof(Vertex*));
    graph->edges = malloc(numEdges * sizeof(Edge*));
    return graph;
}
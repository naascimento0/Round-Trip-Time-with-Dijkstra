#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdlib.h>
#include "edge.h"
#include "vertex.h"

typedef struct Graph Graph;

typedef struct{
    int *server;
    int numServers;
    int *client;
    int numClients;
    int *monitor;
    int numMonitors;
    int *regular;
    int numRegulars;
}IndexSet;

Graph* graphInitialize(int numVertices, int numEdges);

Graph* graphCreateFromInput(FILE *inputFile);

void graphAddVertex(Graph *graph, Vertex *vertex);

void graphAddEdge(Graph *graph, Edge *edge, int index);

int getNumVertices(Graph *graph);
int getNumEdges(Graph *graph);
Vertex** getVertices(Graph *graph);
Edge** getEdges(Graph *graph);
IndexSet* getIndexSet(Graph *graph);

void graphDebug(Graph *graph);

void graphDestroy(Graph *graph);

#endif

#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "data_structures/forward_list.h"

typedef struct Graph Graph;

typedef struct{
    int *server;
    int numServers;
    int *client;
    int numClients;
    int *monitor;
    int numMonitors;
}IndexSet;

Graph* graphInitialize(int numVertices, int numEdges);

Graph* graphCreateFromInput(FILE *inputFile);

int getNumVertices(Graph *graph);
int getNumEdges(Graph *graph);
ForwardList** getEdges(Graph *graph);
IndexSet* getIndexSet(Graph *graph);

void graphDebug(Graph *graph);

void graphDestroy(Graph *graph);

#endif

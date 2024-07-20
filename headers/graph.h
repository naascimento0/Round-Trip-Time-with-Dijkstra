#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdlib.h>
#include "edge.h"
#include "vertex.h"

typedef struct Graph Graph;

Graph* graphInitialize(int numVertices, int numEdges);

void graphAddVertex(Graph *graph, Vertex *vertex, int index);

void graphAddEdge(Graph *graph, Edge *edge, int index);

void graphDebug(Graph *graph);

Graph* graphCreateFromInput(FILE *inputFile);

void graphDestroy(Graph *graph);

#endif

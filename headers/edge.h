#ifndef EDGE_H_
#define EDGE_H_

#include <stdlib.h>

typedef struct Edge Edge;

Edge* edgeInitialize(int source, int destination, double weight);

Edge** getVertexAdjacencyList(Edge **edges, int numEdges, int id, int *adjacencyListSize);

int getEdgeSource(Edge *edge);

int getEdgeDestination(Edge *edge);

double getEdgeWeight(Edge *edge);

void edgeDestroy(Edge *edge);

#endif

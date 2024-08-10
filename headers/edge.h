#ifndef EDGE_H_
#define EDGE_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int destination;
    double weight;
}Edge;

Edge* edgeCreate(int destination, double weight);

int getEdgeDestination(Edge *edge);
double getEdgeWeight(Edge *edge);

void edgePrint(Edge *edge);

void edgeDestroy(Edge *edge);

#endif

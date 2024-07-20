#include "../headers/edge.h"

struct Edge{
    int source;
    int destination;
    double weight;
};

Edge* edgeInitialize(int source, int destination, double weight){
    Edge* edge = malloc(sizeof(Edge));
    edge->source = source;
    edge->destination = destination;
    edge->weight = weight;
    return edge;
}

int getEdgeSource(Edge *edge){
    return edge->source;
}

int getEdgeDestination(Edge *edge){
    return edge->destination;
}

double getEdgeWeight(Edge *edge){
    return edge->weight;
}

void edgeDestroy(Edge *edge){
    free(edge);
}


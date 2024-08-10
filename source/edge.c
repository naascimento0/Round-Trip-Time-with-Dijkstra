#include "../headers/edge.h"

Edge* edgeCreate(int destination, double weight){
    Edge *edge = malloc(sizeof(Edge));
    edge->destination = destination;
    edge->weight = weight;
    return edge;
}

int getEdgeDestination(Edge *edge){
    return edge->destination;
}

double getEdgeWeight(Edge *edge){
    return edge->weight;
}

void edgePrint(Edge *edge){
    printf("Edge: to %d, weight: %lf", edge->destination, edge->weight);
}

void edgeDestroy(Edge *edge){
    free(edge);
}

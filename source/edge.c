#include "../headers/edge.h"

struct Edge{
    char source;
    char destination;
    double weight;
};

Edge* createEdge(char source, char destination, double weight){
    Edge* edge = malloc(sizeof(Edge));
    edge->source = source;
    edge->destination = destination;
    edge->weight = weight;
    return edge;
}
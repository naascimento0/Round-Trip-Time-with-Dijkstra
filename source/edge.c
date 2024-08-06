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

Edge** getVertexAdjacencyList(Edge **edges, int numEdges, int id, int *adjacencyListSize){
    int count = 0;
    for(int i = 0; i < numEdges; i++)
        if(getEdgeSource(edges[i]) == id)
            count++;

    Edge **adjacencyList = malloc(count * sizeof(Edge*));
    *adjacencyListSize = count;

    for (int i = 0, j = 0; i < numEdges; i++)
        if(getEdgeSource(edges[i]) == id)
            adjacencyList[j++] = edges[i];

    return adjacencyList;
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


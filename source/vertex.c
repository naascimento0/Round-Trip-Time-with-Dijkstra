#include "../headers/vertex.h"

struct Vertex{
    int id;
    int *adjacencyList;
    int adjacencyListSize;
    int adjacencyListCapacity;
};

Vertex* vertexInitialize(int id){
    Vertex *vertex = malloc(sizeof(Vertex));
    vertex->id = id;
    vertex->adjacencyList = NULL;
    vertex->adjacencyListSize = 0;
    vertex->adjacencyListCapacity = 10;
    return vertex;
}

void vertexAddEdge(Vertex *vertex, int destination){
    if(vertex->adjacencyList == NULL)
        vertex->adjacencyList = malloc(vertex->adjacencyListCapacity * sizeof(int));
    else
        if(vertex->adjacencyListSize == vertex->adjacencyListCapacity){
            vertex->adjacencyListCapacity *= 2;
            vertex->adjacencyList = realloc(vertex->adjacencyList, vertex->adjacencyListCapacity * sizeof(int));
        }
        
    vertex->adjacencyList[vertex->adjacencyListSize++] = destination;
}

int getVertexId(Vertex *vertex){
    return vertex->id;
}

void vertexDebug(Vertex *vertex){
    printf("Vertex %d: ", vertex->id);
    for(int i = 0; i < vertex->adjacencyListSize; i++)
        printf("%d ", vertex->adjacencyList[i]);
    printf("\n");
}

void vertexDestroy(Vertex *vertex){
    free(vertex->adjacencyList);
	free(vertex);
}

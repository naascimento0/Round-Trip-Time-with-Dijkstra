#include "../headers/vertex.h"

struct Vertex{
    int id;
};

Vertex* vertexInitialize(int id){
    Vertex *vertex = malloc(sizeof(Vertex));
    vertex->id = id;
    return vertex;
}

int getVertexId(Vertex *vertex){
    return vertex->id;
}

void vertexDestroy(Vertex *vertex){
	free(vertex);
}

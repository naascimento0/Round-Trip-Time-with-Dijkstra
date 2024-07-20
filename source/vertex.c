#include "../headers/vertex.h"

struct Vertex{
    int id;
    char type;
};

Vertex* vertexInitialize(int id, char type){
    if(type != CLIENT && type != MONITOR && type != SERVER && type != REGULAR)
        exit(printf("Invalid vertex type\n"));
    
    Vertex *vertex = malloc(sizeof(Vertex));
    vertex->id = id;
    vertex->type = type;
    return vertex;
}

int getVertexId(Vertex *vertex){
    return vertex->id;
}

char getVertexType(Vertex *vertex){
    return vertex->type;
}

void vertexDestroy(Vertex *vertex){
	free(vertex);
}

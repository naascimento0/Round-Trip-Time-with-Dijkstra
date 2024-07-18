#include "../headers/vertex.h"

struct Vertex{
    char id;
    char type;
};

Vertex* createVertex(char id, char type){
    if(type != CLIENT && type != MONITOR && type != SERVER)
        exit(printf("Invalid vertex type\n"));
    
    Vertex* vertex = malloc(sizeof(Vertex));
    vertex->id = id;
    vertex->type = type;
    return vertex;
}
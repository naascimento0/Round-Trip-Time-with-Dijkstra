#include "../headers/vertex.h"

struct Vertex{
    char id;
};

Vertex* createVertex(char id){
    Vertex* vertex = malloc(sizeof(Vertex));
    vertex->id = id;
    return vertex;
}
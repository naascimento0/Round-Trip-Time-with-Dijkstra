#ifndef VERTEX_H_
#define VERTEX_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex Vertex;

enum VertexType{
    CLIENT = 'C',
    MONITOR = 'M',
    SERVER = 'S',
	REGULAR = 'R'
};

Vertex* vertexInitialize(int id, char type);

int getVertexId(Vertex *vertex);

char getVertexType(Vertex *vertex);

void vertexDestroy(Vertex *vertex);

#endif

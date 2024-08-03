#ifndef VERTEX_H_
#define VERTEX_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex Vertex;

Vertex* vertexInitialize(int id);

void vertexAddEdge(Vertex *vertex, int destination);

int getVertexId(Vertex *vertex);

void vertexDebug(Vertex *vertex);

void vertexDestroy(Vertex *vertex);

#endif

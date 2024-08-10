#ifndef _NODE_H_
#define _NODE_H_

#include <stdlib.h>
#include <stdio.h>
#include "../edge.h"

typedef Edge* data_type;

typedef struct Node{
    data_type value;
    struct Node *next;
}Node;

Node *node_construct(data_type value, Node *next);

void node_destroy(Node *n, void(*destroy_fn)(data_type));

void node_remove(Node *n);

#endif

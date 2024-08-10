#include <stdlib.h>
#include "../../headers/data_structures/node.h"

Node* node_construct(data_type value, Node *next){
    Node *n = (Node *)malloc(sizeof(Node));
    n->value = value;
    n->next = next;
    return n;
}

void node_destroy(Node *n, void(*destroy_fn)(data_type)){
    destroy_fn(n->value);
    free(n);
}

void node_remove(Node *n){
    free(n);
}




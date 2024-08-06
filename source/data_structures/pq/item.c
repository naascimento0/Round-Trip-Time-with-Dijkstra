#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item* makeItem(int id, double value){
    Item *t = malloc(sizeof(Item));
    id(t) = id;
    value(t) = value;
    return t;
}

int compareItem(Item *a, Item *b) {
    if (value(a) < value(b)) return -1;
    if (value(a) > value(b)) return 1;
    return 0;
}

void deleteItem(Item *item){
    free(item);
}

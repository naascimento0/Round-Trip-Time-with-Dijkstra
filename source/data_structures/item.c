#include <stdio.h>
#include <stdlib.h>
#include "../../headers/data_structures/item.h"

Item* makeItem(int id, double value){
    Item *t = malloc(sizeof(Item));
    t->id = id;
    t->value = value;
    return t;
}

void deleteItem(Item *item){
    free(item);
}

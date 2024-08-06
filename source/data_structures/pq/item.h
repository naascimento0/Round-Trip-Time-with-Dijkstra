#ifndef ITEM_H
#define ITEM_H

typedef struct {
  int id;           // node identifier
  double value;     // node value
} Item;

#define id(A)           (A->id)                          // return node identifier
#define value(A)        (A->value)                       // return node value
#define greater(A, B)   (compareItem(A, B) > 0)          // compare two nodes
#define exch(A, B)      { Item *t = A; A = B; B = t; }   // swap two nodes

Item* makeItem(int id, double value);

int compareItem(Item* a, Item* b);

void deleteItem(Item *item);

#endif

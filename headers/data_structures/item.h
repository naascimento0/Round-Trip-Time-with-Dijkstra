#ifndef ITEM_H
#define ITEM_H

typedef struct{
  int id;           // node identifier
  double value;     // node value
}Item;

#define id(A)           (A->id)                          // return node identifier
#define value(A)        (A->value)                       // return node value
#define more(A, B)      (value(A) > value(B))            // compare two nodes
#define exch(A, B)      { Item *t = A; A = B; B = t; }   // swap two nodes

Item* makeItem(int id, double value);

void deleteItem(Item *item);

#endif

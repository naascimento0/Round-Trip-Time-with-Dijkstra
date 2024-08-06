#ifndef PQ_H
#define PQ_H

#include "item.h"

typedef struct PriorityQueue PriorityQueue;

PriorityQueue* PQ_init(int maxN);                        // create a priority queue with maximum capacity 'maxN'
void PQ_insert(PriorityQueue *pq, Item *item); // insert Item in the PQ. The biggest priority is the one with the smallest 'value' field
Item* PQ_delmin(PriorityQueue *pq);            // Remove Item with smallest 'value' field from PQ
void PQ_decrease_key(PriorityQueue *pq, int id, double value);   // Change the priority of the node with identifier 'id' to 'value'
Item* PQ_min(PriorityQueue *pq);               // return Item with smallest 'value' field from PQ
int PQ_empty(PriorityQueue *pq);               // retorn True if PQ is empty, False otherwise
int PQ_size(PriorityQueue *pq);                // return the number of elements in PQ
void PQ_finish(PriorityQueue *pq);             // free memory allocated for PQ
Item* PQ_find(PriorityQueue *pq, int id);

#endif

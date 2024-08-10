#include <stdio.h>
#include <stdlib.h>
#include "../../headers/data_structures/PQ.h"

struct PriorityQueue{
    Item **heap;
    int *map;
    int size;
};

static void swap(PriorityQueue *pq, int i, int j){
    exch(pq->heap[i], pq->heap[j]);
    pq->map[id(pq->heap[i])] = i;
    pq->map[id(pq->heap[j])] = j;
}

void fix_up(PriorityQueue *pq, int k){
    while (k > 1 && more(pq->heap[k/2], pq->heap[k])){
        swap(pq, k, k/2);
        k = k/2;
    }
}

void fix_down(PriorityQueue *pq, int k){
    while (2 * k <= pq->size) {
        int j = 2 * k;
        if (j < pq->size && more(pq->heap[j], pq->heap[j + 1]))
            j++;  
        if (!more(pq->heap[k], pq->heap[j]))
            break;
        swap(pq, k, j);
        k = j;
    }
}

PriorityQueue* PQ_init(int maxN){
    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    pq->heap = malloc((maxN + 1) * sizeof(Item *));
    pq->map = malloc((maxN + 1) * sizeof(int));
    pq->size = 0;
    return pq;
}

void PQ_insert(PriorityQueue *pq, Item *v) {
    pq->heap[++pq->size] = v;
    pq->map[id(v)] = pq->size;
    fix_up(pq, pq->size);
}

Item* PQ_delmin(PriorityQueue *pq) {
    Item *min = pq->heap[1];
    swap(pq, 1, pq->size--);
    fix_down(pq, 1);
    return min;
}

Item* PQ_min(PriorityQueue *pq){
    return pq->heap[1];
}

void PQ_decrease_key(PriorityQueue *pq, int id, double value){
    int i = pq->map[id];
    pq->heap[i]->value = value;
    fix_up(pq, i);
}

Item* PQ_find(PriorityQueue *pq, int id){
    return pq->heap[pq->map[id]];
}

int PQ_empty(PriorityQueue *pq){
    return pq->size == 0;
}

int PQ_size(PriorityQueue *pq){
    return pq->size;
}

void PQ_finish(PriorityQueue *pq){
    for (int i = 1; i <= pq->size; i++)
        deleteItem(pq->heap[i]);
    free(pq->heap);
    free(pq->map);
    free(pq);
}
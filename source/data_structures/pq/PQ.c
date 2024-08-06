#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

struct PriorityQueue{
    Item **heap;
    int size;
    int capacity;
};

PriorityQueue* PQ_init(int maxN){
    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->capacity = maxN;
    pq->heap = malloc((maxN + 1) * sizeof(Item*));
    return pq;
}

static void swap(PriorityQueue *pq, int i, int j){
    Item *temp = pq->heap[i];
    pq->heap[i] = pq->heap[j];
    pq->heap[j] = temp;
}

void fix_up(PriorityQueue *pq, int k){
    Item **a = pq->heap;
    while(k > 1 && greater(a[k / 2], a[k])){
        swap(pq, k, k / 2);
        k = k / 2;
    }
}

void fix_down(PriorityQueue *pq, int k){
    Item **a = pq->heap;
    while(2 * k <= PQ_size(pq)){
        int j = 2 * k;
        if(j < PQ_size(pq) && greater(a[j], a[j + 1]))
            j++;
        if(!greater(a[k], a[j]))
            break;
        swap(pq, k, j);
        k = j;
    }
}

void PQ_insert(PriorityQueue*pq, Item *item){
    if(PQ_size(pq) == pq->capacity)
        exit(printf("Priority Queue is full\n"));
    pq->heap[++pq->size] = item;
    fix_up(pq, pq->size);
}

Item* PQ_delmin(PriorityQueue *pq){
    Item *min = pq->heap[1];
    swap(pq, 1, pq->size);
    pq->size--;
    fix_down(pq, 1);
    return min;
}

Item* PQ_min(PriorityQueue *pq){
    return pq->heap[1];
}

void PQ_decrease_key(PriorityQueue *pq, int id, double value){
    for(int i = 1; i <= pq->size; i++){
        if(id(pq->heap[i]) == id){
            value(pq->heap[i]) = value;
            fix_up(pq, i);
            break;
        }
    }
}

int PQ_empty(PriorityQueue *pq){
    return pq->size == 0;
}

int PQ_size(PriorityQueue *pq){
    return pq->size;
}

void PQ_finish(PriorityQueue *pq){
    for(int i = 0; i < pq->size; i++)
        deleteItem(pq->heap[i]);
    free(pq->heap);
    free(pq);
}

Item* PQ_find(PriorityQueue *pq, int id){
    for(int i = 1; i <= pq->size; i++){
        if(id(pq->heap[i]) == id)
            return pq->heap[i];
    }
    return NULL;
}



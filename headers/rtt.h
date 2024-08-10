#ifndef RTT_H_
#define RTT_H_

typedef struct RTTResult RTTResult;

#include "graph.h"
#include "data_structures/PQ.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

void RTT(Graph *graph, char *outputFile);

double* dijkstra(ForwardList **edges, int numVertices, int source);

int compareRTTResults(const void *a, const void *b);

#endif

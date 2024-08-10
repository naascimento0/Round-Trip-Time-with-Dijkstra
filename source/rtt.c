#include "../headers/rtt.h"

struct RTTResult{
    int server;
    int client;
    double ratio;
};

void RTT(Graph *graph, char *outputFile){
    int numVertices = getNumVertices(graph);
    ForwardList **edges = getEdges(graph);
    IndexSet *indexSet = getIndexSet(graph);
    RTTResult *results = malloc((indexSet->numServers * indexSet->numClients) * sizeof(RTTResult));
    int count = 0;

    double **serverShortestPaths = malloc(indexSet->numServers * sizeof(double*));
    double **clientShortestPaths = malloc(indexSet->numClients * sizeof(double*));
    double **monitorShortestPaths = malloc(indexSet->numMonitors * sizeof(double*));

    for(int i = 0; i < indexSet->numServers; i++)
        serverShortestPaths[i] = dijkstra(edges, numVertices, indexSet->server[i]);
    for(int i = 0; i < indexSet->numClients; i++)
        clientShortestPaths[i] = dijkstra(edges, numVertices, indexSet->client[i]);
    for(int i = 0; i < indexSet->numMonitors; i++)
        monitorShortestPaths[i] = dijkstra(edges, numVertices, indexSet->monitor[i]);

    for(int s = 0; s < indexSet->numServers; s++){
        int server = indexSet->server[s];
        for(int c = 0; c < indexSet->numClients; c++){
            int client = indexSet->client[c];

            double rttStar = __DBL_MAX__;
            for(int m = 0; m < indexSet->numMonitors; m++){
                int monitor = indexSet->monitor[m];
                rttStar = fmin(rttStar, serverShortestPaths[s][monitor] + monitorShortestPaths[m][server] + monitorShortestPaths[m][client] + clientShortestPaths[c][monitor]);
            }
            results[count++] = (RTTResult){.server = server, .client = client, .ratio = (rttStar / (serverShortestPaths[s][client] + clientShortestPaths[c][server]))};
        }
    }

    for(int i = 0; i < indexSet->numServers; i++)
        free(serverShortestPaths[i]);
    free(serverShortestPaths);

    for(int i = 0; i < indexSet->numClients; i++)
        free(clientShortestPaths[i]);
    free(clientShortestPaths);

    for(int i = 0; i < indexSet->numMonitors; i++)
        free(monitorShortestPaths[i]);
    free(monitorShortestPaths);
    
    qsort(results, indexSet->numServers * indexSet->numClients, sizeof(RTTResult), compareRTTResults);
    FILE *output = fopen(outputFile, "w");
    if(output == NULL)
        exit(printf("Error: Unable to open file %s\n", outputFile));
    for(int i = 0; i < indexSet->numServers * indexSet->numClients; i++){
        fprintf(output, "%d %d ", results[i].server, results[i].client);
        if(results[i].ratio == (int)results[i].ratio)
            fprintf(output, "%.1f\n", results[i].ratio);
        else 
            fprintf(output, "%.16lf\n", results[i].ratio);
    }
    fclose(output);
    free(results);
}

double* dijkstra(ForwardList **edges, int numVertices, int source){
    PriorityQueue *pq = PQ_init(numVertices);
    for(int i = 0; i < numVertices; i++)
        PQ_insert(pq, makeItem(i, __DBL_MAX__));
    PQ_decrease_key(pq, source, 0);
    
    double *distances = calloc(numVertices, sizeof(double));
    int *visited = calloc(numVertices, sizeof(int));

    while(!PQ_empty(pq)){
        Item *min = PQ_delmin(pq);
        visited[id(min)] = 1;
        
        for(int i = 0; i < forward_list_size(edges[id(min)]); i++){
            Edge *edge = forward_list_get(edges[id(min)], i);
            int destination = getEdgeDestination(edge);
            if(visited[destination]) continue;
            double weight = getEdgeWeight(edge);
            Item *sink = PQ_find(pq, destination);
            if(value(sink) > value(min) + weight){
                PQ_decrease_key(pq, destination, value(min) + weight);
                distances[id(sink)] = value(sink);
            }
        }
        deleteItem(min);
    }

    PQ_finish(pq);
    free(visited);
    return distances;
}

int compareRTTResults(const void *a, const void *b){
    RTTResult *resultA = (RTTResult*)a;
    RTTResult *resultB = (RTTResult*)b;

    if(resultA->ratio < resultB->ratio) return -1;
    if(resultA->ratio > resultB->ratio) return 1;

    if(resultA->server < resultB->server) return -1;
    if(resultA->server > resultB->server) return 1;

    if(resultA->client < resultB->client) return -1;
    if(resultA->client > resultB->client) return 1;
    return 0;
}
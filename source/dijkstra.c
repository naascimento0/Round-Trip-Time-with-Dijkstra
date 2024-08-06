#include "../headers/dijkstra.h"

double** realRTT(Graph *graph){
    int numVertices = getNumVertices(graph);
    int numEdges = getNumEdges(graph);
    Edge **edges = getEdges(graph);
    IndexSet *indexSet = getIndexSet(graph);

    double **shortestPaths = calloc(indexSet->numClients + indexSet->numServers, sizeof(double*));
    for(int i = 0; i < indexSet->numClients + indexSet->numServers; i++)
        shortestPaths[i] = calloc(numVertices, sizeof(double));
    
    int currentSource = 0;
    int *finished = calloc(numVertices, sizeof(int));
    
    PriorityQueue *pq = PQ_init(numVertices);

    for(int clientIndex = 0; clientIndex < indexSet->numClients; clientIndex++){
        for(int vertexIndex = 0; vertexIndex < numVertices; vertexIndex++){
            Item *item = makeItem(vertexIndex, __DBL_MAX__);
            PQ_insert(pq, item);
        }
        PQ_decrease_key(pq, indexSet->client[clientIndex], 0);
        
        memset(finished, 0, numVertices * sizeof(int));
        while(!PQ_empty(pq)){
            Item *min = PQ_delmin(pq);
            finished[min->id] = 1;

            int adjacencyListSize;
            Edge **adjacencyList = getVertexAdjacencyList(edges, numEdges, min->id, &adjacencyListSize);

            for(int i = 0; i < adjacencyListSize; i++){
                int destination = getEdgeDestination(adjacencyList[i]);
                if(finished[destination])
                    continue;
                double weight = getEdgeWeight(adjacencyList[i]);
                Item *server = PQ_find(pq, destination);
                if(server->value > min->value + weight){
                    server->value = min->value + weight;
                    PQ_decrease_key(pq, destination, server->value);
                }
                shortestPaths[currentSource][server->id] = server->value;
            }

            free(adjacencyList);
            deleteItem(min);
        }

        currentSource++;
        free(finished);
    }

    for(int serverIndex = 0; serverIndex < indexSet->numServers; serverIndex++){
        for(int vertexIndex = 0; vertexIndex < numVertices; vertexIndex++){
            Item *item = makeItem(vertexIndex, __DBL_MAX__);
            PQ_insert(pq, item);
        }
        PQ_decrease_key(pq, indexSet->server[serverIndex], 0);
        
        memset(finished, 0, numVertices * sizeof(int));
        while(!PQ_empty(pq)){
            Item *min = PQ_delmin(pq);
            finished[min->id] = 1;

            int adjacencyListSize;
            Edge **adjacencyList = getVertexAdjacencyList(edges, numEdges, min->id, &adjacencyListSize);

            for(int i = 0; i < adjacencyListSize; i++){
                int destination = getEdgeDestination(adjacencyList[i]);
                if (finished[destination])
                    continue;
                double weight = getEdgeWeight(adjacencyList[i]);
                Item *client = PQ_find(pq, destination);
                if(client->value > min->value + weight){
                    client->value = min->value + weight;
                    PQ_decrease_key(pq, destination, client->value);
                }
                shortestPaths[currentSource][client->id] = client->value;
            }

            free(adjacencyList);
            deleteItem(min);
        }

        currentSource++;
        free(finished);
    }

    PQ_finish(pq);
    return shortestPaths;
}


// double** realRTT(Graph *graph){
//     int numVertices = getNumVertices(graph);
//     int numEdges = getNumEdges(graph);
//     Edge **edges = getEdges(graph);
//     IndexSet *indexSet = getIndexSet(graph);

//     double **shortestPaths = malloc(sizeof(double*) * numVertices);
//     for(int i = 0; i < numVertices; i++)
//         shortestPaths[i] = calloc(numVertices, sizeof(double));
    
//     PriorityQueue *pq = PQ_init(numVertices);

//     for(int clientIndex = 0; clientIndex < indexSet->numClients; clientIndex++){
//         for(int vertexIndex = 0; vertexIndex < numVertices; vertexIndex++){
//             Item *item = makeItem(vertexIndex, __DBL_MAX__);
//             PQ_insert(pq, item);
//         }
//         PQ_decrease_key(pq, indexSet->client[clientIndex], 0);
//         int *finished = calloc(numVertices, sizeof(int));

//         while(!PQ_empty(pq)){
//             Item *min = PQ_delmin(pq);
//             finished[min->id] = 1;

//             int adjacencyListSize;
//             Edge **adjacencyList = getVertexAdjacencyList(edges, numEdges, min->id, &adjacencyListSize);

//             for(int i = 0; i < adjacencyListSize; i++){
//                 int destination = getEdgeDestination(adjacencyList[i]);
//                 if(finished[destination])
//                     continue;
//                 double weight = getEdgeWeight(adjacencyList[i]);
//                 Item *server = PQ_find(pq, destination);
//                 if(server->value > min->value + weight){
//                     server->value = min->value + weight;
//                     PQ_decrease_key(pq, destination, server->value);
//                 }
//                 shortestPaths[indexSet->client[clientIndex]][server->id] = server->value;
//             }

//             free(adjacencyList);
//             deleteItem(min);
//         }

//         free(finished);
//     }

//     for(int clientIndex = 0; clientIndex < indexSet->numServers; clientIndex++){
//         for(int vertexIndex = 0; vertexIndex < numVertices; vertexIndex++){
//             Item *item = makeItem(vertexIndex, __DBL_MAX__);
//             PQ_insert(pq, item);
//         }
//         PQ_decrease_key(pq, indexSet->server[clientIndex], 0);
//         int *finished = calloc(numVertices, sizeof(int));

//         while(!PQ_empty(pq)){
//             Item *min = PQ_delmin(pq);
//             finished[min->id] = 1;

//             int adjacencyListSize;
//             Edge **adjacencyList = getVertexAdjacencyList(edges, numEdges, min->id, &adjacencyListSize);

//             for(int i = 0; i < adjacencyListSize; i++){
//                 int destination = getEdgeDestination(adjacencyList[i]);
//                 if (finished[destination])
//                     continue;
//                 double weight = getEdgeWeight(adjacencyList[i]);
//                 Item *client = PQ_find(pq, destination);
//                 if(client->value > min->value + weight){
//                     client->value = min->value + weight;
//                     PQ_decrease_key(pq, destination, client->value);
//                 }
//                 shortestPaths[indexSet->server[clientIndex]][client->id] = client->value;
//             }

//             free(adjacencyList);
//             deleteItem(min);
//         }

//         free(finished);
//     }

//     PQ_finish(pq);
//     return shortestPaths;
// }

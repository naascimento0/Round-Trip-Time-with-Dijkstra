#include "../headers/graph.h"

struct Graph{
    int numVertices;
    int numEdges;
    ForwardList **edges;
    IndexSet *indexSet;
};

Graph* graphInitialize(int numVertices, int numEdges){
    Graph* graph = calloc(1, sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = malloc(numVertices * sizeof(ForwardList*));
    for(int i = 0; i < numVertices; i++)
        graph->edges[i] = forward_list_construct();
    graph->indexSet = malloc(sizeof(IndexSet));
    return graph;
}

Graph* graphCreateFromInput(FILE *inputFile){
    int numVertices, numEdges;
    fscanf(inputFile, "%d %d", &numVertices, &numEdges);
    Graph *graph = graphInitialize(numVertices, numEdges);

    int S, C, M;
    fscanf(inputFile, "%d %d %d", &S, &C, &M);

    graph->indexSet->server = malloc(S * sizeof(int));
    graph->indexSet->numServers = S;

    graph->indexSet->client = malloc(C * sizeof(int));
    graph->indexSet->numClients = C;

    graph->indexSet->monitor = malloc(M * sizeof(int));
    graph->indexSet->numMonitors = M;

    for(int i = 0; i < S; i++){
        int id;
        fscanf(inputFile, "%d", &id);
        graph->indexSet->server[i] = id;
    }

    for(int i = 0; i < C; i++){
    	int id;
        fscanf(inputFile, "%d", &id);
        graph->indexSet->client[i] = id;
    }

    for(int i = 0; i < M; i++){
    	int id;
        fscanf(inputFile, "%d", &id);
        graph->indexSet->monitor[i] = id;
    }

    for(int i = 0; i < numEdges; i++){
        int source, destination;
        double weight;
        fscanf(inputFile, "%d %d %lf", &source, &destination, &weight);
        forward_list_push_front(graph->edges[source], edgeCreate(destination, weight));
    }

    return graph;
}

int getNumVertices(Graph *graph){
    return graph->numVertices;
}

int getNumEdges(Graph *graph){
    return graph->numEdges;
}

ForwardList** getEdges(Graph *graph){
    return graph->edges;
}

IndexSet* getIndexSet(Graph *graph){
    return graph->indexSet;
}

void graphDebug(Graph *graph){
    for(int i = 0; i < getNumVertices(graph); i++){
        printf("\nVertex %d: ", i);
        forward_list_print(graph->edges[i], edgePrint);
    }
    printf("\n");
}

void graphDestroy(Graph *graph){
    free(graph->indexSet->server);
    free(graph->indexSet->client);
    free(graph->indexSet->monitor);
    free(graph->indexSet);

    for(int i = 0; i < getNumVertices(graph); i++)
        forward_list_destroy(graph->edges[i], edgeDestroy);
    free(graph->edges);
	free(graph);
}

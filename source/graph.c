#include "../headers/graph.h"

struct Graph{
    int numVertices;
    int numEdges;
    Vertex** vertices;
    Edge** edges;
    IndexSet *indexSet;
};

Graph* graphInitialize(int numVertices, int numEdges){
    Graph* graph = calloc(1, sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->vertices = calloc(numVertices, sizeof(Vertex*));
    graph->edges = calloc(numEdges, sizeof(Edge**));
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

    graph->indexSet->regular = malloc((numVertices - S - C - M) * sizeof(int));
    graph->indexSet->numRegulars = numVertices - S - C - M;

    for(int i = 0; i < S; i++){
        int id;
        fscanf(inputFile, "%d", &id);
        graphAddVertex(graph, vertexInitialize(id));
        graph->indexSet->server[i] = id;
    }

    for(int i = 0; i < C; i++){
    	int id;
        fscanf(inputFile, "%d", &id);
        graphAddVertex(graph, vertexInitialize(id));
        graph->indexSet->client[i] = id;
    }

    for(int i = 0; i < M; i++){
    	int id;
        fscanf(inputFile, "%d", &id);
        graphAddVertex(graph, vertexInitialize(id));
        graph->indexSet->monitor[i] = id;
    }

    for(int i = 0, count = 0; i < numVertices; i++){
    	if(graph->vertices[i] == NULL){
    		graphAddVertex(graph, vertexInitialize(i));
            graph->indexSet->regular[count++] = i;
            graph->indexSet->numRegulars++;
        }
    }

    for(int i = 0; i < numEdges; i++){
        int source, destination;
        double weight;
        fscanf(inputFile, "%d %d %lf", &source, &destination, &weight);
        graphAddEdge(graph, edgeInitialize(source, destination, weight), i);
    }

    return graph;
}

void graphAddVertex(Graph *graph, Vertex *vertex){
    graph->vertices[getVertexId(vertex)] = vertex;
}

void graphAddEdge(Graph *graph, Edge *edge, int index){
    graph->edges[index] = edge;
}

int getNumVertices(Graph *graph){
    return graph->numVertices;
}

int getNumEdges(Graph *graph){
    return graph->numEdges;
}

Vertex** getVertices(Graph *graph){
    return graph->vertices;
}

Edge** getEdges(Graph *graph){
    return graph->edges;
}

IndexSet* getIndexSet(Graph *graph){
    return graph->indexSet;
}

void graphDebug(Graph *graph){
    printf("Vertices:\n");
    for(int i = 0; i < graph->numVertices; i++)
        printf("Vertex %d: %d\n", i, getVertexId(graph->vertices[i]));

    printf("Edges:\n");
    for(int i = 0; i < graph->numEdges; i++)
        printf("Edge %d: from %d to %d, weight: %lf\n", i, getEdgeSource(graph->edges[i]), getEdgeDestination(graph->edges[i]), getEdgeWeight(graph->edges[i]));
}


void graphDestroy(Graph *graph){
	for(int i = 0; i < graph->numVertices; i++)
		vertexDestroy(graph->vertices[i]);

    for(int i = 0; i < graph->numEdges; i++)
        edgeDestroy(graph->edges[i]);

    free(graph->indexSet->server);
    free(graph->indexSet->client);
    free(graph->indexSet->monitor);
    free(graph->indexSet->regular);
    free(graph->indexSet);

	free(graph->vertices);
	free(graph->edges);
	free(graph);
}

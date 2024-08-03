#include "../headers/graph.h"

struct Graph{
    int numVertices;
    int numEdges;
    Vertex** vertices;
    Edge** edges;
    int *clients;         // clients nodes id's
    int *monitors;        // monitors nodes id's
    int *servers;         // servers nodes id's
    int *regulars;        // other nodes id's
};

Graph* graphInitialize(int numVertices, int numEdges){
    Graph* graph = calloc(1, sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->vertices = calloc(numVertices, sizeof(Vertex*));
    graph->edges = calloc(numEdges, sizeof(Edge*));
    return graph;
}

void graphAddVertex(Graph *graph, Vertex *vertex){
    graph->vertices[getVertexId(vertex)] = vertex;
}

void graphAddEdge(Graph *graph, Edge *edge, int index){
    graph->edges[index] = edge;
}

void graphDebug(Graph *graph){
    printf("Vertices:\n");
    for(int i = 0; i < graph->numVertices; i++)
        vertexDebug(graph->vertices[i]);

    printf("Edges:\n");
    for(int i = 0; i < graph->numEdges; i++)
        printf("Edge %d: %d %d %lf\n", i, getEdgeSource(graph->edges[i]), getEdgeDestination(graph->edges[i]), getEdgeWeight(graph->edges[i]));
}

Graph* graphCreateFromInput(FILE *inputFile){
    int numVertices, numEdges;
    fscanf(inputFile, "%d %d", &numVertices, &numEdges);
    Graph *graph = graphInitialize(numVertices, numEdges);

    int S, C, M;
    fscanf(inputFile, "%d %d %d", &S, &C, &M);

    graph->servers = malloc(S * sizeof(int));
    for(int i = 0; i < S; i++){
        int id;
        fscanf(inputFile, "%d", &id);
        graphAddVertex(graph, vertexInitialize(id));
        graph->servers[i] = id;
    }

    graph->clients = malloc(C * sizeof(int));
    for(int i = 0; i < C; i++){
    	int id;
        fscanf(inputFile, "%d", &id);
        graphAddVertex(graph, vertexInitialize(id));
        graph->clients[i] = id;
    }

    graph->monitors = malloc(M * sizeof(int));
    for(int i = 0; i < M; i++){
    	int id;
        fscanf(inputFile, "%d", &id);
        graphAddVertex(graph, vertexInitialize(id));
        graph->monitors[i] = id;
    }

    graph->regulars = malloc((numVertices - (S + C + M)) * sizeof(int));
    for(int i = 0, count = 0; i < numVertices; i++){
    	if(graph->vertices[i] == NULL){
    		graphAddVertex(graph, vertexInitialize(i));
    		graph->regulars[count++] = i;
    	}
    }

    for(int i = 0; i < numEdges; i++){
        int source, destination;
        double weight;
        fscanf(inputFile, "%d %d %lf", &source, &destination, &weight);
        graphAddEdge(graph, edgeInitialize(source, destination, weight), i);
        vertexAddEdge(graph->vertices[source], destination);
    }

    return graph;
}

void graphDestroy(Graph *graph){
	for(int i = 0; i < graph->numVertices; i++)
		vertexDestroy(graph->vertices[i]);

    for(int i = 0; i < graph->numEdges; i++)
        edgeDestroy(graph->edges[i]);

    free(graph->clients);
    free(graph->monitors);
    free(graph->servers);
    free(graph->regulars);

	free(graph->vertices);
	free(graph->edges);
	free(graph);
}

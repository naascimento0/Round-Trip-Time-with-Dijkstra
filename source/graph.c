#include "../headers/graph.h"

struct Graph{
    int numVertices;
    int numEdges;
    Vertex** vertices;
    Edge** edges;
};

Graph* graphInitialize(int numVertices, int numEdges){
    Graph* graph = calloc(1, sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->vertices = calloc(numVertices, sizeof(Vertex*));
    graph->edges = calloc(numEdges, sizeof(Edge*));
    return graph;
}

void graphAddVertex(Graph *graph, Vertex *vertex, int index){
    graph->vertices[index] = vertex;
}

void graphDebug(Graph *graph){
    printf("Vertices:\n");
    for(int i = 0; i < graph->numVertices; i++)
        printf("Vertex %d: %d %c\n", i, getVertexId(graph->vertices[i]), getVertexType(graph->vertices[i]));

    // printf("Edges:\n");
    // for(int i = 0; i < graph->numEdges; i++){
    //     printf("Edge %d: %c %c %f\n", i, graph->edges[i]->source, graph->edges[i]->destination, graph->edges[i]->weight);
    // }
}

Graph* graphCreateFromInput(FILE *inputFile){
    int numVertices, numEdges;
    fscanf(inputFile, "%d %d", &numVertices, &numEdges);
    Graph *graph = graphInitialize(numVertices, numEdges);

    int S, C, M;
    fscanf(inputFile, "%d %d %d", &S, &C, &M);

    for(int i = 0; i < S; i++){
        int id;
        fscanf(inputFile, "%d", &id);
        graphAddVertex(graph, vertexInitialize(id, SERVER), id);
    }

    for(int i = 0; i < C; i++){
    	int id;
        fscanf(inputFile, "%d", &id);
        graphAddVertex(graph, vertexInitialize(id, CLIENT), id);
    }

    for(int i = 0; i < M; i++){
    	int id;
        fscanf(inputFile, "%d", &id);
        graphAddVertex(graph, vertexInitialize(id, MONITOR), id);
    }

    for(int i = 0; i < numVertices; i++)
    	if(graph->vertices[i] == NULL)
    		graphAddVertex(graph, vertexInitialize(i, REGULAR), i);

    return graph;
}

void graphDestroy(Graph *graph){
	for(int i = 0; i < graph->numVertices; i++)
		vertexDestroy(graph->vertices[i]);

	free(graph->vertices);
	free(graph->edges);
	free(graph);
}

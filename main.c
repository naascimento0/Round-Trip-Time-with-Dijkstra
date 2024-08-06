#include <stdio.h>
#include <stdlib.h>
#include "headers/graph.h"
#include "headers/dijkstra.h"

int main(int argc, char **argv){
    if(argc != 3)
        exit(printf("Error: Invalid number of arguments\n"));

    FILE *inputFile = fopen(argv[1], "r");
    if(inputFile == NULL)
        exit(printf("Error: Unable to open file %s\n", argv[1]));

    Graph *graph = graphCreateFromInput(inputFile);
    fclose(inputFile);

    double **shortestPathsReal = realRTT(graph);

    graphDebug(graph);

    IndexSet *indexSet = getIndexSet(graph);
    for(int i = 0; i < indexSet->numClients + indexSet->numServers; i++){
        for(int j = 0; j < getNumVertices(graph); j++)
            printf("%lf ", shortestPathsReal[i][j]);
        printf("\n");
    }

    for(int i = 0; i < indexSet->numClients + indexSet->numServers; i++)
        free(shortestPathsReal[i]);
    free(shortestPathsReal);

    graphDestroy(graph);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "headers/graph.h"
#include "headers/rtt.h"

int main(int argc, char **argv){
    if(argc != 3)
        exit(printf("Error: Invalid number of arguments\n"));

    FILE *inputFile = fopen(argv[1], "r");
    if(inputFile == NULL)
        exit(printf("Error: Unable to open file %s\n", argv[1]));

    Graph *graph = graphCreateFromInput(inputFile);
    fclose(inputFile);

    RTT(graph, argv[2]);

    graphDestroy(graph);

    return 0;
}

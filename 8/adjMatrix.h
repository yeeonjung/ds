#pragma once
#define MAX_VERTICES 30

typedef struct graphType{
    int n;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} graphType;

void createGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjMatrix(graphType* g);
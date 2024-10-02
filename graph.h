// T4 - SCC503
// Giancarlo Malfate Caprino, nUSP: 12725025


#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_VERTEX 100


typedef struct {
    char name[50];
} Vertex;

typedef struct {
    int source;
    int target;
    float weight;
} Edge;

typedef struct {
    float distance;
    int previous;
    bool visited;
} DijkstraData;

void dijkstra(int n, Vertex vertices[], int m, Edge edges[], int q, char customer_names[][50]);

#endif
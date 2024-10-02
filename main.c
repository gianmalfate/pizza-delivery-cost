// T4 - SCC503
// Giancarlo Malfate Caprino, nUSP: 12725025


#include "graph.h"



int main() {
    int n; // Quantidade de vértices
    scanf("%d", &n);

    Vertex vertices[MAX_VERTEX];

    // Leitura dos vértices
    for (int i = 0; i < n; i++) {
        scanf("%s", vertices[i].name);
    }

    int m; // Quantidade de arestas
    scanf("%d", &m);

    Edge edges[MAX_VERTEX];

    // Leitura das arestas
    for (int i = 0; i < m; i++) {
        char source_name[50];
        char target_name[50];
        float weight;

        scanf("%s %s %f", source_name, target_name, &weight);

        // Encontra o índice dos vértices na lista de vértices
        int source = -1;
        int target = -1;

        for (int j = 0; j < n; j++) {
            if (strcmp(vertices[j].name, source_name) == 0) {
                source = j;
            }
            if (strcmp(vertices[j].name, target_name) == 0) {
                target = j;
            }
        }

        if (source == -1 || target == -1) {
            printf("Vértices inválidos: %s %s\n", source_name, target_name);
            continue;
        }

        edges[i].source = source;
        edges[i].target = target;
        edges[i].weight = weight;
    }

    int q; // Quantidade de custos de entregas
    scanf("%d", &q);

    char customer_names[MAX_VERTEX][50];

    // Leitura dos nomes dos clientes
    for (int i = 0; i < q; i++) {
        scanf("%s", customer_names[i]);
    }

    dijkstra(n, vertices, m, edges, q, customer_names);

    return 0;
}
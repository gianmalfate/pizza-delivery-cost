// T4 - SCC503
// Giancarlo Malfate Caprino, nUSP: 12725025


#include "graph.h"


void dijkstra(int n, Vertex vertices[], int m, Edge edges[], int q, char customer_names[][50]) {
    float adjMatrix[MAX_VERTEX][MAX_VERTEX];  // Matriz de adjacência para armazenar os pesos das arestas

    // Inicializa a matriz de adjacência com infinito (valor padrão)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = INT_MAX;
        }
    }

    // Preenche a matriz de adjacência com os pesos das arestas
    for (int i = 0; i < m; i++) {
        int source = edges[i].source;
        int target = edges[i].target;
        float weight = edges[i].weight;

        adjMatrix[source][target] = weight;
        adjMatrix[target][source] = weight;
    }

    // Loop para processar cada cliente
    for (int i = 0; i < q; i++) {
        char *customer_name = customer_names[i];

        int source = 0;  // Índice da pizzaria
        int target = -1;

        // Encontra o índice do cliente na lista de vértices
        for (int j = 0; j < n; j++) {
            if (strcmp(vertices[j].name, customer_name) == 0) {
                target = j;
                break;
            }
        }

        if (target == -1) {
            printf("Cliente %s não encontrado.\n", customer_name);
            continue;
        }

        DijkstraData data[MAX_VERTEX];  // Dados do algoritmo de Dijkstra para cada vértice

        // Inicializa os dados do algoritmo de Dijkstra
        for (int j = 0; j < n; j++) {
            data[j].distance = INT_MAX;
            data[j].previous = -1;
            data[j].visited = false;
        }

        data[source].distance = 0;

        // Executa o algoritmo de Dijkstra
        for (int j = 0; j < n; j++) {
            int minDistance = INT_MAX;
            int minIndex = -1;

            // Encontra o vértice não visitado com menor distância
            for (int k = 0; k < n; k++) {
                if (!data[k].visited && data[k].distance < minDistance) {
                    minDistance = data[k].distance;
                    minIndex = k;
                }
            }

            if (minIndex == -1)
                break;

            data[minIndex].visited = true;

            // Atualiza as distâncias dos vértices vizinhos não visitados
            for (int k = 0; k < n; k++) {
                if (!data[k].visited && adjMatrix[minIndex][k] != INT_MAX) {
                    float distance = data[minIndex].distance + adjMatrix[minIndex][k];

                    if (distance < data[k].distance) {
                        data[k].distance = distance;
                        data[k].previous = minIndex;
                    }
                }
            }
        }

        // Calcula o custo da entrega pelo menor caminho
        float delivery_cost = 1.50 + 0.20 * data[target].distance;
        printf("%.2f\n", delivery_cost);
    }
}
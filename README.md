# Pizza Delivery Cost

## Descrição
Este projeto implementa o algoritmo de Dijkstra para calcular o custo de entregas de uma pizzaria para seus clientes, levando em consideração a distância mínima entre a pizzaria e os clientes. As distâncias são representadas em uma matriz de adjacência que modela as ruas entre os clientes e a pizzaria.

## Funcionalidades
- Leitura de vértices que representam locais (pizzaria e clientes).
- Leitura de arestas que representam as ruas com seus respectivos pesos (distâncias).
- Utiliza o algoritmo de Dijkstra para encontrar o menor caminho entre a pizzaria e os clientes.
- Calcula o custo da entrega com base na menor distância.

## Como rodar o projeto

1. Compile o código:
2. Execute o programa:
3. Insira os dados conforme solicitado:
- Quantidade de vértices (locais)
- Lista de vértices (nomes dos locais)
- Quantidade de arestas (ruas)
- Lista de arestas (nome de origem, nome de destino e peso)
- Quantidade de clientes
- Nomes dos clientes para calcular o custo da entrega

## Estrutura do código
- `main.c`: Ponto de entrada do programa, responsável pela leitura dos dados e invocação da função `dijkstra`.
- `graph.c`: Implementação do algoritmo de Dijkstra.
- `graph.h`: Definições de structs e funções utilizadas no projeto.

## Autoria
Projeto desenvolvido por Giancarlo Malfate Caprino

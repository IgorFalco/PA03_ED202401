#pragma once

#include "graph.hpp"
#include <iostream>

void LeGrafo(Grafo &G) {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        G.InsereVertice();
    }

    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; ++j) {
            int vizinho;
            std::cin >> vizinho;
            G.InsereAresta(i, vizinho);
        }
    }
}

void ImprimeDadosBasicos(Grafo &G) {
    std::cout << G.QuantidadeVertices() << std::endl;
    std::cout << G.QuantidadeArestas() << std::endl;
    std::cout << G.GrauMinimo() << std::endl;
    std::cout << G.GrauMaximo() << std::endl;
}

void ImprimeTodosVizinhos(Grafo G) {
    for (int i = 0; i < G.QuantidadeVertices(); ++i) {
        G.ImprimeVizinhos(i);
    }
}
#include "lista.hpp"
#include <iostream>
#include <limits>

ListaAdjacencia::ListaAdjacencia() : lista(nullptr), numVertices(0), numArestas(0) {}

ListaAdjacencia::~ListaAdjacencia() {
    LiberaMemoria();
}

void ListaAdjacencia::InsereVertice() {
    No** novaLista = new No*[numVertices + 1];
    for (int i = 0; i < numVertices; ++i) {
        novaLista[i] = lista[i];
    }
    novaLista[numVertices] = nullptr;

    delete[] lista;
    lista = novaLista;
    ++numVertices;
}

void ListaAdjacencia::InsereAresta(int v, int w) {
    if (v >= numVertices || w >= numVertices) return;
    
    No* novoNo = new No{w, lista[v]};
    lista[v] = novoNo;
    ++numArestas;
}

int ListaAdjacencia::QuantidadeVertices() {
    return numVertices;
}

int ListaAdjacencia::QuantidadeArestas() {
    return numArestas;
}

int ListaAdjacencia::GrauMinimo() {
    int grauMin = std::numeric_limits<int>::max();
    for (int i = 0; i < numVertices; ++i) {
        int grau = 0;
        for (No* no = lista[i]; no != nullptr; no = no->proximo) {
            ++grau;
        }
        if (grau < grauMin) {
            grauMin = grau;
        }
    }
    return grauMin;
}

int ListaAdjacencia::GrauMaximo() {
    int grauMax = 0;
    for (int i = 0; i < numVertices; ++i) {
        int grau = 0;
        for (No* no = lista[i]; no != nullptr; no = no->proximo) {
            ++grau;
        }
        if (grau > grauMax) {
            grauMax = grau;
        }
    }
    return grauMax;
}

void ListaAdjacencia::ImprimeVizinhos(int v) {
    for (No* no = lista[v]; no != nullptr; no = no->proximo) {
        std::cout << no->vertice << " ";
    }
    std::cout << std::endl;
}

void ListaAdjacencia::LiberaMemoria() {
    for (int i = 0; i < numVertices; ++i) {
        No* no = lista[i];
        while (no != nullptr) {
            No* temp = no;
            no = no->proximo;
            delete temp;
        }
    }
    delete[] lista;
}
bool ListaAdjacencia::EhCompleto() {

    int n;
    ListaAdjacencia Lista;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        Lista.InsereVertice();
    }

    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; ++j) {
            int vizinho;
            std::cin >> vizinho;
            Lista.InsereAresta(i, vizinho);
        }
    }
    
    for (int i = 0; i < numVertices; ++i) {
        int grau = 0;
        for (No* no = Lista.lista[i]; no != nullptr; no = no->proximo) {
            ++grau;
        }
        if (grau != Lista.numVertices - 1) {
            return false;
        }
    }
    return true;
}


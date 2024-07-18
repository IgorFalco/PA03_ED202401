#ifndef LISTA_HPP
#define LISTA_HPP

struct No {
    int vertice;
    No* proximo;
};

class ListaAdjacencia {
public:
    ListaAdjacencia();
    ~ListaAdjacencia();

    void InsereVertice();
    void InsereAresta(int v, int w);

    int QuantidadeVertices();
    int QuantidadeArestas();

    int GrauMinimo();
    int GrauMaximo();

    void ImprimeVizinhos(int v);
    bool EhCompleto();

private:
    No** lista;
    int numVertices;
    int numArestas;

    void LiberaMemoria();
};

#endif // LISTA_HPP

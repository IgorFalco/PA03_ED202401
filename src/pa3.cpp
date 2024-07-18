#include "graph.hpp"
#include "auxiliar.hpp"
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " -d" << std::endl;
        return 1;
    }

    if (std::strcmp(argv[1], "-d") == 0) {

        Grafo d;
        LeGrafo(d);
        ImprimeDadosBasicos(d);

        std::cout<< "D" << std::endl;
    }
    // else if (std::strcmp(argv[1], "-n") == 0){

    //     Grafo n;
    //     LeGrafo(n);

    //     ImprimeTodosVizinhos(n);

    //     std::cout<< "N" << std::endl;

    // } else if (std::strcmp(argv[1], "-k") == 0){
    //     ListaAdjacencia Lista;
    //     Lista.EhCompleto();

    //     std::cout<< "K" << std::endl;

    // } 
    else{
        std::cerr << "Operacao desconhecida: " << argv[1] << std::endl;
        return 1;
    }

    return 0;
}

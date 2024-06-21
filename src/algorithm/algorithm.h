

#ifndef AIZO_GRAPHS_ALGORITHM_H
#define AIZO_GRAPHS_ALGORITHM_H


#include "../graph/graph.h"
#include "result.h"

template<typename T>
class algorithm {
public:
    /**
     * Uruchamia algorytm na grafie
     *
     * @param graph graf
     * @param start wierzchołek startowy
     * @param print czy wypisać wynik
     */
    virtual T run(graph& graph, ushort start) = 0;
};


#endif //AIZO_GRAPHS_ALGORITHM_H



#ifndef AIZO_GRAPHS_ALGORITHM_H
#define AIZO_GRAPHS_ALGORITHM_H


#include "../graph/graph.h"

class algorithm {
public:
    /**
     * Uruchamia algorytm na grafie
     *
     * @param graph graf
     * @param start wierzchołek startowy
     * @param print czy wypisać wynik
     */
    virtual void run(graph& graph, ushort start, bool print) = 0;
};


#endif //AIZO_GRAPHS_ALGORITHM_H

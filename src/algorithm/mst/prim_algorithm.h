

#ifndef AIZO_GRAPHS_PRIM_ALGORITHM_H
#define AIZO_GRAPHS_PRIM_ALGORITHM_H


#include "../algorithm.h"

class prim_algorithm : public algorithm {
public:
    /**
     * Wierzchołek grafu
     */
    struct vertex {
        ushort parent;
        ushort key;
    };

    /**
     * Funktor porównujący wierzchołki
     */
    struct compare {
        bool operator()(vertex const& a, vertex const& b) {
            return a.key > b.key;
        }
    };

    void run(graph& graph, ushort start, bool print) override;
private:
    /**
     * Znajduje wierzchołek o najmniejszym kluczu
     *
     * @param key tablica kluczy
     * @param in_mst tablica wierzchołków w MST
     * @param vertices liczba wierzchołków
     * @return wierzchołek o najmniejszym kluczu
     */
    [[nodiscard]]
    ushort min_key(int* key, ushort* in_mst, ushort vertices);
};


#endif //AIZO_GRAPHS_PRIM_ALGORITHM_H

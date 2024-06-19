

#ifndef AIZO_GRAPHS_KRUSKAL_ALGORITHM_H
#define AIZO_GRAPHS_KRUSKAL_ALGORITHM_H


#include "../algorithm.h"

class kruskal_algorithm : public algorithm {
public:
    /**
     * Krawędź grafu
     */
    struct edge {
        ushort src;
        ushort dest;
        int weight;
    };

    void run(graph& graph, ushort start, bool print) override;

private:
    /**
     * Znajduje zbiór wierzchołka
     *
     * @param parent tablica z rodzicami
     * @param i wierzchołek
     * @return zbiór wierzchołka
     */
    [[nodiscard]]
    ushort find(ushort* parent, ushort i);
    /**
     * Łączy zbiory wierzchołków
     *
     * @param parent tablica z rodzicami
     * @param x wierzchołek x
     * @param y wierzchołek y
     */
    void union_set(ushort* parent, ushort x, ushort y);
};


#endif //AIZO_GRAPHS_KRUSKAL_ALGORITHM_H

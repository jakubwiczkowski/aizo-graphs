

#ifndef AIZO_GRAPHS_KRUSKAL_ALGORITHM_H
#define AIZO_GRAPHS_KRUSKAL_ALGORITHM_H


#include "../algorithm.h"
#include "kruskal_result.h"

class kruskal_algorithm : public algorithm<kruskal_result> {
public:
    kruskal_result run(graph& graph, ushort start) override;

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

    static void sort_edges(list<edge_kruskal>& edge_list);
    static void quick_sort(list<edge_kruskal>& edge_list, int low, int high);
    static int partition(list<edge_kruskal>& edge_list, int low, int high);
};


#endif //AIZO_GRAPHS_KRUSKAL_ALGORITHM_H



#ifndef AIZO_GRAPHS_DIJKSTRA_ALGORITHM_H
#define AIZO_GRAPHS_DIJKSTRA_ALGORITHM_H


#include "../algorithm.h"

class dijkstra_algorithm : public algorithm {
public:
    void run(graph& graph, ushort start, bool print) override;

private:
    /**
     * Znajduje wierzchołek o najmniejszym dystansie
     *
     * @param dist tablica dystansów
     * @param visited tablica odwiedzonych wierzchołków
     * @param vertices liczba wierzchołków
     * @return wierzchołek o najmniejszym dystansie
     */
    [[nodiscard]]
    ushort min_distance(ushort* dist, bool* visited, ushort vertices);
};


#endif //AIZO_GRAPHS_DIJKSTRA_ALGORITHM_H



#ifndef AIZO_GRAPHS_MATRIX_GRAPH_H
#define AIZO_GRAPHS_MATRIX_GRAPH_H


#include "../graph.h"

class matrix_graph : public graph {
    // Macierz
    int** matrix;

    int current_edge = 0;
    bool is_directed = false;
public:
    matrix_graph(ushort vertices, double fill, bool is_directed = false);
    matrix_graph(ushort vertices, ulong edges, bool is_directed = false);
    ~matrix_graph();

    void add_edge(ushort u, ushort v, int weight) override;
    void remove_edge(ushort u, ushort v) override;

    [[nodiscard]] bool is_adjacent(ushort u, ushort v) override;
    [[nodiscard]] list<ushort> get_adjacent(ushort u) override;

    [[nodiscard]] int get_weight(ushort u, ushort v) override;

    void print() override;
};


#endif //AIZO_GRAPHS_MATRIX_GRAPH_H

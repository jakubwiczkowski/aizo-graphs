

#ifndef AIZO_GRAPHS_MATRIX_GRAPH_H
#define AIZO_GRAPHS_MATRIX_GRAPH_H


#include "../graph.h"

class matrix_graph : public graph {
    int** matrix;
public:
    matrix_graph(ushort vertices, double fill, bool is_directed = false);
    matrix_graph(ushort vertices, ushort edges);
    ~matrix_graph();

    void add_edge(ushort u, ushort v, int weight) override;
    void remove_edge(ushort u, ushort v) override;

    [[nodiscard]] bool is_adjacent(ushort u, ushort v) override;
    [[nodiscard]] std::vector<ushort> get_adjacent(ushort u) override;

    [[nodiscard]] int get_weight(ushort u, ushort v) override;

    void print() override;
};


#endif //AIZO_GRAPHS_MATRIX_GRAPH_H

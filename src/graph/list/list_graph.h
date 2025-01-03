

#ifndef AIZO_GRAPHS_LIST_GRAPH_H
#define AIZO_GRAPHS_LIST_GRAPH_H

#include "../graph.h"
#include "connection.h"
#include "../matrix/matrix_graph.h"

class list_graph : public graph {
    // Lista list sąsiedztwa
    list<connection>** adjacency_list;
public:
    list_graph(ushort vertices, ulong edges);
    list_graph(ushort vertices, double fill, bool is_directed = false);
    list_graph(matrix_graph& matrix_graph);

    ~list_graph();

    void add_edge(ushort u, ushort v, int weight) override;

    void remove_edge(ushort u, ushort v) override;

    [[nodiscard]] bool is_adjacent(ushort u, ushort v) override;
    [[nodiscard]] list<ushort> get_adjacent(ushort u) override;
    [[nodiscard]] int get_weight(ushort u, ushort v) override;

    void print() override;
};


#endif //AIZO_GRAPHS_LIST_GRAPH_H

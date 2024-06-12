

#ifndef AIZO_GRAPHS_MATRIX_GRAPH_H
#define AIZO_GRAPHS_MATRIX_GRAPH_H


#include "../graph.h"

class matrix_graph : public graph {
    int** matrix;
public:
    matrix_graph(ulong vertices, ulong edges);
    ~matrix_graph();

    void add_edge(ulong u, ulong v, int weight) override;
    void remove_edge(ulong u, ulong v) override;

    [[nodiscard]] bool is_adjacent(ulong u, ulong v) const override;
    [[nodiscard]] linked_list<ulong>* get_adjacent(ulong u) const override;

    [[nodiscard]] int get_weight(ulong u, ulong v) const override;

    void print() override;
};


#endif //AIZO_GRAPHS_MATRIX_GRAPH_H

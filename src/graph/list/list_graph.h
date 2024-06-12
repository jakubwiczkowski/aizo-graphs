

#ifndef AIZO_GRAPHS_LIST_GRAPH_H
#define AIZO_GRAPHS_LIST_GRAPH_H

#include "../graph.h"
#include "../../list/linked_list.h"
#include "connection.h"

class list_graph : public graph {
    linked_list<connection> **list;

public:
    list_graph(ulong vertices, ulong edges);

    ~list_graph();

    void add_edge(ulong u, ulong v, int weight) override;

    void remove_edge(ulong u, ulong v) override;

    [[nodiscard]] bool is_adjacent(ulong u, ulong v) const override;

    [[nodiscard]] linked_list<ulong> *get_adjacent(ulong u) const override;

    void print() override;
};


#endif //AIZO_GRAPHS_LIST_GRAPH_H

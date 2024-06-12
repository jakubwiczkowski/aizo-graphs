

#ifndef AIZO_GRAPHS_GRAPH_H
#define AIZO_GRAPHS_GRAPH_H

#include "../list/linked_list.h"

typedef unsigned long ulong;

class graph {
    ulong vertices;
    ulong edges;

public:
    graph(ulong vertices, ulong edges);
    graph(ulong vertices, double fill);

    virtual void add_edge(ulong u, ulong v, int weight);
    virtual void remove_edge(ulong u, ulong v);

    [[nodiscard]] ulong get_vertices() const;
    [[nodiscard]] ulong get_edges() const;

    [[nodiscard]] virtual bool is_adjacent(ulong u, ulong v) const;
    [[nodiscard]] virtual linked_list<ulong>* get_adjacent(ulong u) const;
    [[nodiscard]] virtual int get_weight(ulong u, ulong v) const;

    virtual void print();
};


#endif //AIZO_GRAPHS_GRAPH_H

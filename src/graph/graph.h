

#ifndef AIZO_GRAPHS_GRAPH_H
#define AIZO_GRAPHS_GRAPH_H

#include <vector>
#include "../list/linked_list.h"

typedef unsigned short ushort;

class graph {
    ushort vertices;
    ushort edges;

public:
    graph(ushort vertices, ushort edges);
    graph(ushort vertices, double fill, bool is_directed = false);

    virtual void add_edge(ushort u, ushort v, int weight);
    virtual void remove_edge(ushort u, ushort v);

    [[nodiscard]] ushort get_vertices() const;
    [[nodiscard]] ushort get_edges() const;

    [[nodiscard]] virtual bool is_adjacent(ushort u, ushort v);
    [[nodiscard]] virtual std::vector<ushort> get_adjacent(ushort u);
    [[nodiscard]] virtual int get_weight(ushort u, ushort v);

    virtual void print();
};


#endif //AIZO_GRAPHS_GRAPH_H

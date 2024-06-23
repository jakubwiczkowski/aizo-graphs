

#include "graph.h"

graph::graph(ushort vertices, ulong edges) {
    this->vertices = vertices;
    this->edges = edges;
}

graph::graph(ushort vertices, double fill, bool is_directed): graph(vertices, static_cast<ulong>(vertices * (vertices - 1) * fill / (is_directed ? 2 : 1))) {}

ulong graph::get_edges() const {
    return this->edges;
}

ushort graph::get_vertices() const {
    return this->vertices;
}

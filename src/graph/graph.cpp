

#include "graph.h"

graph::graph(ushort vertices, ushort edges) {
    this->vertices = vertices;
    this->edges = edges;
}

graph::graph(ushort vertices, double fill, bool is_directed): graph(vertices,static_cast<ushort>(vertices * (vertices - 1) * fill / (is_directed ? 2 : 1))) {}

ushort graph::get_edges() const {
    return this->edges;
}

ushort graph::get_vertices() const {
    return this->vertices;
}

std::vector<ushort> graph::get_adjacent(ushort u) {
    return this->adjacents[u];
}

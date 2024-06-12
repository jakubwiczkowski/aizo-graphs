

#include "graph.h"

graph::graph(ulong vertices, ulong edges) {
    this->vertices = vertices;
    this->edges = edges;
}

graph::graph(ulong vertices, double fill): graph(vertices, static_cast<ulong>(vertices * (vertices - 1) * fill / 2)) {}

bool graph::is_adjacent(ulong u, ulong v) const {
    return false;
}

ulong graph::get_edges() const {
    return this->edges;
}

ulong graph::get_vertices() const {
    return this->vertices;
}

void graph::remove_edge(ulong u, ulong v) {

}

void graph::add_edge(ulong u, ulong v, int weight) {

}

linked_list<ulong> *graph::get_adjacent(ulong u) const {
    return nullptr;
}

void graph::print() {

}

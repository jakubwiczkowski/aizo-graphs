

#include <iostream>
#include "list_graph.h"

list_graph::list_graph(ushort vertices, ulong edges) : graph(vertices, edges) {
    this->adjacency_list = new list<connection>*[vertices];

    for (int idx = 0; idx < vertices; idx++) {
        this->adjacency_list[idx] = new list<connection>();
    }
}

list_graph::list_graph(ushort vertices, double fill, bool is_directed) : graph(vertices, fill, is_directed) {

}

list_graph::list_graph(matrix_graph &matrix_graph) : list_graph(matrix_graph.get_vertices(), matrix_graph.get_edges()) {
    for (int i = 0; i < this->get_vertices(); i++) {
        for (int j = 0; j < this->get_vertices(); j++) {
            if (matrix_graph.is_adjacent(i, j)) {
                this->add_edge(i, j, matrix_graph.get_weight(i, j));
            }
        }
    }
}

list_graph::~list_graph() {
    for (int idx = 0; idx < this->get_vertices(); idx++) {
        delete this->adjacency_list[idx];
    }
    delete[] this->adjacency_list;
}

void list_graph::add_edge(ushort u, ushort v, int weight) {
    this->adjacency_list[u]->add({v, weight});
}

void list_graph::remove_edge(ushort u, ushort v) {
    int index = this->adjacency_list[u]->find_index({v, this->get_weight(u, v)});
    if (index == -1) return;

    this->adjacency_list[u]->remove(index);
}

bool list_graph::is_adjacent(ushort u, ushort v) {
    return this->get_weight(u, v) != 0;
}

list<ushort> list_graph::get_adjacent(ushort u) {
    list<ushort> adjacent;
    for (int idx = 0; idx < this->get_vertices(); idx++) {
        if (this->is_adjacent(u, idx)) {
            adjacent.add(idx);
        }
    }

    return adjacent;
}

void list_graph::print() {
    for (int i = 0; i < this->get_vertices(); i++) {
        std::cout << i << " -> ";
        this->adjacency_list[i]->print();
        std::cout << std::endl;
    }
}

int list_graph::get_weight(ushort u, ushort v) {
    for (int idx = 0; idx < this->adjacency_list[u]->size(); idx++) {
        if (this->adjacency_list[u]->get(idx).get_vertex() == v) {
            return this->adjacency_list[u]->get(idx).get_weight();
        }
    }
    return 0;
}



#include <iostream>
#include "list_graph.h"

list_graph::list_graph(ushort vertices, ushort edges) : graph(vertices, edges) {
    this->list = new linked_list<connection>*[vertices];

    for (int idx = 0; idx < vertices; idx++) {
        this->list[idx] = new linked_list<connection>();
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
        delete this->list[idx];
    }
    delete[] this->list;
}

void list_graph::add_edge(ushort u, ushort v, int weight) {
    this->list[u]->insert({v, weight});
}

void list_graph::remove_edge(ushort u, ushort v) {
    auto current = this->list[u]->get_head();
    while (current != nullptr) {
        if (current->get_key().get_vertex() == v) {
            this->list[u]->remove({v, current->get_key().get_weight()});
            break;
        }
        current = current->get_next();
    }

    current = this->list[v]->get_head();
    while (current != nullptr) {
        if (current->get_key().get_vertex() == u) {
            this->list[v]->remove({u, current->get_key().get_weight()});
            break;
        }
        current = current->get_next();
    }
}

bool list_graph::is_adjacent(ushort u, ushort v) {
    auto current = this->list[u]->get_head();
    while (current != nullptr) {
        if (current->get_key().get_vertex() == v) {
            return true;
        }
        current = current->get_next();
    }
    return false;
}

std::vector<ushort> list_graph::get_adjacent(ushort u) {
    std::vector<ushort> adjacent;
    auto current = this->list[u]->get_head();
    while (current != nullptr) {
        adjacent.emplace_back(current->get_key().get_vertex());
        current = current->get_next();
    }
    return adjacent;
}

void list_graph::print() {
    for (int i = 0; i < this->get_vertices(); i++) {
        std::cout << i << " -> ";
        this->list[i]->print();
        std::cout << std::endl;
    }
}

int list_graph::get_weight(ushort u, ushort v) {
    auto current = this->list[u]->get_head();
    while (current != nullptr) {
        if (current->get_key().get_vertex() == v) {
            return current->get_key().get_weight();
        }
        current = current->get_next();
    }
    return 0;
}

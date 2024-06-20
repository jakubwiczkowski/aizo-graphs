

#include <iostream>
#include "list_graph.h"

list_graph::list_graph(ushort vertices, ushort edges) : graph(vertices, edges) {
    this->adjacency_list = new list<connection>*[vertices];

    for (int idx = 0; idx < vertices; idx++) {
        this->adjacency_list[idx] = new list<connection>();
    }

    this->adjacents = new list<ushort>[vertices];
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
    delete[] this->adjacents;
}

void list_graph::add_edge(ushort u, ushort v, int weight) {
    this->adjacency_list[u]->add({v, weight});
    this->adjacents[u].add(v);
}

void list_graph::remove_edge(ushort u, ushort v) {
    int index = this->adjacency_list[u]->find_index({v, this->get_weight(u, v)});
    if (index == -1) return;

    this->adjacency_list[u]->remove(index);
//    auto current = this->adjacency_list[u]->get_head();
//    while (current != nullptr) {
//        if (current->get_key().get_vertex() == v) {
//            this->list[u]->remove({v, current->get_key().get_weight()});
//            break;
//        }
//        current = current->get_next();
//    }
//
//    current = this->list[v]->get_head();
//    while (current != nullptr) {
//        if (current->get_key().get_vertex() == u) {
//            this->list[v]->remove({u, current->get_key().get_weight()});
//            break;
//        }
//        current = current->get_next();
//    }
}

bool list_graph::is_adjacent(ushort u, ushort v) {
    return this->get_weight(u, v) != 0;
//    auto current = this->list[u]->get_head();
//    while (current != nullptr) {
//        if (current->get_key().get_vertex() == v) {
//            return true;
//        }
//        current = current->get_next();
//    }
//    return false;
}

list<ushort> list_graph::get_adjacent(ushort u) {
//    list<ushort> adjacent;
//    for (int idx = 0; idx < this->get_vertices(); idx++) {
//        if (this->is_adjacent(u, idx)) {
//            adjacent.add(idx);
//        }
//    }

    //    auto current = this->list[u]->get_head();
//    while (current != nullptr) {
//        adjacent.emplace_back(current->get_key().get_vertex());
//        current = current->get_next();
//    }
    return this->adjacents[u];
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

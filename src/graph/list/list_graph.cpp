

#include <iostream>
#include "list_graph.h"

list_graph::list_graph(ulong vertices, ulong edges) : graph(vertices, edges) {
    this->list = new linked_list<connection>*[vertices];

    for (int idx = 0; idx < vertices; idx++) {
        this->list[idx] = new linked_list<connection>();
    }
}

list_graph::~list_graph() {
    for (int idx = 0; idx < this->get_vertices(); idx++) {
        delete this->list[idx];
    }
    delete[] this->list;
}

void list_graph::add_edge(ulong u, ulong v, int weight) {
    this->list[u]->insert({v, weight});
//    this->list[v]->insert({u, weight});
}

void list_graph::remove_edge(ulong u, ulong v) {
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

bool list_graph::is_adjacent(ulong u, ulong v) const {
    auto current = this->list[u]->get_head();
    while (current != nullptr) {
        if (current->get_key().get_vertex() == v) {
            return true;
        }
        current = current->get_next();
    }
    return false;
}

linked_list<ulong> *list_graph::get_adjacent(ulong u) const {
    auto* adjacent = new linked_list<ulong>();
    auto current = this->list[u]->get_head();
    while (current != nullptr) {
        adjacent->insert(current->get_key().get_vertex());
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

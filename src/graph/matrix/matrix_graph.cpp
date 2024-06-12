
#include<iostream>
#include "matrix_graph.h"

matrix_graph::matrix_graph(ulong vertices, ulong edges) : graph(vertices, edges) {
    this->matrix = new int*[vertices];
    for (int idx = 0; idx < vertices; idx++) {
        this->matrix[idx] = new int[vertices];
    }

    // edge initialization
}

matrix_graph::~matrix_graph() {
    for (int idx = 0; idx < this->get_vertices(); idx++) {
        delete[] this->matrix[idx];
    }
    delete[] this->matrix;
}

void matrix_graph::print() {
    for (int i = 0; i < this->get_vertices(); i++) {
        for (int j = 0; j < this->get_vertices(); j++) {
            std::cout << this->matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void matrix_graph::add_edge(ulong u, ulong v, int weight) {
    this->matrix[u][v] = weight;
}

void matrix_graph::remove_edge(ulong u, ulong v) {
    this->matrix[u][v] = 0;
}

bool matrix_graph::is_adjacent(ulong u, ulong v) const {
    return this->matrix[u][v] != 0;
}

linked_list<ulong> *matrix_graph::get_adjacent(ulong u) const {
    auto* list = new linked_list<ulong>();
    for (int idx = 0; idx < this->get_vertices(); idx++) {
        if (this->matrix[u][idx] != 0) {
            list->insert(idx);
        }
    }
    return list;
}

int matrix_graph::get_weight(ulong u, ulong v) const {
    return this->matrix[u][v];
}

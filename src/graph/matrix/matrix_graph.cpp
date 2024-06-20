
#include<iostream>
#include <algorithm>
#include <random>
#include "matrix_graph.h"

matrix_graph::matrix_graph(ushort vertices, ushort edges) : graph(vertices, edges) {
    this->matrix = new int*[vertices];
    for (int idx = 0; idx < vertices; idx++) {
        this->matrix[idx] = new int[vertices];
        for (int jdx = 0; jdx < vertices; jdx++) {
            this->matrix[idx][jdx] = 0;
        }
    }
    this->adjacents = new list<ushort>[vertices];
}

matrix_graph::matrix_graph(ushort vertices, double fill, bool is_directed) : matrix_graph(vertices,static_cast<ushort>(vertices * (vertices - 1) * fill / (!is_directed ? 2 : 1))) {
    ushort added_edges = 0;
    static std::random_device r;
    static std::default_random_engine e1(r());
    static std::uniform_int_distribution<int> uniform_dist_weight(1, 20);

    list<pair<ushort, ushort>> possible_edges;
    for (ushort i = 0; i < this->get_vertices(); ++i) {
        for (ushort j = 0; j < this->get_vertices(); ++j) {
            if (i != j) {
                possible_edges.add(pair(i, j));
            }
        }
    }

    // MST
    for (ushort i = 1; i < this->get_vertices(); ++i) {
        int weight = uniform_dist_weight(e1);
        this->add_edge(i - 1, i, weight);
        possible_edges.remove(possible_edges.find_index(pair((ushort) (i - 1), i)));
        if (!is_directed) {
            this->add_edge(i, i - 1, weight);
            possible_edges.remove(possible_edges.find_index(pair(i, (ushort) (i - 1))));
            added_edges++;
        }
        added_edges++;
    }

    while(added_edges < this->get_edges()) {
        std::uniform_int_distribution<ushort> uniform_dist(0, possible_edges.size() - 1);

        ushort idx = uniform_dist(e1);

        ushort u = possible_edges[idx].first;
        ushort v = possible_edges[idx].second;

        if (u != v) {
            int weight = uniform_dist_weight(e1);
            this->add_edge(u, v, weight);
            possible_edges.remove(possible_edges.find_index(pair(u, v)));
            if (!is_directed) {
                this->add_edge(v, u, weight);
                possible_edges.remove(possible_edges.find_index(pair(v, u)));
                added_edges++;
            }
            added_edges++;
        }
    }
}

matrix_graph::~matrix_graph() {
    for (int idx = 0; idx < this->get_vertices(); idx++) {
        delete[] this->matrix[idx];
    }
    delete[] this->matrix;
    delete[] this->adjacents;
}

void matrix_graph::print() {
    for (int i = 0; i < this->get_vertices(); i++) {
        for (int j = 0; j < this->get_vertices(); j++) {
            std::cout << this->matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void matrix_graph::add_edge(ushort u, ushort v, int weight) {
    this->matrix[u][v] = weight;
    this->adjacents[u].add(v);
}

void matrix_graph::remove_edge(ushort u, ushort v) {
    this->matrix[u][v] = 0;
}

bool matrix_graph::is_adjacent(ushort u, ushort v) {
    return this->matrix[u][v] != 0;
}

list<ushort> matrix_graph::get_adjacent(ushort u) {
//    list<ushort> adjacent;
//    for (int idx = 0; idx < this->get_vertices(); idx++) {
//        if (this->matrix[u][idx] != 0) {
//            adjacent.add(idx);
//        }
//    }
    return this->adjacents[u];
}

int matrix_graph::get_weight(ushort u, ushort v) {
    return this->matrix[u][v];
}

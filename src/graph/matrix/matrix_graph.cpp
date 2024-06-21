#include <iostream>
#include <algorithm>
#include <random>
#include <iomanip>
#include "matrix_graph.h"

matrix_graph::matrix_graph(ushort vertices, ushort edges, bool is_directed) : graph(vertices, edges) {
    this->matrix = new int*[vertices];
    for (int idx = 0; idx < vertices; idx++) {
        this->matrix[idx] = new int[edges];
        for (int jdx = 0; jdx < edges; jdx++) {
            this->matrix[idx][jdx] = 0;
        }
    }
    this->adjacents = new list<ushort>[vertices];
    this->is_directed = is_directed;
}

matrix_graph::matrix_graph(ushort vertices, double fill, bool is_directed) : matrix_graph(vertices,static_cast<ushort>(vertices * (vertices - 1) * fill / (is_directed ? 1 : 2)), is_directed) {
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
            possible_edges.remove(possible_edges.find_index(pair(i, (ushort) (i - 1))));
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
                possible_edges.remove(possible_edges.find_index(pair(v, u)));
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
    std::cout << "    v" << std::endl;
    for (int i = 0; i < this->get_vertices(); i++) {
        std::cout << std::setw(5) << i << " | ";
        for (int j = 0; j < this->get_edges(); j++) {
            std::cout << std::setw(3) << this->matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void matrix_graph::add_edge(ushort u, ushort v, int weight) {
    if (this->is_directed) {
        this->matrix[u][this->current_edge] = -weight;
        this->matrix[v][this->current_edge] = weight;
        this->adjacents[u].add(v);
    } else {
        this->matrix[u][this->current_edge] = weight;
        this->matrix[v][this->current_edge] = weight;
        this->adjacents[u].add(v);
        this->adjacents[v].add(u);
    }
    this->current_edge++;
}

void matrix_graph::remove_edge(ushort u, ushort v) {
//    this->matrix[u][v] = 0;
}

bool matrix_graph::is_adjacent(ushort u, ushort v) {
    if (u == v) return false;

    for (int idx = 0; idx < this->get_edges(); idx++) {
        if (this->matrix[u][idx] == 0 || this->matrix[v][idx] == 0)
            continue;

        if (this->is_directed) {
            bool starts_at_u = this->matrix[u][idx] < 0;

            if (!starts_at_u) continue;

            return true;
        } else {
            return true;
        }
    }
    return false;
}

list<ushort> matrix_graph::get_adjacent(ushort u) {
    return this->adjacents[u];
}

int matrix_graph::get_weight(ushort u, ushort v) {
    if (u == v) return 0;

    for (int idx = 0; idx < this->get_edges(); idx++) {
        if (this->matrix[u][idx] == 0 || this->matrix[v][idx] == 0)
            continue;

        if (this->is_directed) {
            bool starts_at_u = this->matrix[u][idx] < 0;

            if (!starts_at_u) {
                continue;
            }

            return this->matrix[u][idx] < 0 ? -this->matrix[u][idx] : this->matrix[u][idx];
        } else {
            return this->matrix[u][idx];
        }
    }
    return 0;
}

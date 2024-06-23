#ifndef AIZO_GRAPHS_VERTEX_DIJKSTRA_H
#define AIZO_GRAPHS_VERTEX_DIJKSTRA_H

#include <cstdlib>
#include <ostream>

/**
 * Wierzchołek grafu dla algorytmu Dijkstry.
 */
struct vertex_dijkstra {
    ushort idx;
    int distance;

    bool operator<(const vertex_dijkstra& other) const {
        return distance < other.distance;
    }

    bool operator>(const vertex_dijkstra& other) const {
        return distance > other.distance;
    }

    bool operator==(const vertex_dijkstra& other) const {
        return distance == other.distance && idx == other.idx;
    }

    friend auto operator<<(std::ostream& os, vertex_dijkstra const& vertex) -> std::ostream& {
        return os << "(" << vertex.idx << ", " << vertex.distance << ")";
    }
};

#endif //AIZO_GRAPHS_VERTEX_DIJKSTRA_H

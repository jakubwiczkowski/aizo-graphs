

#ifndef AIZO_GRAPHS_VERTEX_PRIM_H
#define AIZO_GRAPHS_VERTEX_PRIM_H

#include <cstdlib>

/**
 * Wierzchołek grafu używany w algorytmie Prima.
 */
struct vertex_prim {
    ushort idx;
    int key;

    bool operator<(const vertex_prim& other) const {
        return key < other.key;
    }

    bool operator>(const vertex_prim& other) const {
        return key > other.key;
    }

    bool operator==(const vertex_prim& other) const {
        return key == other.key && idx == other.idx;
    }

    friend auto operator<<(std::ostream& os, vertex_prim const& vertex) -> std::ostream& {
        return os << "(" << vertex.idx << ", " << vertex.key << ")";
    }
};

#endif //AIZO_GRAPHS_VERTEX_PRIM_H

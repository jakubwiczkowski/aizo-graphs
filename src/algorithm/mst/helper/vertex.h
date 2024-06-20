

#ifndef AIZO_GRAPHS_VERTEX_H
#define AIZO_GRAPHS_VERTEX_H

#include <cstdlib>

/**
 * Wierzchołek grafu
 */
struct vertex {
    ushort idx;
    int key;

    bool operator<(const vertex& other) const {
        return key < other.key;
    }

    bool operator>(const vertex& other) const {
        return key > other.key;
    }

    bool operator==(const vertex& other) const {
        return key == other.key && idx == other.idx;
    }

    friend auto operator<<(std::ostream& os, vertex const& vertex) -> std::ostream& {
        return os << "(" << vertex.idx << ", " << vertex.key << ")";
    }
};

#endif //AIZO_GRAPHS_VERTEX_H

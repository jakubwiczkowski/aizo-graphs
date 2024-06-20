

#ifndef AIZO_GRAPHS_EDGE_H
#define AIZO_GRAPHS_EDGE_H

#include <cstdlib>
#include <ostream>

struct edge {
    ushort src;
    ushort dest;
    int weight;

    bool operator==(const edge& other) const {
        return src == other.src && dest == other.dest && weight == other.weight;
    }

    friend auto operator<<(std::ostream& os, edge const& edge) -> std::ostream& {
        return os << "(" << edge.src << ", " << edge.dest << ", " << edge.weight << ")";
    }
};

#endif //AIZO_GRAPHS_EDGE_H

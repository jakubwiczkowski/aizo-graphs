

#ifndef AIZO_GRAPHS_EDGE_KRUSKAL_H
#define AIZO_GRAPHS_EDGE_KRUSKAL_H

#include <cstdlib>
#include <ostream>

struct edge_kruskal {
    ushort src;
    ushort dest;
    int weight;

    bool operator<(const edge_kruskal& other) const {
        return weight < other.weight;
    }

    bool operator>(const edge_kruskal& other) const {
        return weight > other.weight;
    }

    bool operator==(const edge_kruskal& other) const {
        return src == other.src && dest == other.dest && weight == other.weight;
    }

    friend auto operator<<(std::ostream& os, edge_kruskal const& edge) -> std::ostream& {
        return os << "(" << edge.src << ", " << edge.dest << ", " << edge.weight << ")";
    }
};

#endif //AIZO_GRAPHS_EDGE_KRUSKAL_H

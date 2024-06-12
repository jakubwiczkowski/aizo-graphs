

#ifndef AIZO_GRAPHS_CONNECTION_H
#define AIZO_GRAPHS_CONNECTION_H


#include <ostream>

class connection {
    unsigned long vertex = -1;
    int weight = 0;

public:
    connection() = default;
    connection(unsigned long vertex, int weight) : vertex(vertex), weight(weight) {}

    [[nodiscard]] unsigned long get_vertex() const { return vertex; }
    [[nodiscard]] int get_weight() const { return weight; }

    friend auto operator<<(std::ostream& os, connection const& conn) -> std::ostream& {
        return os << "(" << conn.vertex << ", " << conn.weight << ")";
    }

    friend auto operator==(connection const &lhs, connection const &rhs) -> bool {
        return lhs.get_vertex() == rhs.get_vertex() && lhs.get_weight() == rhs.get_weight();
    }
};

#endif //AIZO_GRAPHS_CONNECTION_H

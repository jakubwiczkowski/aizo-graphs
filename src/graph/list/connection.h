

#ifndef AIZO_GRAPHS_CONNECTION_H
#define AIZO_GRAPHS_CONNECTION_H


#include <ostream>

class connection {
    unsigned long vertex = -1; // wierzchołek
    int weight = 0;            // waga krawędzi

public:
    connection() = default;
    connection(unsigned long vertex, int weight) : vertex(vertex), weight(weight) {}

    /**
     * Zwraca wierzchołek
     *
     * @return wierzchołek
     */
    [[nodiscard]] unsigned long get_vertex() const { return vertex; }
    /**
     * Zwraca wagę krawędzi
     *
     * @return waga krawędzi
     */
    [[nodiscard]] int get_weight() const { return weight; }

    /**
     * Przeciążony operator wypisywania na strumień
     *
     * @param os strumień wyjściowy
     * @param conn połączenie
     * @return strumień wyjściowy
     */
    friend auto operator<<(std::ostream& os, connection const& conn) -> std::ostream& {
        return os << "(" << conn.vertex << ", " << conn.weight << ")";
    }

    /**
     * Przeciążony operator porównania
     *
     * @param lhs lewa strona
     * @param rhs prawa strona
     * @return czy są równe
     */
    friend auto operator==(connection const &lhs, connection const &rhs) -> bool {
        return lhs.get_vertex() == rhs.get_vertex() && lhs.get_weight() == rhs.get_weight();
    }
};

#endif //AIZO_GRAPHS_CONNECTION_H

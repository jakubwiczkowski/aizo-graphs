

#ifndef AIZO_GRAPHS_GRAPH_H
#define AIZO_GRAPHS_GRAPH_H

#include <vector>
#include "../list/linked_list.h"

typedef unsigned short ushort;

/**
 * Klasa abstrakcyjna reprezentująca graf
 */
class graph {
    ushort vertices; // liczba wierzchołków
    ushort edges;    // liczba krawędzi

public:
    graph(ushort vertices, ushort edges);
    graph(ushort vertices, double fill, bool is_directed = false);

    /**
     * Dodaje krawędź między wierzchołkami u i v o wadze weight
     *
     * @param u pierwszy wierzchołek
     * @param v drugi wierzchołek
     * @param weight waga krawędzi
     */
    virtual void add_edge(ushort u, ushort v, int weight) = 0;
    /**
     * Usuwa krawędź między wierzchołkami u i v
     *
     * @param u pierwszy wierzchołek
     * @param v drugi wierzchołek
     */
    virtual void remove_edge(ushort u, ushort v) = 0;

    [[nodiscard]] ushort get_vertices() const;
    [[nodiscard]] ushort get_edges() const;

    /**
     * Sprawdza czy wierzchołki u i v są sąsiednie
     *
     * @param u pierwszy wierzchołek
     * @param v drugi wierzchołek
     * @return czy wierzchołki są sąsiednie
     */
    [[nodiscard]] virtual bool is_adjacent(ushort u, ushort v) = 0;
    /**
     * Zwraca listę sąsiednich wierzchołków wierzchołka u
     *
     * @param u wierzchołek
     * @return lista sąsiednich wierzchołków
     */
    [[nodiscard]] virtual std::vector<ushort> get_adjacent(ushort u) = 0;
    /**
     * Zwraca wagę krawędzi między wierzchołkami u i v
     *
     * @param u pierwszy wierzchołek
     * @param v drugi wierzchołek
     * @return wartość wagi krawędzi
     */
    [[nodiscard]] virtual int get_weight(ushort u, ushort v) = 0;

    /**
     * Wypisuje graf do konsoli
     */
    virtual void print() = 0;
};


#endif //AIZO_GRAPHS_GRAPH_H

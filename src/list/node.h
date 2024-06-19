

#ifndef AIZO_GRAPHS_NODE_H
#define AIZO_GRAPHS_NODE_H

#include "../graph/list/connection.h"
#include "pair.h"

template<class T>
class node {
    T key;                // klucz
    node* next = nullptr; // wskaźnik na następny element
public:
    explicit node(T key);

    /**
     * Zwraca klucz
     *
     * @return klucz
     */
    [[nodiscard]] T get_key() const;
    /**
     * Zwra wskaźnik na następny element
     *
     * @return wskaźnik na następny element
     */
    node* get_next();
    /**
     * Ustawia wskaźnik na następny element
     *
     * @param next wskaźnik na następny element
     */
    void set_next(node* next);
};

template class node<int>;
template class node<unsigned long>;
template class node<connection>;
template class node<pair<ushort, ushort>>;

#endif //AIZO_GRAPHS_NODE_H

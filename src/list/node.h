

#ifndef AIZO_GRAPHS_NODE_H
#define AIZO_GRAPHS_NODE_H

#include "../graph/list/connection.h"
#include "pair.h"

template<class T>
class node {
    T key;
    node* next = nullptr;
public:
    explicit node(T key);

    [[nodiscard]] T get_key() const;
    node* get_next();
    void set_next(node* next);
};

template class node<int>;
template class node<unsigned long>;
template class node<connection>;
template class node<pair<ushort, ushort>>;

#endif //AIZO_GRAPHS_NODE_H

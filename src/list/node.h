

#ifndef AIZO_GRAPHS_NODE_H
#define AIZO_GRAPHS_NODE_H

#include "../graph/list/connection.h"

template<class T>
class node {
    T key;
    node* next = nullptr;
    node* previous = nullptr;

public:
    explicit node(T key);

    [[nodiscard]] T get_key() const;
    node* get_next();
    node* get_previous();
    void set_next(node* next);
    void set_previous(node* previous);
};

template class node<int>;
template class node<unsigned long>;
template class node<connection>;

#endif //AIZO_GRAPHS_NODE_H

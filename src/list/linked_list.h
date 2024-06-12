

#ifndef AIZO_GRAPHS_LINKED_LIST_H
#define AIZO_GRAPHS_LINKED_LIST_H

#include "node.h"

template<class T>
class linked_list {
    node<T>* head;

public:
    linked_list();
    ~linked_list();

    node<T>* get_head();

    void insert(T key);
    void remove(T key);

    void print();
};

template class linked_list<int>;
template class linked_list<unsigned long>;
template class linked_list<connection>;

#endif //AIZO_GRAPHS_LINKED_LIST_H

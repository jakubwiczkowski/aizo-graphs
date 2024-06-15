

#ifndef AIZO_GRAPHS_LINKED_LIST_H
#define AIZO_GRAPHS_LINKED_LIST_H

#include "node.h"

template<class T>
class linked_list {
    node<T>* head;
    ulong size;

public:
    linked_list();
    ~linked_list();

    node<T>* get_head();

    void insert(T key);
    void remove(T key);

    ulong get_size();
    node<T>* get(ulong index);

    void print();
};

template class linked_list<int>;
template class linked_list<unsigned long>;
template class linked_list<connection>;

#endif //AIZO_GRAPHS_LINKED_LIST_H

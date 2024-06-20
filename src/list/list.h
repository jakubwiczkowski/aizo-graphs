#ifndef AIZO_GRAPHS_LIST_H
#define AIZO_GRAPHS_LIST_H


#include <iostream>
#include "pair.h"
#include "../graph/list/connection.h"
#include "../algorithm/mst/helper/vertex_prim.h"
#include "../algorithm/mst/helper/edge_kruskal.h"
#include "../algorithm/shortest/helper/vertex_dijkstra.h"

template<typename T>
class list {
    T *array;
    int capacity = 10;
    int current = 0;

public:
    list();
    list(const list<T> &other);
    ~list();

    int size();

    virtual void add(T element);
    virtual T &get(int index);
    virtual void remove(int index);

    int find_index(T element);
    void swap(int first, int second);

    void print();

    T operator[](int idx) { return this->get(idx); }
};

template class list<int>;
template class list<ushort>;
template class list<pair<ushort, ushort>>;
template class list<connection>;
template class list<vertex_prim>;
template class list<vertex_dijkstra>;
template class list<edge_kruskal>;

#endif //AIZO_GRAPHS_LIST_H

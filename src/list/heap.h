

#ifndef AIZO_GRAPHS_HEAP_H
#define AIZO_GRAPHS_HEAP_H

#include "list.h"
#include "../algorithm/shortest/helper/vertex_dijkstra.h"

template<typename T>
class heap : public list<T> {
public:
    heap() : list<T>() {}
    heap(const heap<T>& other) : list<T>(other) {}

    ~heap() = default;

    void add(T element) override;
    void remove(int index) override;

    void create_heap();
    void sift_down(int root, int end);

    static int index_parent(int index);
    static int index_left_child(int index);
    static int index_right_child(int index);
};

template class heap<vertex_prim>;
template class heap<vertex_dijkstra>;

#endif //AIZO_GRAPHS_HEAP_H

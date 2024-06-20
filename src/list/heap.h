

#ifndef AIZO_GRAPHS_HEAP_H
#define AIZO_GRAPHS_HEAP_H

#include "list.h"

template<typename T>
class heap : public list<T> {
public:
    heap() : list<T>() {}
    heap(const heap<T>& other) : list<T>(other) {}

    ~heap() = default;

    void add(T element) override;
    void remove(int index) override;

    static int index_parent(int index);
    static int index_left_child(int index);
    static int index_right_child(int index);

    void create_heap();
    void sift_down(int root, int end);
};

template class heap<vertex>;

#endif //AIZO_GRAPHS_HEAP_H

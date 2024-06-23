

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

    /**
     * Dodaje element do kopca minimalnego
     *
     * @param element element do dodania
     */
    void add(T element) override;
    /**
     * Usuwa element o danym indeksie z kopca minimalnego
     *
     * @param index indeks elementu do usunięcia
     */
    void remove(int index) override;

    /**
     * Tworzy kopiec minimalny
     */
    void create_heap();
    /**
     * Naprawia kopiec w dół
     *
     * @param root indeks korzenia kopca
     * @param end  indeks do którego kopiec ma być naprawiany
     */
    void sift_down(int root, int end);

    static int index_parent(int index);
    static int index_left_child(int index);
    static int index_right_child(int index);
};

template class heap<vertex_prim>;
template class heap<vertex_dijkstra>;

#endif //AIZO_GRAPHS_HEAP_H

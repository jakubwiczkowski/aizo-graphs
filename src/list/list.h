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

    /**
     * Zwraca ilość elementów listy
     *
     * @return ilość elementów listy
     */
    int size();

    /**
     * Dodaje element do listy
     *
     * @param element element do dodania
     */
    virtual void add(T element);
    /**
     * Zwraca referencje do obiektu w liście pod danym ideksem
     *
     * @param index indeks elementu
     * @return referencja do obiektu danego elementu
     */
    virtual T &get(int index);
    /**
     * Usuwa element pod danym indeksem
     *
     * @param index indeks elementu do usunięcia
     */
    virtual void remove(int index);

    /**
     * Ustawia dany element na podanym indeksie.
     *
     * @param index   indeks do wstawiania elementu
     * @param element element do wstawienia
     */
    void set(int index, T element);

    /**
     * Znajduje indeks danego elementu
     *
     * @param element element, którego indeks chcemy znaleźć
     * @return indeks elementu
     */
    int find_index(T element);
    /**
     * Zamienia elementy miejscem
     *
     * @param first  miejsce pierwszego elementu
     * @param second miejsce drugiego elementu
     */
    void swap(int first, int second);

    /**
     * Wypisuje zawartość listy
     */
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



#ifndef AIZO_GRAPHS_LINKED_LIST_H
#define AIZO_GRAPHS_LINKED_LIST_H

#include "node.h"

template<class T>
class linked_list {
    node<T>* head;    // wskaźnik na głowę listy
    ushort size = 0;  // rozmiar listy

public:
    linked_list();
    ~linked_list();

    /**
     * Zwraca wskaźnik na głowę listy
     *
     * @return wskaźnik na głowę listy
     */
    node<T>* get_head();

    /**
     * Dodaje element do listy
     *
     * @param key element do dodania
     */
    void insert(T key);
    /**
     * Usuwa element z listy
     *
     * @param key element do usunięcia
     */
    void remove(T key);

    /**
     * Zwraca rozmiar listy
     *
     * @return rozmiar listy
     */
    ushort get_size();
    /**
     * Zwraca wskaźnik na element o podanym indeksie
     *
     * @param index indeks elementu
     * @return wskaźnik na element
     */
    node<T>* get(ushort index);

    /**
     * Wypisuje listę
     */
    void print();
};

template class linked_list<int>;
template class linked_list<unsigned long>;
template class linked_list<connection>;
template class linked_list<pair<ushort, ushort>>;

#endif //AIZO_GRAPHS_LINKED_LIST_H

#include "node.h"

template<class T>
node<T>::node(T key) {
    this->key = key;
}

template<class T>
T node<T>::get_key() const {
    return this->key;
}

template<class T>
node<T> *node<T>::get_next() {
    return this->next;
}

template<class T>
void node<T>::set_next(node<T>* next) {
    this->next = next;
}

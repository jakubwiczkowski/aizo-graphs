
#include<iostream>
#include "linked_list.h"

template<class T>
linked_list<T>::linked_list() {
    head = nullptr;
}

template<class T>
linked_list<T>::~linked_list() {
    node<T>* current = head;
    while (current != nullptr) {
        node<T>* next = current->get_next();
        delete current;
        current = next;
    }
}

template<class T>
node<T>* linked_list<T>::get_head() {
    return this->head;
}

template<class T>
void linked_list<T>::insert(T key) {
    auto* new_node = new node<T>(key);
    new_node->set_next(head);
    head = new_node;
}

template<class T>
void linked_list<T>::remove(T key) {
    node<T>* current = head;
    node<T>* previous = nullptr;
    while (current != nullptr) {
        if (current->get_key() == key) {
            if (previous == nullptr) {
                head = current->get_next();
            } else {
                previous->set_next(current->get_next());
            }
            delete current;
            return;
        }
        previous = current;
        current = current->get_next();
    }
}

template<class T>
ulong linked_list<T>::get_size() {
    ulong size = 0;
    node<T>* current = head;
    while (current != nullptr) {
        size++;
        current = current->get_next();
    }
    return size;
}

template<class T>
node<T> *linked_list<T>::get(ulong index) {
    node<T>* current = head;
    ulong i = 0;
    while (current != nullptr) {
        if (i == index) {
            return current;
        }
        i++;
        current = current->get_next();
    }
    return nullptr;
}

template<class T>
void linked_list<T>::print() {
    node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->get_key();
        current = current->get_next();

        if (current != nullptr) {
            std::cout << ", ";
        }
    }
}

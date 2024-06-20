

#include "heap.h"


template<typename T>
void heap<T>::remove(int index) {
    list<T>::remove(index);
    create_heap();
}

template<typename T>
void heap<T>::add(T element) {
    list<T>::add(element);
    create_heap();
}

template<typename T>
void heap<T>::create_heap() {
    int start = index_parent(list<T>::size() - 1) + 1;

    while (start > 0) {
        --start;

        sift_down(start, list<T>::size());
    }
}

template<typename T>
void heap<T>::sift_down(int root, int end) {
    while (index_left_child(root) < end) {
        int child = index_left_child(root);

        if (child + 1 < end &&
            list<T>::get(child) > list<T>::get(child + 1)) {
            ++child;
        }

        if (list<T>::get(root) > list<T>::get(child)) {
            list<T>::swap(root, child);
            root = child;
        } else {
            return;
        }
    }
}

template<typename T>
int heap<T>::index_parent(int index) {
    return (index - 1) / 2;
}

template<typename T>
int heap<T>::index_right_child(int index) {
    return 2 * index + 2;
}

template<typename T>
int heap<T>::index_left_child(int index) {
    return 2 * index + 1;
}

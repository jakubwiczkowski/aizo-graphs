

#include "list.h"

template<typename T>
list<T>::list() {
    this->capacity = 10;
    this->current = 0;
    this->array = new T[this->capacity];
}

template<typename T>
list<T>::list(const list<T> &other) {
    this->capacity = other.capacity;
    this->current = other.current;
    this->array = new T[this->capacity];

//    other.array == nullptr;
    for (int i = 0; i < this->current; i++) {
        this->array[i] = other.array[i];
    }
}

template<typename T>
list<T>::~list() {
//    if (this->array == nullptr)
//        return;
    delete[] this->array;
}

template<typename T>
void list<T>::add(T element) {
    if (this->current == this->capacity) {
        T* temp = new T[2 * this->capacity];

        for (int i = 0; i < this->capacity; i++) {
            temp[i] = this->array[i];
        }

        delete[] this->array;
        this->capacity *= 2;
        this->array = temp;
    }

    this->array[this->current] = element;
    this->current++;
}

template<typename T>
T& list<T>::get(int index) {
    return this->array[index];
}

template<typename T>
void list<T>::set(int index, T element) {
    if (index >= 0 && index < this->current) {
        this->array[index] = element;
    }
}

//template<typename T>
//void list<T>::remove(T element) {
//    for (int i = 0; i < this->current; i++) {
//        if (this->array[i] == element) {
//            this->remove(i);
//            break;
//        }
//    }
//}

template<typename T>
void list<T>::remove(int index) {
    if (index >= 0 && index < this->current) {
        for (int i = index; i < this->current - 1; i++) {
            this->array[i] = this->array[i + 1];
        }

        this->current--;
    }
}

template<typename T>
void list<T>::swap(int first, int second) {
    T temp = this->array[first];
    this->array[first] = this->array[second];
    this->array[second] = temp;
}

template<typename T>
int list<T>::find_index(T element) {
    for (int i = 0; i < this->current; i++) {
        if (this->array[i] == element) {
            return i;
        }
    }

    return -1;
}

template<typename T>
int list<T>::size() {
    return this->current;
}

template<typename T>
void list<T>::print() {
    for (int i = 0; i < this->current; i++) {
        std::cout << this->array[i] << " ";
    }
}


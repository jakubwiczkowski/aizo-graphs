

#ifndef AIZO_GRAPHS_RESULT_H
#define AIZO_GRAPHS_RESULT_H

#include "../graph/graph.h"

template<typename T>
class result {
    T data;
public:
    result() = default;
    explicit result(T data) : data(data) {}

    [[nodiscard]] T get_data() const {
        return this->data;
    }

    virtual void print(graph& target_graph) = 0;
};


#endif //AIZO_GRAPHS_RESULT_H

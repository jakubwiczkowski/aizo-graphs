

#ifndef AIZO_GRAPHS_DIJKSTRA_RESULT_H
#define AIZO_GRAPHS_DIJKSTRA_RESULT_H

#include <cstdlib>
#include <limits>
#include "../result.h"

struct dijkstra_data {
    int* dist;
    ushort* path;
    ushort start;

    ~dijkstra_data() {
        delete[] dist;
        delete[] path;
    }
};


class dijkstra_result : public result<dijkstra_data*> {
public:
    explicit dijkstra_result(dijkstra_data* data) : result(data) {}
    ~dijkstra_result() {
        delete this->get_data();
    }

    void print(graph& target_graph) override {
        for (ushort i = 0; i < target_graph.get_vertices(); i++) {
            std::cout << "Path from " << this->get_data()->start << " to " << i << " is: ";
            ushort end = i;
            if (this->get_data()->path[end] == std::numeric_limits<ushort>::max()) {
                std::cout << "Path doesn't exist" << std::endl;
                continue;
            }
            while (end != this->get_data()->start) {
                std::cout << end << " <- ";
                end = this->get_data()->path[end];
            }
            std::cout << this->get_data()->start;
            std::cout << " | Weight: " << this->get_data()->dist[i] << std::endl;
        }
    }
};


#endif //AIZO_GRAPHS_DIJKSTRA_RESULT_H

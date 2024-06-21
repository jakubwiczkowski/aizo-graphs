

#ifndef AIZO_GRAPHS_KRUSKAL_RESULT_H
#define AIZO_GRAPHS_KRUSKAL_RESULT_H


#include "../result.h"

class kruskal_result : public result<edge_kruskal*> {
public:
    explicit kruskal_result(edge_kruskal* data) : result(data) {}
    ~kruskal_result() {
        delete[] this->get_data();
    }

    void print(graph& target_graph) override {
        int weight = 0;
        for (ushort idx = 0; idx < target_graph.get_vertices() - 1; idx++) {
            std::cout << this->get_data()[idx].src << " -> " << this->get_data()[idx].dest << " | " << this->get_data()[idx].weight << std::endl;
            weight += this->get_data()[idx].weight;
        }
        std::cout << "Total weight: " << weight << std::endl;
    }
};


#endif //AIZO_GRAPHS_KRUSKAL_RESULT_H

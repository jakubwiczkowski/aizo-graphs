

#ifndef AIZO_GRAPHS_PRIM_RESULT_H
#define AIZO_GRAPHS_PRIM_RESULT_H


#include "../result.h"

class prim_result : public result<ushort*> {
public:
    explicit prim_result(ushort* data) : result(data) {}
    ~prim_result() {
        delete[] this->get_data();
    }

    void print(graph& target_graph) override {
        int weight = 0;
        for (ushort i = 0; i < target_graph.get_vertices(); i++) {
            if (this->get_data()[i] == 65535) continue;

            std::cout << this->get_data()[i] << " -> " << i << " | " << target_graph.get_weight(this->get_data()[i], i) << std::endl;
            weight += target_graph.get_weight(this->get_data()[i], i);
        }
        std::cout << "Total weight: " << weight << std::endl;
    }
};


#endif //AIZO_GRAPHS_PRIM_RESULT_H

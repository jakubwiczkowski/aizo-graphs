

#ifndef AIZO_GRAPHS_PRIM_ALGORITHM_H
#define AIZO_GRAPHS_PRIM_ALGORITHM_H


#include "../algorithm.h"

class prim_algorithm : public algorithm {
public:
    struct vertex {
        ushort parent;
        ushort key;
    };

    struct compare {
        bool operator()(vertex const& a, vertex const& b) {
            return a.key > b.key;
        }
    };

    void run(graph& graph, ushort start, bool print) override;
private:
    ushort min_key(int* key, ushort* in_mst, ushort vertices);
};


#endif //AIZO_GRAPHS_PRIM_ALGORITHM_H

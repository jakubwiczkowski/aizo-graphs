

#ifndef AIZO_GRAPHS_PRIM_ALGORITHM_H
#define AIZO_GRAPHS_PRIM_ALGORITHM_H


#include "../algorithm.h"

class prim_algorithm : public algorithm {
public:
    void run(graph& graph, ulong start) override;

private:
    ulong min_key(ulong* key, ulong* in_mst, ulong vertices);
};


#endif //AIZO_GRAPHS_PRIM_ALGORITHM_H

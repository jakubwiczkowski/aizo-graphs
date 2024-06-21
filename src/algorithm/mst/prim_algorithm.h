

#ifndef AIZO_GRAPHS_PRIM_ALGORITHM_H
#define AIZO_GRAPHS_PRIM_ALGORITHM_H


#include "../algorithm.h"
#include "prim_result.h"

class prim_algorithm : public algorithm<prim_result> {
public:
    prim_result run(graph& graph, ushort start) override;
};


#endif //AIZO_GRAPHS_PRIM_ALGORITHM_H

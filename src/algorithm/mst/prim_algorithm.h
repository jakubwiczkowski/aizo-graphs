

#ifndef AIZO_GRAPHS_PRIM_ALGORITHM_H
#define AIZO_GRAPHS_PRIM_ALGORITHM_H


#include "../algorithm.h"

class prim_algorithm : public algorithm {
public:
    void run(graph& graph, ushort start, bool print) override;

private:
    ushort min_key(ushort* key, ushort* in_mst, ushort vertices);
};


#endif //AIZO_GRAPHS_PRIM_ALGORITHM_H

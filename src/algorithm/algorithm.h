

#ifndef AIZO_GRAPHS_ALGORITHM_H
#define AIZO_GRAPHS_ALGORITHM_H


#include "../graph/graph.h"

class algorithm {
public:
    virtual void run(graph& graph, ushort start, bool print) = 0;
};


#endif //AIZO_GRAPHS_ALGORITHM_H

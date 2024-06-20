

#ifndef AIZO_GRAPHS_DIJKSTRA_ALGORITHM_H
#define AIZO_GRAPHS_DIJKSTRA_ALGORITHM_H


#include "../algorithm.h"

class dijkstra_algorithm : public algorithm {
public:
    void run(graph& graph, ushort start, bool print) override;
};


#endif //AIZO_GRAPHS_DIJKSTRA_ALGORITHM_H

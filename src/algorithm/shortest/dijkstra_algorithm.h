

#ifndef AIZO_GRAPHS_DIJKSTRA_ALGORITHM_H
#define AIZO_GRAPHS_DIJKSTRA_ALGORITHM_H


#include "../algorithm.h"

class dijkstra_algorithm : public algorithm {
public:
    void run(graph& graph, ulong start) override;

private:
    ulong min_distance(ulong* dist, bool* visited, ulong vertices);
};


#endif //AIZO_GRAPHS_DIJKSTRA_ALGORITHM_H

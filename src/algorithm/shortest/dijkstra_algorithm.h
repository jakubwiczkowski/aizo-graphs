

#ifndef AIZO_GRAPHS_DIJKSTRA_ALGORITHM_H
#define AIZO_GRAPHS_DIJKSTRA_ALGORITHM_H


#include "../algorithm.h"
#include "dijkstra_result.h"

class dijkstra_algorithm : public algorithm<dijkstra_result> {
public:
    dijkstra_result run(graph& graph, ushort start) override;
};


#endif //AIZO_GRAPHS_DIJKSTRA_ALGORITHM_H

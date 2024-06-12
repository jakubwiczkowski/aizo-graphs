

#ifndef AIZO_GRAPHS_KRUSKAL_ALGORITHM_H
#define AIZO_GRAPHS_KRUSKAL_ALGORITHM_H


#include "../algorithm.h"

class kruskal_algorithm : public algorithm {
public:
    void run(graph& graph, ulong start) override;

private:
    ulong find(ulong* parent, ulong i);
    void union_set(ulong* parent, ulong x, ulong y);
};


#endif //AIZO_GRAPHS_KRUSKAL_ALGORITHM_H



#ifndef AIZO_GRAPHS_KRUSKAL_ALGORITHM_H
#define AIZO_GRAPHS_KRUSKAL_ALGORITHM_H


#include "../algorithm.h"

class kruskal_algorithm : public algorithm {
public:
    struct edge {
        ushort src;
        ushort dest;
        int weight;
    };

    void run(graph& graph, ushort start, bool print) override;

private:
    ushort find(ushort* parent, ushort i);
    void union_set(ushort* parent, ushort x, ushort y);
};


#endif //AIZO_GRAPHS_KRUSKAL_ALGORITHM_H

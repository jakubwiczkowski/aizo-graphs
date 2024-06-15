

#ifndef AIZO_GRAPHS_FORDBELLMAN_ALGORITHM_H
#define AIZO_GRAPHS_FORDBELLMAN_ALGORITHM_H


#include "../algorithm.h"

class fordbellman_algorithm : public algorithm {
public:
    void run(graph &graph, ulong start) override;
};


#endif //AIZO_GRAPHS_FORDBELLMAN_ALGORITHM_H

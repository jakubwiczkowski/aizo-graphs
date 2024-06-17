

#ifndef AIZO_GRAPHS_FORDBELLMAN_ALGORITHM_H
#define AIZO_GRAPHS_FORDBELLMAN_ALGORITHM_H


#include "../algorithm.h"

class fordbellman_algorithm : public algorithm {
public:
    void run(graph &graph, ushort start, bool print) override;
};


#endif //AIZO_GRAPHS_FORDBELLMAN_ALGORITHM_H

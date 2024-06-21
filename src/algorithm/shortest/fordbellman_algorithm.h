

#ifndef AIZO_GRAPHS_FORDBELLMAN_ALGORITHM_H
#define AIZO_GRAPHS_FORDBELLMAN_ALGORITHM_H


#include "../algorithm.h"
#include "fordbellman_result.h"

class fordbellman_algorithm : public algorithm<fordbellman_result> {
public:
    fordbellman_result run(graph &graph, ushort start) override;
};


#endif //AIZO_GRAPHS_FORDBELLMAN_ALGORITHM_H

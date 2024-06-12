#include <iostream>

#include "list/linked_list.h"
#include "graph/matrix/matrix_graph.h"
#include "graph/list/list_graph.h"
#include "algorithm/mst/prim_algorithm.h"

int main() {
    matrix_graph graph{5, 5};
    graph.add_edge(0, 3, 1);
    graph.add_edge(1, 2, 1);
    graph.add_edge(1, 4, 2);
    graph.add_edge(3, 0, -1);

    auto adj = graph.get_adjacent(1);
    adj->print();
    delete adj;

    std::cout << std::endl;

    graph.print();

    list_graph list_graph{4, 5};
    list_graph.add_edge(0, 1, 2);
    list_graph.add_edge(1, 0, 2);

    list_graph.add_edge(1, 2, 5);
    list_graph.add_edge(2, 1, 5);

    list_graph.add_edge(2, 3, 3);
    list_graph.add_edge(3, 2, 3);

    list_graph.add_edge(2, 0, 8);
    list_graph.add_edge(0, 2, 8);

    list_graph.add_edge(1, 3, 4);
    list_graph.add_edge(3, 1, 4);
    list_graph.print();

    prim_algorithm prims_algorithm{};
    prims_algorithm.run(list_graph, 0);
    return 0;
}

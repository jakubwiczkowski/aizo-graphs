#include <iostream>

#include "list/linked_list.h"
#include "graph/matrix/matrix_graph.h"
#include "graph/list/list_graph.h"

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

    list_graph list_graph{5, 5};
    list_graph.add_edge(0, 3, 1);
    list_graph.print();
    return 0;
}

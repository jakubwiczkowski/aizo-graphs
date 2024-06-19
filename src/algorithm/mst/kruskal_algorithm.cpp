

#include <iostream>
#include <algorithm>
#include "kruskal_algorithm.h"

void kruskal_algorithm::run(graph &graph, ushort start, bool print) {
    ushort vertices = graph.get_vertices();
    edge result[vertices];


    std::vector<edge> edge_list;

    for (ushort v = 0; v < vertices; v++) {
        for (ushort u = 0; u < vertices; u++) {
            if (u == v) continue;

            if (graph.is_adjacent(v, u)) {
                int weight = graph.get_weight(v, u);

                edge_list.push_back({v, u, weight});
            }
        }
    }

    std::sort(edge_list.begin(), edge_list.end(), [](edge a, edge b) {
        return a.weight < b.weight;
    });

    auto* parent = new ushort[(int) vertices];

    for (ushort v = 0; v < vertices; v++) {
        parent[v] = v;
    }

    ushort i = 0;
    ushort e = 0;

    while (i < vertices - 1) {
        edge next_edge = edge_list[e++];
        ushort x = find(parent, next_edge.src);
        ushort y = find(parent, next_edge.dest);

        if (x != y) {
            result[i++] = next_edge;
            union_set(parent, x, y);
        }
    }

    if (print) {
        for (ushort idx = 0; idx < vertices - 1; idx++) {
            std::cout << result[idx].src << " -> " << result[idx].dest << " | " << result[idx].weight << std::endl;
        }
    }

    delete[] parent;
}

ushort kruskal_algorithm::find(ushort *parent, ushort i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void kruskal_algorithm::union_set(ushort *parent, ushort x, ushort y) {
    ushort x_set = find(parent, x);
    ushort y_set = find(parent, y);
    parent[x_set] = y_set;
}
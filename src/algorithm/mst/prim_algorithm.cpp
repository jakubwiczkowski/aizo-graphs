#include "prim_algorithm.h"
#include <limits>
#include <iostream>

void prim_algorithm::run(graph &graph, ushort start, bool print) {
    auto* in_mst = new ushort[graph.get_vertices()];
    auto *key = new int[graph.get_vertices()];
    auto *parent = new ushort[graph.get_vertices()];

    for (ushort i = 0; i < graph.get_vertices(); i++) {
        in_mst[i] = 0;
        key[i] = std::numeric_limits<ushort>::max();
        parent[i] = -1;
    }

    key[0] = 0;

    for (ushort i = 0; i < graph.get_vertices() - 1; i++) {
        ushort u = min_key(key, in_mst, graph.get_vertices());
        in_mst[u] = 1;

        for (ushort v = 0; v < graph.get_vertices(); v++) {
            if (graph.is_adjacent(u, v) && !in_mst[v] && graph.get_weight(u, v) < key[v]) {
                parent[v] = u;
                key[v] = graph.get_weight(u, v);
            }
        }
    }

    if (print) {
        for (ushort i = 1; i < graph.get_vertices(); i++) {
            std::cout << parent[i] << " -> " << i << " | " << graph.get_weight(parent[i], i) << std::endl;
        }
    }

    delete[] in_mst;
    delete[] key;
    delete[] parent;
}

ushort prim_algorithm::min_key(int *key, ushort *in_mst, ushort vertices) {
    ushort min = std::numeric_limits<ushort>::max();
    ushort min_index = 0;

    for (ushort i = 0; i < vertices; i++) {
        if (!in_mst[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

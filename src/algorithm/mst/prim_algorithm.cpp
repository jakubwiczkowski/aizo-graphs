#include "prim_algorithm.h"
#include <limits>
#include <iostream>

void prim_algorithm::run(graph &graph, ulong start) {
    auto* in_mst = new ulong[graph.get_vertices()];
    auto* key = new ulong[graph.get_vertices()];
    auto* parent = new ulong[graph.get_vertices()];

    for (ulong i = 0; i < graph.get_vertices(); i++) {
        in_mst[i] = 0;
        key[i] = std::numeric_limits<ulong>::max();
        parent[i] = -1;
    }

    key[0] = 0;

    for (ulong i = 0; i < graph.get_vertices() - 1; i++) {
        ulong u = min_key(key, in_mst, graph.get_vertices());
        in_mst[u] = 1;

        for (ulong v = 0; v < graph.get_vertices(); v++) {
            if (graph.is_adjacent(u, v) && !in_mst[v] && graph.get_weight(u, v) < key[v]) {
                parent[v] = u;
                key[v] = graph.get_weight(u, v);
            }
        }
    }

    for (ulong i = 1; i < graph.get_vertices(); i++) {
        std::cout << parent[i] << " -> " << i << " | " << graph.get_weight(i, parent[i]) << std::endl;
    }

    delete[] in_mst;
    delete[] key;
    delete[] parent;
}

ulong prim_algorithm::min_key(ulong* key, ulong* in_mst, ulong vertices) {
    ulong min = std::numeric_limits<ulong>::max();
    ulong min_index = 0;

    for (ulong i = 0; i < vertices; i++) {
        if (!in_mst[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

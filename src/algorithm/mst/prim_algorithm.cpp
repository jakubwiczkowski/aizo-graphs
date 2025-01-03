#include "prim_algorithm.h"
#include "../../list/heap.h"
#include <limits>
#include <iostream>

prim_result prim_algorithm::run(graph &graph, ushort start) {
    auto* in_mst = new ushort[graph.get_vertices()];
    auto* key = new int[graph.get_vertices()];
    auto* parent = new ushort[graph.get_vertices()];

    heap<vertex_prim> heap;

    for (ushort i = 0; i < graph.get_vertices(); i++) {
        in_mst[i] = 0;
        parent[i] = -1;

        if (i == start) {
            key[i] = 0;
            heap.add({i, key[i]});
        } else {
            key[i] = std::numeric_limits<ushort>::max();
            heap.add({i, key[i]});
        }
    }

    for (ushort i = 0; i < graph.get_vertices(); i++) {
        ushort u = heap[0].idx;
        heap.remove(0);
        in_mst[u] = 1;

        for (ushort v = 0; v < graph.get_vertices(); v++) {
            int weight = graph.get_weight(u, v);
            if (graph.is_adjacent(u, v) && !in_mst[v] && weight < key[v]) {
                parent[v] = u;
                int heap_idx = heap.find_index({v, key[v]});
                heap.remove(heap_idx);
                heap.add({v, weight});
                key[v] = weight;
            }
        }
    }

    delete[] in_mst;
    delete[] key;

    return prim_result(parent);
}

#include "prim_algorithm.h"
#include "../../list/heap.h"
#include <limits>
#include <iostream>

void prim_algorithm::run(graph &graph, ushort start, bool print) {
    auto* in_mst = new ushort[graph.get_vertices()];
    auto* key = new int[graph.get_vertices()];
    auto* parent = new ushort[graph.get_vertices()];

    heap<vertex> heap;

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

    heap.print();

    for (ushort i = 0; i < graph.get_vertices(); i++) {
        ushort u = heap[0].idx;
        heap.remove(0);
        in_mst[u] = 1;

        for (ushort v = 0; v < graph.get_vertices(); v++) {
            if (graph.is_adjacent(u, v) && !in_mst[v] && graph.get_weight(u, v) < key[v]) {
                parent[v] = u;
                int heap_idx = heap.find_index({v, key[v]});
                heap.remove(heap_idx);
                heap.add({v, graph.get_weight(u, v)});
                key[v] = graph.get_weight(u, v);
            }
        }
    }

    if (print) {
        int weight = 0;
        for (ushort i = 0; i < graph.get_vertices(); i++) {
            if (i == start) continue;

            std::cout << parent[i] << " -> " << i << " | " << graph.get_weight(parent[i], i) << std::endl;
            weight += graph.get_weight(parent[i], i);
        }
        std::cout << "Total weight: " << weight << std::endl;
    }

    delete[] in_mst;
    delete[] key;
    delete[] parent;
}



#include <limits>
#include <iostream>
#include "dijkstra_algorithm.h"
#include "helper/vertex_dijkstra.h"
#include "../../list/heap.h"

void dijkstra_algorithm::run(graph &graph, ushort start, bool print) {
    auto *dist = new int[graph.get_vertices()];
    bool *visited = new bool[graph.get_vertices()];
    auto *path = new ushort[graph.get_vertices()];

    heap<vertex_dijkstra> heap;

    for (ushort i = 0; i < graph.get_vertices(); i++) {
        visited[i] = false;
        path[i] = -1;

        if (i == start) {
            dist[i] = 0;
            heap.add({i, dist[i]});
        } else {
            dist[i] = std::numeric_limits<ushort>::max();
            heap.add({i, dist[i]});
        }
    }

    for (ushort i = 0; i < graph.get_vertices(); i++) {
        ushort u = heap[0].idx;
        heap.remove(0);
        visited[u] = true;

        auto adj = graph.get_adjacent(u);
        for (ushort j = 0; j < adj.size(); j++) {
            ushort v = adj[j];
            ushort weight = graph.get_weight(u, v);

            if (!visited[v] && dist[u] != std::numeric_limits<ushort>::max() && dist[u] + weight < dist[v]) {
                int heap_idx = heap.find_index({v, dist[v]});
                heap.remove(heap_idx);
                dist[v] = dist[u] + weight;
                path[v] = u;
                heap.add({v, dist[v]});
            }
        }
    }

    if (print) {
        for (ushort i = 0; i < graph.get_vertices(); i++) {
            std::cout << "Path from " << start << " to " << i << " is: ";
            ushort end = i;
            if (path[end] == std::numeric_limits<ushort>::max()) {
                std::cout << "Path doesn't exist" << std::endl;
                continue;
            }
            while (end != start) {
                std::cout << end << " <- ";
                end = path[end];
            }
            std::cout << start;
            std::cout << " | Weight: " << dist[i] << std::endl;
        }
    }

    delete[] path;
    delete[] dist;
    delete[] visited;
}

//ushort dijkstra_algorithm::min_distance(ushort *dist, bool *visited, ushort vertices) {
//    ushort min = std::numeric_limits<ushort>::max();
//    ushort min_index = 0;
//
//    for (ushort i = 0; i < vertices; i++) {
//        if (!visited[i] && dist[i] <= min) {
//            min = dist[i];
//            min_index = i;
//        }
//    }
//
//    return min_index;
//}

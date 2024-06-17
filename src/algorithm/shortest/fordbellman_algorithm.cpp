

#include <limits>
#include <iostream>
#include "fordbellman_algorithm.h"

void fordbellman_algorithm::run(graph &graph, ushort start, bool print) {
    auto* dist = new ushort[graph.get_vertices()];
    auto* path = new ushort[graph.get_vertices()];

    for (ushort i = 0; i < graph.get_vertices(); i++) {
        dist[i] = std::numeric_limits<ushort>::max();
        path[i] = -1;
    }

    dist[start] = 0;

    for (ushort i = 0; i < graph.get_vertices() - 1; i++) {
        for (ushort u = 0; u < graph.get_vertices(); u++) {
            auto adj = graph.get_adjacent(u);
            for (ushort j = 0; j < adj.size(); j++) {
                ushort v = adj[j];
                ushort weight = graph.get_weight(u, v);

                if (dist[u] != std::numeric_limits<ushort>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    path[v] = u;
                }
            }
        }
    }

    for (ushort u = 0; u < graph.get_vertices(); u++) {
        auto adj = graph.get_adjacent(u);
        for (ushort j = 0; j < adj.size(); j++) {
            ushort v = adj[j];
            ushort weight = graph.get_weight(u, v);

            if (dist[u] != std::numeric_limits<ushort>::max() && dist[u] + weight < dist[v]) {
                std::cout << "Graph contains negative cycle" << std::endl;
                return;
            }
        }
    }

    if (print) {
        for (ushort i = 0; i < graph.get_vertices(); i++) {
            std::cout << "Path from " << start << " to " << i << " is: ";
            ushort end = i;
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
}



#include <limits>
#include <iostream>
#include "fordbellman_algorithm.h"

fordbellman_result fordbellman_algorithm::run(graph &graph, ushort start) {
    auto* dist = new ushort[graph.get_vertices()];
    auto* path = new ushort[graph.get_vertices()];

    for (ushort i = 0; i < graph.get_vertices(); i++) {
        dist[i] = std::numeric_limits<ushort>::max();
        path[i] = -1;
    }

    dist[start] = 0;

    for (ushort i = 0; i < graph.get_vertices() - 1; i++) {
        bool all_not_passed = true;
        for (ushort u = 0; u < graph.get_vertices(); u++) {
            auto adj = graph.get_adjacent(u);
            for (ushort j = 0; j < adj.size(); j++) {
                ushort v = adj[j];
                ushort weight = graph.get_weight(u, v);

                if (dist[u] != std::numeric_limits<ushort>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    path[v] = u;

                    all_not_passed = false;
                }
            }
        }

        if (all_not_passed) break;
    }

    for (ushort u = 0; u < graph.get_vertices(); u++) {
        auto adj = graph.get_adjacent(u);
        for (auto j = 0; j < adj.size(); j++) {
            ushort v = adj[j];
            ushort weight = graph.get_weight(u, v);

            if (dist[u] != std::numeric_limits<ushort>::max() && dist[u] + weight < dist[v]) {
                std::cout << "Graph contains negative cycle" << std::endl;
                return fordbellman_result(new fordbellman_data{dist, path, start});
            }
        }
    }

    return fordbellman_result(new fordbellman_data{dist, path, start});
}

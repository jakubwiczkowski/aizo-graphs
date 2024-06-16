

#include <limits>
#include <iostream>
#include "fordbellman_algorithm.h"

void fordbellman_algorithm::run(graph &graph, ulong start) {
    auto* dist = new ulong[graph.get_vertices()];
    auto* path = new ulong[graph.get_vertices()];

    for (ulong i = 0; i < graph.get_vertices(); i++) {
        dist[i] = std::numeric_limits<ulong>::max();
        path[i] = -1;
    }

    dist[start] = 0;

    for (ulong i = 0; i < graph.get_vertices() - 1; i++) {
        for (ulong u = 0; u < graph.get_vertices(); u++) {
            auto* adj = graph.get_adjacent(u);
            for (ulong j = 0; j < adj->get_size(); j++) {
                ulong v = adj->get(j)->get_key();
                ulong weight = graph.get_weight(u, v);

                if (dist[u] != std::numeric_limits<ulong>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    path[v] = u;
                }
            }
            delete adj;
        }
    }

    for (ulong u = 0; u < graph.get_vertices(); u++) {
        auto* adj = graph.get_adjacent(u);
        for (ulong j = 0; j < adj->get_size(); j++) {
            ulong v = adj->get(j)->get_key();
            ulong weight = graph.get_weight(u, v);

            if (dist[u] != std::numeric_limits<ulong>::max() && dist[u] + weight < dist[v]) {
                std::cout << "Graph contains negative cycle" << std::endl;
                return;
            }
        }
        delete adj;
    }

    for (ulong i = 0; i < graph.get_vertices(); i++) {
        std::cout << "Path from " << start << " to " << i << " is: ";
        ulong end = i;
        while (end != start) {
            std::cout << end << " <- ";
            end = path[end];
        }
        std::cout << start;
        std::cout << " | Weight: " << dist[i] << std::endl;
    }

    delete[] path;
    delete[] dist;
}

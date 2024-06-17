

#include <limits>
#include <iostream>
#include "dijkstra_algorithm.h"

void dijkstra_algorithm::run(graph &graph, ushort start, bool print) {
    auto *dist = new ushort[graph.get_vertices()];
    bool *visited = new bool[graph.get_vertices()];
    auto *path = new ushort[graph.get_vertices()];

    for (ushort i = 0; i < graph.get_vertices(); i++) {
        dist[i] = std::numeric_limits<ushort>::max();
        visited[i] = false;
        path[i] = -1;
    }

    dist[start] = 0;

    for (ushort i = 0; i < graph.get_vertices(); i++) {
        ushort u = min_distance(dist, visited, graph.get_vertices());
        visited[u] = true;

        auto adj = graph.get_adjacent(u);
        for (ushort j = 0; j < adj.size(); j++) {
            ushort v = adj[j];
            ushort weight = graph.get_weight(u, v);

            if (!visited[v] && dist[u] != std::numeric_limits<ushort>::max() && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                path[v] = u;
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
    delete[] visited;
}

ushort dijkstra_algorithm::min_distance(ushort *dist, bool *visited, ushort vertices) {
    ushort min = std::numeric_limits<ushort>::max();
    ushort min_index = 0;

    for (ushort i = 0; i < vertices; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}



#include <limits>
#include <iostream>
#include "dijkstra_algorithm.h"

void dijkstra_algorithm::run(graph &graph, ulong start) {
    auto* dist = new ulong[graph.get_vertices()];
    bool* visited = new bool[graph.get_vertices()];
    auto* path = new ulong[graph.get_vertices()];

    for (ulong i = 0; i < graph.get_vertices(); i++) {
        dist[i] = std::numeric_limits<ulong>::max();
        visited[i] = false;
        path[i] = -1;
    }

    dist[start] = 0;

    for (ulong i = 0; i < graph.get_vertices(); i++) {
        ulong u = min_distance(dist, visited, graph.get_vertices());
        visited[u] = true;

        auto* adj = graph.get_adjacent(u);
        for (ulong j = 0; j < adj->get_size(); j++) {
            ulong v = adj->get(j)->get_key();
            ulong weight = graph.get_weight(u, v);

            if (!visited[v] && dist[u] != std::numeric_limits<ulong>::max() && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                path[v] = u;
            }
        }
        delete adj;
    }

    for (ulong i = 0; i < graph.get_vertices(); i++) {
        std::cout << i << " -> " << dist[i] << std::endl;
    }

    // print out the shortest path from the start node to the end node
     for (ulong i = 0; i < graph.get_vertices(); i++) {
         std::cout << "Path from " << start << " to " << i << " is: ";
         ulong end = i;
         while (end != start) {
             std::cout << end << " <- ";
             end = path[end];
         }
         std::cout << start << std::endl;
     }


    delete[] path;
    delete[] dist;
    delete[] visited;
}

ulong dijkstra_algorithm::min_distance(ulong *dist, bool *visited, ulong vertices) {
    ulong min = std::numeric_limits<ulong>::max();
    ulong min_index = 0;

    for (ulong i = 0; i < vertices; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

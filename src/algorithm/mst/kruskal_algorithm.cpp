

#include <iostream>
#include <algorithm>
#include "kruskal_algorithm.h"

void kruskal_algorithm::run(graph &graph, ulong start) {
    // create kruskal's algorithm but only use the current functins in a graph for accessing edges
    ulong vertices = graph.get_vertices();
    ulong edges = graph.get_edges();
    edge result[vertices];

    ulong i = 0;
    ulong e = 0;

    auto* edge_array = new edge[edges];

    for (ulong v = 0; v < vertices; v++) {
        auto* adj = graph.get_adjacent(v);
        for (ulong j = 0; j < adj->get_size(); j++) {
            ulong u = adj->get(j)->get_key();
            int weight = graph.get_weight(u, v);

            edge_array[e].src = v;
            edge_array[e].dest = u;
            edge_array[e].weight = weight;
            e++;
        }
        delete adj;
    }

    std::sort(edge_array, edge_array + edges, [](edge a, edge b) {
        return a.weight < b.weight;
    });

    auto* parent = new ulong[vertices];

    for (ulong v = 0; v < vertices; v++) {
        parent[v] = v;
    }

    i = 0;
    e = 0;

    while (i < vertices - 1) {
        edge next_edge = edge_array[e++];
        ulong x = find(parent, next_edge.src);
        ulong y = find(parent, next_edge.dest);

        if (x != y) {
            result[i++] = next_edge;
            union_set(parent, x, y);
        }
    }

    for (ulong idx = 0; idx < vertices - 1; idx++) {
        std::cout << result[idx].src << " -> " << result[idx].dest << " | " << result[idx].weight << std::endl;
    }
    delete[] edge_array;
    delete[] parent;
}

ulong kruskal_algorithm::find(ulong *parent, ulong i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void kruskal_algorithm::union_set(ulong *parent, ulong x, ulong y) {
    ulong x_set = find(parent, x);
    ulong y_set = find(parent, y);
    parent[x_set] = y_set;
}
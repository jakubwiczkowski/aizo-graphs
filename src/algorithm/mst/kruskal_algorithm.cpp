

#include <iostream>
#include "kruskal_algorithm.h"

void kruskal_algorithm::run(graph &graph, ulong start) {
//    auto* edges = new edge[graph.get_edges()];
//    ulong edge_count = 0;
//
//    for (ulong i = 0; i < graph.get_vertices(); i++) {
//        auto* adj = graph.get_adjacent(i);
//        for (ulong j = 0; j < adj->get_size(); j++) {
//            if (i < adj->get(j)->get_key()) {
//                edges[edge_count++] = {i, adj->get(j)->get_key(), adj->get(j).get};
//            }
//        }
//        delete adj;
//    }
//
//    std::sort(edges, edges + edge_count, [](edge a, edge b) {
//        return a.weight < b.weight;
//    });
//
//    auto* parent = new ulong[graph.get_vertices()];
//    for (ulong i = 0; i < graph.get_vertices(); i++) {
//        parent[i] = i;
//    }
//
//    ulong edge_index = 0;
//    ulong mst_index = 0;
//    auto* mst = new edge[graph.get_vertices() - 1];
//
//    while (mst_index < graph.get_vertices() - 1) {
//        auto next_edge = edges[edge_index++];
//        ulong x = find(parent, next_edge.src);
//        ulong y = find(parent, next_edge.dest);
//
//        if (x != y) {
//            mst[mst_index++] = next_edge;
//            union_set(parent, x, y);
//        }
//    }
//
//    for (ulong i = 0; i < graph.get_vertices() - 1; i++) {
//        std::cout << mst[i].src << " -> " << mst[i].dest << " | " << mst[i].weight << std::endl;
//    }
//
//    delete[] edges;
//    delete[] parent;
//    delete[] mst;
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
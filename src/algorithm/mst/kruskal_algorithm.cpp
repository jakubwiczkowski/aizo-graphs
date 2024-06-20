

#include <iostream>
#include <algorithm>
#include "kruskal_algorithm.h"
#include "helper/edge_kruskal.h"

void kruskal_algorithm::run(graph &graph, ushort start, bool print) {
    ushort vertices = graph.get_vertices();
    edge_kruskal result[vertices];

    list<edge_kruskal> edge_list;

    for (ushort v = 0; v < vertices; v++) {
        list<ushort> adjacent = graph.get_adjacent(v);

        for (int idx = 0; idx < adjacent.size(); idx++) {
            ushort u = adjacent[idx];
            int weight = graph.get_weight(v, u);

            edge_list.add({v, u, weight});
        }
    }

    sort_edges(edge_list);

    auto* parent = new ushort[(int) vertices];

    for (ushort v = 0; v < vertices; v++) {
        parent[v] = v;
    }

    ushort i = 0;
    ushort e = 0;

    while (i < vertices - 1) {
        edge_kruskal next_edge = edge_list[e++];
        ushort x = find(parent, next_edge.src);
        ushort y = find(parent, next_edge.dest);

        if (x != y) {
            result[i++] = next_edge;
            union_set(parent, x, y);
        }
    }

    if (print) {
        int weight = 0;
        for (ushort idx = 0; idx < vertices - 1; idx++) {
            std::cout << result[idx].src << " -> " << result[idx].dest << " | " << result[idx].weight << std::endl;
            weight += result[idx].weight;
        }
        std::cout << "Total weight: " << weight << std::endl;
    }

    delete[] parent;
}

ushort kruskal_algorithm::find(ushort *parent, ushort i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void kruskal_algorithm::sort_edges(list<edge_kruskal> &edge_list) {
    quick_sort(edge_list, 0, edge_list.size() - 1);
}

void kruskal_algorithm::union_set(ushort *parent, ushort x, ushort y) {
    ushort x_set = find(parent, x);
    ushort y_set = find(parent, y);
    parent[x_set] = y_set;
}

void kruskal_algorithm::quick_sort(list<edge_kruskal>& edge_list, int low, int high) {
    if (low >= high)
        return;

    int partition_idx = partition(edge_list, low, high);

    quick_sort(edge_list, low, partition_idx);
    quick_sort(edge_list, partition_idx + 1, high);
}

int kruskal_algorithm::partition(list<edge_kruskal>& edge_list, int low, int high) {
    int pivot_position = low + (high - low) / 2;

    edge_kruskal pivot = edge_list[pivot_position];

    int left = low, right = high;

    while (true) {
        while (edge_list[left] < pivot) ++left;
        while (edge_list[right] > pivot) --right;

        if (left < right) {
            edge_list.swap(left, right);
            ++left;
            --right;
        } else {
            if (right == high) right--;
            return right;
        }
    }
}

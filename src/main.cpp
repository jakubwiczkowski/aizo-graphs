#include <iostream>
#include <fstream>
#include <chrono>

#include "list/linked_list.h"
#include "graph/matrix/matrix_graph.h"
#include "graph/list/list_graph.h"
#include "algorithm/mst/prim_algorithm.h"
#include "algorithm/shortest/dijkstra_algorithm.h"
#include "algorithm/shortest/fordbellman_algorithm.h"
#include "algorithm/mst/kruskal_algorithm.h"
#include "menu/menu.h"

int main() {
    menu main_menu(7);

    matrix_graph* matrix_graph = nullptr;
    list_graph* list_graph = nullptr;

    main_menu.add_option(0, "Wczytaj dane z pliku", [&matrix_graph, &list_graph] {
        std::cout << "[?] Czy graf jest skierowany? (t/n): ";
        char directed;
        std::cin >> directed;
        if (directed != 't' && directed != 'n') {
            std::cout << "[!] Niepoprawna odpowiedz\n";
            return;
        }
        bool is_directed = directed == 't';
        std::cout << "[?] Podaj sciezke do pliku: ";
        std::string path;
        std::cin >> path;
        std::ifstream file(path);
        if (!file.is_open()) {
            std::cout << "[!] Nie udalo sie otworzyc pliku\n";
            return;
        }

        if (matrix_graph != nullptr) {
            delete matrix_graph;
        }
        if (list_graph != nullptr) {
            delete list_graph;
        }

        ulong vertices, edges;
        file >> edges >> vertices;

        matrix_graph = new class matrix_graph(vertices, directed ? edges : edges * 2);
        list_graph = new class list_graph(vertices, directed ? edges : edges * 2);

        for (int i = 0; i < edges; ++i) {
            ulong u, v;
            int weight;
            file >> u >> v >> weight;
            matrix_graph->add_edge(u, v, weight);
            list_graph->add_edge(u, v, weight);

            if (!is_directed) {
                matrix_graph->add_edge(v, u, weight);
                list_graph->add_edge(v, u, weight);
            }
        }
    });
    main_menu.add_option(1, "Wygeneruj graf losowo", [] {
        std::cout << "Wygeneruj graf losowo\n";
    });
    main_menu.add_option(2, "Wyswietl graf listowo i macierzowo na ekranie", [&matrix_graph, &list_graph] {
        if (matrix_graph == nullptr || list_graph == nullptr) {
            std::cout << "[!] Brak wczytanego grafu\n";
            return;
        }
        std::cout << "[#] Macierzowo:\n";
        matrix_graph->print();

        std::cout << "[#] Listowo:\n";
        list_graph->print();
    });
    main_menu.add_option(3, "Algorytm Prima macierzowo i listowo", [&matrix_graph, &list_graph] {
        if (matrix_graph == nullptr || list_graph == nullptr) {
            std::cout << "[!] Brak wczytanego grafu\n";
            return;
        }

        prim_algorithm prim{};
        std::cout << "[#] Prim - macierzowo\n";
        const auto start_time_matrix = std::chrono::high_resolution_clock::now();
        prim.run(*matrix_graph, 0);
        const auto end_time_matrix = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Prim - macierzowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_matrix - start_time_matrix).count() << "ns" << std::endl;

        std::cout << "[#] Prim - listowo\n";
        const auto start_time_list = std::chrono::high_resolution_clock::now();
        prim.run(*list_graph, 0);
        const auto end_time_list = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Prim - listowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_list - start_time_list).count() << "ns" << std::endl;
    });
    main_menu.add_option(4, "Algorytm Kruskala macierzowo i listowo", [&matrix_graph, &list_graph] {
        if (matrix_graph == nullptr || list_graph == nullptr) {
            std::cout << "[!] Brak wczytanego grafu\n";
            return;
        }

        kruskal_algorithm kruskal{};
        std::cout << "[#] Kruskal - macierzowo\n";
        const auto start_time_matrix = std::chrono::high_resolution_clock::now();
        kruskal.run(*matrix_graph, 0);
        const auto end_time_matrix = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Kruskal - macierzowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_matrix - start_time_matrix).count() << "ns" << std::endl;

        std::cout << "[#] Kruskal - listowo\n";
        const auto start_time_list = std::chrono::high_resolution_clock::now();
        kruskal.run(*list_graph, 0);
        const auto end_time_list = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Kruskal - listowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_list - start_time_list).count() << "ns" << std::endl;
    });
    main_menu.add_option(5, "Algorytm Dijkstry macierzowo i listowo", [&matrix_graph, &list_graph] {
        if (matrix_graph == nullptr || list_graph == nullptr) {
            std::cout << "[!] Brak wczytanego grafu\n";
            return;
        }

        dijkstra_algorithm dijkstra{};
        std::cout << "[#] Dijkstra - macierzowo\n";
        const auto start_time_matrix = std::chrono::high_resolution_clock::now();
        dijkstra.run(*matrix_graph, 0);
        const auto end_time_matrix = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Dijkstra - macierzowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_matrix - start_time_matrix).count() << "ns" << std::endl;

        std::cout << "[#] Dijkstra - listowo\n";
        const auto start_time_list = std::chrono::high_resolution_clock::now();
        dijkstra.run(*list_graph, 0);
        const auto end_time_list = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Dijkstra - listowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_list - start_time_list).count() << "ns" << std::endl;
    });
    main_menu.add_option(6, "Algorytm Forda-Bellmana macierzowo i listowo", [&matrix_graph, &list_graph] {
        if (matrix_graph == nullptr || list_graph == nullptr) {
            std::cout << "[!] Brak wczytanego grafu\n";
            return;
        }

        fordbellman_algorithm fordbellman{};
        std::cout << "[#] Ford-Bellman - macierzowo\n";
        const auto start_time_matrix = std::chrono::high_resolution_clock::now();
        fordbellman.run(*matrix_graph, 0);
        const auto end_time_matrix = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Ford-Bellman - macierzowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_matrix - start_time_matrix).count() << "ns" << std::endl;

        std::cout << "[#] Ford-Bellman - listowo\n";
        const auto start_time_list = std::chrono::high_resolution_clock::now();
        fordbellman.run(*list_graph, 0);
        const auto end_time_list = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Ford-Bellman - listowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_list - start_time_list).count() << "ns" << std::endl;
    });
    main_menu.open();
    return 0;
}

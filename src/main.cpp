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
    menu main_menu(9);

    matrix_graph* loaded_matrix_graph = nullptr;
    list_graph* loaded_list_graph = nullptr;

    main_menu.add_option(0, "Wczytaj dane z pliku", [&loaded_matrix_graph, &loaded_list_graph] {
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

        if (loaded_matrix_graph != nullptr) {
            delete loaded_matrix_graph;
        }
        if (loaded_list_graph != nullptr) {
            delete loaded_list_graph;
        }

        ushort vertices, edges;
        file >> edges >> vertices;

        loaded_matrix_graph = new matrix_graph(vertices, (ushort) (directed ? edges : edges * 2));
        loaded_list_graph = new list_graph(vertices, (ushort) (directed ? edges : edges * 2));

        for (int i = 0; i < edges; ++i) {
            ushort u, v;
            int weight;
            file >> u >> v >> weight;
            loaded_matrix_graph->add_edge(u, v, weight);
            loaded_list_graph->add_edge(u, v, weight);

            if (!is_directed) {
                loaded_matrix_graph->add_edge(v, u, weight);
                loaded_list_graph->add_edge(v, u, weight);
            }
        }
    });
    main_menu.add_option(1, "Wygeneruj graf losowo", [&loaded_matrix_graph, &loaded_list_graph] {
        double density;
        ushort vertices;
        bool is_directed;
        std::cout << "[?] Podaj ilosc wierzcholkow: ";
        std::cin >> vertices;
        std::cout << "[?] Podaj gestosc grafu (0-1): ";
        std::cin >> density;
        std::cout << "[?] Czy graf jest skierowany? (t/n): ";
        char directed;
        std::cin >> directed;
        if (directed != 't' && directed != 'n') {
            std::cout << "[!] Niepoprawna odpowiedz\n";
            return;
        }
        is_directed = directed == 't';

        if (loaded_matrix_graph != nullptr) {
            delete loaded_matrix_graph;
        }
        if (loaded_list_graph != nullptr) {
            delete loaded_list_graph;
        }

        loaded_matrix_graph = new matrix_graph(vertices, density, is_directed);
        loaded_list_graph = new list_graph(*loaded_matrix_graph);
    });
    main_menu.add_option(2, "Wyswietl graf listowo i macierzowo na ekranie", [&loaded_matrix_graph, &loaded_list_graph] {
        if (loaded_matrix_graph == nullptr || loaded_list_graph == nullptr) {
            std::cout << "[!] Brak wczytanego grafu\n";
            return;
        }
        std::cout << "[#] Macierzowo:\n";
        loaded_matrix_graph->print();

        std::cout << "[#] Listowo:\n";
        loaded_list_graph->print();
    });
    main_menu.add_option(3, "Algorytm Prima macierzowo i listowo", [&loaded_matrix_graph, &loaded_list_graph] {
        if (loaded_matrix_graph == nullptr || loaded_list_graph == nullptr) {
            std::cout << "[!] Brak wczytanego grafu\n";
            return;
        }

        prim_algorithm prim{};
        std::cout << "[#] Prim - macierzowo\n";
        const auto start_time_matrix = std::chrono::high_resolution_clock::now();
        prim.run(*loaded_matrix_graph, 0, true);
        const auto end_time_matrix = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Prim - macierzowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_matrix - start_time_matrix).count() << "ns" << std::endl;

        std::cout << "[#] Prim - listowo\n";
        const auto start_time_list = std::chrono::high_resolution_clock::now();
        prim.run(*loaded_list_graph, 0, true);
        const auto end_time_list = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Prim - listowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_list - start_time_list).count() << "ns" << std::endl;
    });
    main_menu.add_option(4, "Algorytm Kruskala macierzowo i listowo", [&loaded_matrix_graph, &loaded_list_graph] {
        if (loaded_matrix_graph == nullptr || loaded_list_graph == nullptr) {
            std::cout << "[!] Brak wczytanego grafu\n";
            return;
        }

        kruskal_algorithm kruskal{};
        std::cout << "[#] Kruskal - macierzowo\n";
        const auto start_time_matrix = std::chrono::high_resolution_clock::now();
        kruskal.run(*loaded_matrix_graph, 0, true);
        const auto end_time_matrix = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Kruskal - macierzowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_matrix - start_time_matrix).count() << "ns" << std::endl;

        std::cout << "[#] Kruskal - listowo\n";
        const auto start_time_list = std::chrono::high_resolution_clock::now();
        kruskal.run(*loaded_list_graph, 0, true);
        const auto end_time_list = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Kruskal - listowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_list - start_time_list).count() << "ns" << std::endl;
    });
    main_menu.add_option(5, "Algorytm Dijkstry macierzowo i listowo", [&loaded_matrix_graph, &loaded_list_graph] {
        if (loaded_matrix_graph == nullptr || loaded_list_graph == nullptr) {
            std::cout << "[!] Brak wczytanego grafu\n";
            return;
        }

        dijkstra_algorithm dijkstra{};
        std::cout << "[#] Dijkstra - macierzowo\n";
        const auto start_time_matrix = std::chrono::high_resolution_clock::now();
        dijkstra.run(*loaded_matrix_graph, 0, true);
        const auto end_time_matrix = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Dijkstra - macierzowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_matrix - start_time_matrix).count() << "ns" << std::endl;

        std::cout << "[#] Dijkstra - listowo\n";
        const auto start_time_list = std::chrono::high_resolution_clock::now();
        dijkstra.run(*loaded_list_graph, 0, true);
        const auto end_time_list = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Dijkstra - listowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_list - start_time_list).count() << "ns" << std::endl;
    });
    main_menu.add_option(6, "Algorytm Forda-Bellmana macierzowo i listowo", [&loaded_matrix_graph, &loaded_list_graph] {
        if (loaded_matrix_graph == nullptr || loaded_list_graph == nullptr) {
            std::cout << "[!] Brak wczytanego grafu\n";
            return;
        }

        fordbellman_algorithm fordbellman{};
        std::cout << "[#] Ford-Bellman - macierzowo\n";
        const auto start_time_matrix = std::chrono::high_resolution_clock::now();
        fordbellman.run(*loaded_matrix_graph, 0, true);
        const auto end_time_matrix = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Ford-Bellman - macierzowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_matrix - start_time_matrix).count() << "ns" << std::endl;

        std::cout << "[#] Ford-Bellman - listowo\n";
        const auto start_time_list = std::chrono::high_resolution_clock::now();
        fordbellman.run(*loaded_list_graph, 0, true);
        const auto end_time_list = std::chrono::high_resolution_clock::now();
        std::cout << "[#] Ford-Bellman - listowo - wykonano w " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_list - start_time_list).count() << "ns" << std::endl;
    });
    main_menu.add_option(7, "Obliczenia do wykresów", [] {
        ushort repetitions = 25;
        ushort sizes[] = {10, 20, 50, 100, 200, 500, 1000};
        double densities[] = {0.25, 0.5, 0.99};

        std::ofstream file("results_mst.csv", std::ios::app);
        std::ofstream file_sp("results_sp.csv", std::ios::app);

        // ALGORYTMY MST
//        prim_algorithm prim{};
//        kruskal_algorithm kruskal{};
//        for (ushort size : sizes) {
//            std::cout << "[#] Size: " << size << std::endl;
//            file << size << ",";
//            for (double density : densities) {
//                std::cout << " ↳ Density: " << density << std::endl;
//                file << density << ",";
//                long sum_prim_matrix = 0;
//                long sum_prim_list = 0;
//                long sum_kruskal_matrix = 0;
//                long sum_kruskal_list = 0;
//                for (ushort n = 0; n < repetitions; n++) {
//                    auto* matrix = new matrix_graph(size, density, false);
//                    auto* list = new list_graph(*matrix);
//                    for (int type : {0, 1}) {
//
//                        if (type == 0) {
//                            auto start_matrix = std::chrono::high_resolution_clock::now();
//                            prim.run(*matrix, 0, false);
//                            auto end_matrix = std::chrono::high_resolution_clock::now();
//                            auto duration_matrix = std::chrono::duration_cast<std::chrono::nanoseconds>(end_matrix - start_matrix).count();
//
//                            sum_prim_matrix += duration_matrix;
//                            std::cout << "  ↳ (" << n + 1 << "/" << repetitions << ") Prim runtime (matrix): " << duration_matrix << "ns" << std::endl;
//
//                            auto start_list = std::chrono::high_resolution_clock::now();
//                            prim.run(*list, 0, false);
//                            auto end_list = std::chrono::high_resolution_clock::now();
//                            auto duration_list = std::chrono::duration_cast<std::chrono::nanoseconds>(end_list - start_list).count();
//
//                            sum_prim_list += duration_list;
//                            std::cout << "  ↳ (" << n + 1 << "/" << repetitions << ") Prim runtime (list): " << duration_list << "ns" << std::endl;
//                        } else {
//                            auto start_matrix = std::chrono::high_resolution_clock::now();
//                            kruskal.run(*matrix, 0, false);
//                            auto end_matrix = std::chrono::high_resolution_clock::now();
//                            auto duration_matrix = std::chrono::duration_cast<std::chrono::nanoseconds>(end_matrix - start_matrix).count();
//
//                            sum_kruskal_matrix += duration_matrix;
//                            std::cout << "  ↳ (" << n + 1 << "/" << repetitions << ") Kruskal runtime (matrix): " << duration_matrix << "ns" << std::endl;
//
//                            auto start_list = std::chrono::high_resolution_clock::now();
//                            kruskal.run(*list, 0, false);
//                            auto end_list = std::chrono::high_resolution_clock::now();
//                            auto duration_list = std::chrono::duration_cast<std::chrono::nanoseconds>(end_list - start_list).count();
//
//                            sum_kruskal_list += duration_list;
//                            std::cout << "  ↳ (" << n + 1 << "/" << repetitions << ") Kruskal runtime (list): " << duration_list << "ns" << std::endl;
//                        }
//                    }
//                    delete list;
//                    delete matrix;
//                }
//                file << sum_prim_matrix / repetitions << "," << sum_prim_list / repetitions << "," << sum_kruskal_matrix / repetitions << "," << sum_kruskal_list / repetitions << "\n";
//                std::cout << " | Prim (matrix)    avg.: " << sum_prim_matrix / repetitions << "ns\n";
//                std::cout << " | Prim (list)      avg.: " << sum_prim_list / repetitions << "ns\n";
//                std::cout << " | Kruskal (matrix) avg.: " << sum_kruskal_matrix / repetitions << "ns\n";
//                std::cout << " ↳ Kruskal (list)   avg.: " << sum_kruskal_list / repetitions << "ns\n";
//            }
//        }

        file.close();

        // ALGORYTMY SHORTEST PATH
        dijkstra_algorithm dijkstra{};
        fordbellman_algorithm fordbellman{};
        for (ushort size : sizes) {
            std::cout << "[#] Size: " << size << std::endl;
            file_sp << size << ",";
            for (double density : densities) {
                std::cout << " ↳ Density: " << density << std::endl;
                file_sp << density << ",";
                long sum_dijkstra_matrix = 0;
                long sum_dijkstra_list = 0;
                long sum_fordbellman_matrix = 0;
                long sum_fordbellman_list = 0;
                for (ushort n = 0; n < repetitions; n++) {
                    auto* matrix = new matrix_graph(size, density, false);
                    auto* list = new list_graph(*matrix);
                    for (int type : {0, 1}) {

                        if (type == 0) {
                            auto start_matrix = std::chrono::high_resolution_clock::now();
                            dijkstra.run(*matrix, 0, false);
                            auto end_matrix = std::chrono::high_resolution_clock::now();
                            auto duration_matrix = std::chrono::duration_cast<std::chrono::nanoseconds>(end_matrix - start_matrix).count();

                            sum_dijkstra_matrix += duration_matrix;
                            std::cout << "  ↳ (" << n + 1 << "/" << repetitions << ") Dijkstra runtime (matrix): " << duration_matrix << "ns" << std::endl;

                            auto start_list = std::chrono::high_resolution_clock::now();
                            dijkstra.run(*list, 0, false);
                            auto end_list = std::chrono::high_resolution_clock::now();
                            auto duration_list = std::chrono::duration_cast<std::chrono::nanoseconds>(end_list - start_list).count();

                            sum_dijkstra_list += duration_list;
                            std::cout << "  ↳ (" << n + 1 << "/" << repetitions << ") Dijkstra runtime (list): " << duration_list << "ns" << std::endl;
                        } else {
                            auto start_matrix = std::chrono::high_resolution_clock::now();
                            fordbellman.run(*matrix, 0, false);
                            auto end_matrix = std::chrono::high_resolution_clock::now();
                            auto duration_matrix = std::chrono::duration_cast<std::chrono::nanoseconds>(end_matrix - start_matrix).count();

                            sum_fordbellman_matrix += duration_matrix;
                            std::cout << "  ↳ (" << n + 1 << "/" << repetitions << ") Ford-Bellman runtime (matrix): " << duration_matrix << "ns" << std::endl;

                            auto start_list = std::chrono::high_resolution_clock::now();
                            fordbellman.run(*list, 0, false);
                            auto end_list = std::chrono::high_resolution_clock::now();
                            auto duration_list = std::chrono::duration_cast<std::chrono::nanoseconds>(end_list - start_list).count();

                            sum_fordbellman_list += duration_list;
                            std::cout << "  ↳ (" << n + 1 << "/" << repetitions << ") Ford-Bellman runtime (list): " << duration_list << "ns" << std::endl;
                        }

                    }
                    delete list;
                    delete matrix;
                }
                file_sp << sum_dijkstra_matrix / repetitions << "," << sum_dijkstra_list / repetitions << "," << sum_fordbellman_matrix / repetitions << "," << sum_fordbellman_list / repetitions << "\n";
                std::cout << " | Dijkstra (matrix)     avg.: " << sum_dijkstra_matrix / repetitions << "ns\n";
                std::cout << " | Dijkstra (list)       avg.: " << sum_dijkstra_list / repetitions << "ns\n";
                std::cout << " | Ford-Bellman (matrix) avg.: " << sum_fordbellman_matrix / repetitions << "ns\n";
                std::cout << " ↳ Ford-Bellman (list)   avg.: " << sum_fordbellman_list / repetitions << "ns\n";
            }
        }

        file_sp.close();
    });
    main_menu.add_option(8, "Zakoncz", [&main_menu] {
        std::cout << "[#] Koniec programu\n";
        main_menu.close();
    });
    main_menu.open();

    delete loaded_matrix_graph;
    delete loaded_list_graph;
    return 0;
}

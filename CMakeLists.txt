cmake_minimum_required(VERSION 3.28)
project(aizo_graphs)

set(CMAKE_CXX_STANDARD 17)

add_executable(aizo_graphs src/main.cpp
        src/list/linked_list.h
        src/list/node.h
        src/list/node.cpp
        src/graph/graph.h
        src/graph/graph.cpp
        src/graph/list/connection.h
        src/list/linked_list.cpp
        src/graph/matrix/matrix_graph.cpp
        src/graph/matrix/matrix_graph.h
        src/graph/list/list_graph.cpp
        src/graph/list/list_graph.h
        src/menu/menu.cpp
        src/menu/menu.h
        src/graph/list/connection.cpp
        src/graph/list/connection.h
        src/algorithm/algorithm.h
        src/algorithm/mst/prim_algorithm.cpp
        src/algorithm/mst/prim_algorithm.h
        src/algorithm/mst/kruskal_algorithm.cpp
        src/algorithm/mst/kruskal_algorithm.h
        src/algorithm/shortest/dijkstra_algorithm.cpp
        src/algorithm/shortest/dijkstra_algorithm.h
        src/algorithm/shortest/fordbellman_algorithm.cpp
        src/algorithm/shortest/fordbellman_algorithm.h)
#target_link_options(aizo_sorting_exe PRIVATE -static-libgcc -static-libstdc++ -static)
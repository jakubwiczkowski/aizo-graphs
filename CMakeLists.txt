cmake_minimum_required(VERSION 3.28)
project(aizo_graphs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

add_executable(aizo_graphs src/main.cpp
        src/graph/graph.h
        src/graph/graph.cpp
        src/graph/list/connection.h
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
        src/algorithm/shortest/fordbellman_algorithm.h
        src/list/pair.cpp
        src/list/pair.h
        src/list/list.cpp
        src/list/list.h
        src/list/heap.cpp
        src/list/heap.h
        src/algorithm/mst/helper/vertex_prim.h
        src/algorithm/mst/helper/edge_kruskal.h
        src/algorithm/shortest/helper/vertex_dijkstra.h)
#target_link_options(aizo_graphs PRIVATE -static-libgcc -static-libstdc++ -static)
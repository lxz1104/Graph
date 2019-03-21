cmake_minimum_required(VERSION 3.13)
project(Graph001 C)

set(CMAKE_C_STANDARD 99)

add_executable(Graph001 main.c MatrixGraph.c AdjListGraph.c)
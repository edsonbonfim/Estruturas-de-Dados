cmake_minimum_required(VERSION 3.10)
project(Grafo C)

set(CMAKE_C_STANDARD 99)

add_executable(Grafo main.c Lista.c Lista.h Grafo.c Grafo.h)
cmake_minimum_required(VERSION 3.21)
project(check C)

set(CMAKE_C_STANDARD 99)

add_executable(check main.c Priority_Queue.c Priority_Queue.h Graph.c Graph.h Graph_Algo.c Graph_Algo.h)

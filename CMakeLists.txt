cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        algorithms/Algorithms.cpp
        algorithms/Algorithms.h
        menu/Menu.cpp
        menu/Menu.h
        data_structures/Item.cpp
        data_structures/Item.h
)

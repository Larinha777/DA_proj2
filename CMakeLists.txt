cmake_minimum_required(VERSION 3.30)
project(DAProject2)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/ortools/include)
link_directories(${CMAKE_SOURCE_DIR}/ortools/lib)

add_executable(DAProject2 main.cpp
        algorithms/Algorithms.cpp
        menu/Menu.cpp
        data_structures/Item.cpp
        data_structures/DataStruct.cpp
)
target_link_libraries(DAProject2 ortools)
set_target_properties(DAProject2 PROPERTIES INSTALL_RPATH "${CMAKE_SOURCE_DIR}/ortools/lib")
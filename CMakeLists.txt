cmake_minimum_required(VERSION 3.30)
project(DAProject2)

set(CMAKE_CXX_STANDARD 20)

if(APPLE)
    set(ORTOOLS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/ortools/macos/include)
    set(ORTOOLS_LIB_DIR ${CMAKE_SOURCE_DIR}/ortools/macos/lib)
elseif(UNIX)
    set(ORTOOLS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/ortools/linux/include)
    set(ORTOOLS_LIB_DIR ${CMAKE_SOURCE_DIR}/ortools/linux/lib)
endif()

include_directories(${ORTOOLS_INCLUDE_DIR})
link_directories(${ORTOOLS_LIB_DIR})

add_executable(DAProject2
        main.cpp
        algorithms/Algorithms.cpp
        menu/Menu.cpp
        data_structures/Item.cpp
        data_structures/DataStruct.cpp
)

target_link_libraries(DAProject2 ortools)

# Ensure rpath is set properly for runtime linking
set_target_properties(DAProject2 PROPERTIES INSTALL_RPATH "${ORTOOLS_LIB_DIR}")
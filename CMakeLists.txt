cmake_minimum_required(VERSION 3.14)
project(zhao-json LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(CMAKE_BUILD_TESTS "Enable testing of the zhao-json library." OFF)
option(CMAKE_BUILD_BENCHMARK "Enable benchmark test." OFF)
option(CMAKE_BUILD_EXAMPLES "Enable building examples." ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_FLAGS
        -fno-omit-frame-pointer # linux perf
        -Wall
        -Wextra
        -Werror
        -Wconversion
        -Wno-unused-parameter
        -Wold-style-cast
        -Woverloaded-virtual
        -Wpointer-arith
        -Wshadow
        -Wwrite-strings
        -std=c++17
        -march=native
        -rdynamic)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
message("CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

message("PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(include)

message("CMAKE_BUILD_TESTS: ${CMAKE_BUILD_TESTS}")

if(CMAKE_BUILD_TESTS)
    add_subdirectory(test)
endif()
if(CMAKE_BUILD_BENCHMARK)
    set(BENCHMARK_ENABLE_TESTING OFF)
    set(BENCHMARK_ENABLE_INSTALL OFF)
    set(CMAKE_CXX_FLAGS
        -fno-omit-frame-pointer # linux perf
        -Wall
        -Wextra
        -Werror
        # -Wconversion #benchmark converts long int to double
        -Wno-unused-parameter
        -Wold-style-cast
        # -Woverloaded-virtual #benchmark overrides virtual
        -Wpointer-arith
        -Wshadow
        -Wwrite-strings
        -std=c++17
        -march=native
        -rdynamic)
    string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    add_subdirectory(bench)
    add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/benchmark)
endif()
if (CMAKE_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

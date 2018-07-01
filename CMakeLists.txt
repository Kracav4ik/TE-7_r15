cmake_minimum_required(VERSION 3.11)
project(TE-7_r15)

# CMake debug
# set(CMAKE_VERBOSE_MAKEFILE on)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# SDL2 setup
set(SDL2_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2-devel-2.0.8-mingw")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

include_directories(src)

add_subdirectory(src)

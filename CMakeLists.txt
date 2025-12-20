cmake_minimum_required(VERSION 3.10)
project(PuttIt)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)
find_package(GTest REQUIRED)

add_subdirectory(code/tests)
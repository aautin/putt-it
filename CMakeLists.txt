cmake_minimum_required(VERSION 3.10)
project("Putt-It")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CPack)
include(CTest)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(GTest REQUIRED)

add_subdirectory(code/core)
add_subdirectory(code/main)
add_subdirectory(code/tests)
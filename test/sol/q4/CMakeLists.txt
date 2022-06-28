cmake_minimum_required(VERSION 2.8)
project(q4)

add_library(q4_func func.cpp)
add_executable(q4 main.cpp)
target_link_libraries(q4 q4_func)
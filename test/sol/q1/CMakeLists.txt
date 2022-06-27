cmake_minimum_required(VERSION 2.8)
project(q1)

add_library(q1_func func.cpp)
add_executable(q1 main.cpp)
target_link_libraries(q1 q1_func)
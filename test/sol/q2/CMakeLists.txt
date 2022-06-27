cmake_minimum_required(VERSION 2.8)
project(q2)

add_library(q2_func func.cpp)
add_executable(q2 main.cpp)
target_link_libraries(q2 q2_func)
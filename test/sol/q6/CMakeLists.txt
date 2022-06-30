cmake_minimum_required(VERSION 2.8)
project(q6)

add_library(q6_func func.cpp)
add_executable(q6 main.cpp)
target_link_libraries(q6 q6_func)
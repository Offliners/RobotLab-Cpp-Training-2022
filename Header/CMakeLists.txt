cmake_minimum_required(VERSION 2.8)
project(Header)

add_library(func func.cpp)
add_executable(header main.cpp)
target_link_libraries(header func)
cmake_minimum_required(VERSION 3.21)
project(teste C)

set(CMAKE_C_STANDARD 99)

add_executable(teste main.c)

target_link_libraries(teste m)
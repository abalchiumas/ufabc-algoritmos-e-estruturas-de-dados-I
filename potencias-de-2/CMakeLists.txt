cmake_minimum_required(VERSION 3.21)
project(potencias_de_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(potencias_de_2 main.c)

target_link_libraries(potencias_de_2 m)
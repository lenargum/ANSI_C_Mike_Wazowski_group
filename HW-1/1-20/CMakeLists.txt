cmake_minimum_required(VERSION 3.10)
project(1_20 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(1_20
        src/detab.c
        src/detab.h)

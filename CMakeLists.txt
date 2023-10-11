cmake_minimum_required(VERSION 3.26)
project(WordGenetics)

set(CMAKE_CXX_STANDARD 17)

add_executable(WordGenetics main.cpp
        DNA.cpp
        DNA.h
        Population.cpp
        Population.h)

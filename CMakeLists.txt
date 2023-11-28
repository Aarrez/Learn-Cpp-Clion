cmake_minimum_required(VERSION 3.27)
project(GraphProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(GraphProject
        main.cpp
        main.h
        GraphImport.cpp
        GraphImport.h
)

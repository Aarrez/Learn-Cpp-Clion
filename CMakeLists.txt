cmake_minimum_required(VERSION 3.26)
project(LearningCpp)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(LearningCpp
        DataStuctureAssignment/main.cpp
        DataStuctureAssignment/main.h
)

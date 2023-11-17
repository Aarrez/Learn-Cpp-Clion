cmake_minimum_required(VERSION 3.26)
project(LearningCpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion")



add_executable(LearningCpp
        DataStuctureAssignment/InsertionSort.h
        DataStuctureAssignment/InsertionSort.cpp
        DataStuctureAssignment/UnsortedVector.cpp
        DataStuctureAssignment/UnsortedVector.h

)

cmake_minimum_required(VERSION 3.26)
project(LearningCpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(LearningCpp
        MiscellaneousCode/HashMap.h
        MiscellaneousCode/HashMap.cpp
)

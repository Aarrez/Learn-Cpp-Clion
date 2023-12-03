cmake_minimum_required(VERSION 3.26)
project(SortingAlgorithms)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(SortingAlgorithms
        DataStructure/main.h

        DataStructure/SimpleSorting/BubbleSort.cpp
        DataStructure/SimpleSorting/BubbleSort.h
        DataStructure/SimpleSorting/CountSort.cpp
        DataStructure/SimpleSorting/CountSort.h
        DataStructure/SimpleSorting/InsertionSort.cpp
        DataStructure/SimpleSorting/InsertionSort.h
        DataStructure/SimpleSorting/SelectionSort.cpp
        DataStructure/SimpleSorting/SelectionSort.h


        DataStructure/AdvancedSorting/HeapSort.cpp
        DataStructure/AdvancedSorting/HeapSort.h
        DataStructure/AdvancedSorting/MergeSort.cpp
        DataStructure/AdvancedSorting/MergeSort.h
        DataStructure/AdvancedSorting/QuickSort.cpp
        DataStructure/AdvancedSorting/QuickSort.h

        DataStructure/main.cpp
)

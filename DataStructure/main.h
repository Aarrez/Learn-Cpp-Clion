#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <queue>

//Advanced sorting algorithms header files
#include "AdvancedSorting/HeapSort.h"
#include "AdvancedSorting/MergeSort.h"
#include "AdvancedSorting/QuickSort.h"

//Simple sorting algorithms header files
#include "SimpleSorting/SelectionSort.h"
#include "SimpleSorting/BubbleSort.h"
#include "SimpleSorting/CountSort.h"
#include "SimpleSorting/InsertionSort.h"



template<typename T>
void print_two_vector(std::vector<std::vector<T>> &two_vector, std::vector<std::vector<double>> &time_keeper)
{

    double sum {0};
    double worst {0};
    double best {10};
    for (int i = 0; i < two_vector.size()-1; ++i)
    {
        std::cout << "size: " << two_vector[i].size() << std::endl;
        for(auto a : time_keeper[i])
        {
            sum += a;
            if(worst < a) worst = a;
            if(best > a) best = a;
        }
        double avrage = sum / time_keeper[i].size();
        std::cout << "Avrage Time in seconds: " << avrage << std::endl;
        std::cout << "Worst Time: " << worst << std::endl;
        std::cout << "Best Time: " << best << std::endl;
    }
}

inline void contruct_sorting_table()
{

}

namespace sorting_Algorithms
{
    //Measure Sorting Algorithms
    class M_S_A
    {
        int count_;
    public:
        explicit M_S_A(const int count)
        {
            this->count_ = count;
        }
        std::chrono::time_point<std::chrono::system_clock> start, last;

        //advanced sorting algorithms
        void h_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            std::vector<std::vector<double>> time_keeper;
            time_keeper.reserve(vector_list.size());
            for (int i = 0; i < vector_list.size(); i++)
            {
                int size = vector_list[i].size();
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    heap_sort_func(vector_list[i], size);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds.count());
                }
            }

            print_two_vector(vector_list, time_keeper);
        }
        void m_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            std::vector<std::vector<double>> time_keeper;
            time_keeper.reserve(vector_list.size());
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    merge_sort_func(vector_list[i]);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds.count());
                }
            }

            print_two_vector(vector_list, time_keeper);
        }
        void q_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            std::vector<std::vector<double>> time_keeper;
            time_keeper.reserve(vector_list.size());
            for (int i = 0; i < vector_list.size(); i++)
            {
                int size = vector_list[i].size();
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    quick_sort_func(vector_list[i], size);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds.count());
                }
            }

            print_two_vector(vector_list, time_keeper);
        }

        //simple soritng alogrithms
        void b_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            std::vector<std::vector<double>> time_keeper;
            time_keeper.reserve(vector_list.size());
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    bubble_sort_func(vector_list[i]);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds.count());
                }
            }

            print_two_vector(vector_list, time_keeper);
        }
        void c_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            std::vector<std::vector<double>> time_keeper;
            time_keeper.reserve(vector_list.size());
            for (int i = 0; i < vector_list.size(); i++)
            {
                int size = vector_list[i].size();
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    count_sort_func(vector_list[i], size);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds.count());
                }
            }

            print_two_vector(vector_list, time_keeper);

        }
        void i_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            std::vector<std::vector<double>> time_keeper;
            time_keeper.reserve(vector_list.size());
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    insertion_sort_func(vector_list[i]);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds.count());
                }
            }

            print_two_vector(vector_list, time_keeper);
        }
        void s_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            std::vector<std::vector<double>> time_keeper;
            time_keeper.reserve(vector_list.size());
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    selection_sort_func(vector_list[i]);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds.count());
                }
            }

            print_two_vector(vector_list, time_keeper);
        }

    };
}



#endif //MAIN_H

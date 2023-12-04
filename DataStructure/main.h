#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <queue>
#include <fstream>

//Advanced sorting algorithms header files
#include "AdvancedSorting/HeapSort.h"
#include "AdvancedSorting/MergeSort.h"
#include "AdvancedSorting/QuickSort.h"

//Simple sorting algorithms header files
#include "SimpleSorting/SelectionSort.h"
#include "SimpleSorting/BubbleSort.h"
#include "SimpleSorting/CountSort.h"
#include "SimpleSorting/InsertionSort.h"



inline void print_two_vector
(std::vector<std::vector<int>> &two_vector,
    std::vector<std::vector<std::chrono::duration<double>>> &time_keeper,
    std::vector<std::queue<double>> &table_contents)
{
    double sum {0};
    double worst {0};
    double best {10};
    double avrage {0};
    for (int i = 0; i < two_vector.size()-1; ++i)
    {
        std::cout << "size: " << two_vector[i].size() << std::endl;
        for (int j = 0; j < two_vector[i].size()-1; ++j)
        {
            auto duration_ = time_keeper[i][j];
            double a = duration_.count();
            sum += a;
            if(worst < a) worst = a;
            if(best > a) best = a;
            avrage = sum / time_keeper[i].size();
            table_contents[j].push(avrage);
        }
        std::cout << "Avrage Time in seconds: " << avrage << std::endl;
        std::cout << "Worst Time: " << worst << std::endl;
        std::cout << "Best Time: " << best << std::endl;
    }
}

inline int populate_sorting_table(std::vector<std::queue<double>> &table_contests)
{
    std::fstream ifile;
    std::ofstream ofile;
    ifile.open("TableSortiongAlgorithms.txt");
    ofile.open("OutputFile.txt");
    if(!ifile || !ofile)
    {
        std::cerr << "Files could not be opend";
        return 1;
    }
    int i {0};
    std::string line;
    while(std::getline(ifile, line))
    {
        while ( line.find('#') != std::string::npos)
        {
            if(table_contests.empty())
            {
                std::cerr << "There are no contents in the table queue";
                return 1;
            }
            std::string number = std::to_string(table_contests[i].front());
           table_contests[i].pop();
           line.replace(line.find('#'), 1, number);
           if(table_contests[i].empty())
               i++;
        }
        ofile << line << "\n";
    }
    return 0;
}

namespace sorting_Algorithms
{
    //Measure Sorting Algorithms
    class M_S_A
    {
        int count_;
    public:
        std::vector<std::queue<double>> table_content;
        std::vector<std::vector<std::chrono::duration<double>>> time_keeper;
        std::chrono::time_point<std::chrono::system_clock> start, last;

        explicit M_S_A(const int count)
        {
            this->count_ = count;
            table_content.resize(count);
            time_keeper.reserve(count);
        }

        //advanced sorting algorithms
        void h_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            for (int i = 0; i < vector_list.size(); i++)
            {
                int size = vector_list[i].size();
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    heap_sort_func(vector_list[i], size);
                    last = std::chrono::system_clock::now();

                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds);
                }
            }

            print_two_vector(vector_list, time_keeper, table_content);
        }
        void m_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    merge_sort_func(vector_list[i]);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds);
                }
            }

            print_two_vector(vector_list, time_keeper, table_content);
        }
        void q_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                int size = vector_list[i].size();
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    quick_sort_func(vector_list[i], size);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds);
                }
            }

            print_two_vector(vector_list, time_keeper, table_content);
        }

        //simple soritng alogrithms
        void b_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    bubble_sort_func(vector_list[i]);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds);
                }
            }

            print_two_vector(vector_list, time_keeper, table_content);
        }
        void c_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                int size = vector_list[i].size();
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    count_sort_func(vector_list[i], size);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds);
                }
            }

            print_two_vector(vector_list, time_keeper, table_content);

        }
        void i_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    insertion_sort_func(vector_list[i]);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds);
                }
            }

            print_two_vector(vector_list, time_keeper, table_content);
        }
        void s_measure_sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    selection_sort_func(vector_list[i]);
                    last = std::chrono::system_clock::now();
                    std::chrono::duration_cast<std::chrono::milliseconds>(last - start);
                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds);
                }
            }

            print_two_vector(vector_list, time_keeper, table_content);
        }

    };
}



#endif //MAIN_H

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
    std::vector<std::vector<double>> &table_contents)
{
    double worst {0};
    double best {10};
    double avrage {0};
    for (int i = 0; i < two_vector.size(); ++i)
    {
        double sum {0};
        // std::cout << "size: " << two_vector[i].size() << std::endl;
        for (int j = 0; j < two_vector[i].size()-1; ++j)
        {
            auto duration = time_keeper[i][j];
            double a = duration.count();
            sum += a;
            if(worst < a) worst = a;
            if(best > a) best = a;
        }
        avrage = sum / time_keeper[i].size();
        table_contents[i].push_back(avrage);
        // std::cout << "Avrage Time in seconds: " << avrage << std::endl;
        // std::cout << "Worst Time: " << worst << std::endl;
        // std::cout << "Best Time: " << best << std::endl;
    }
}

inline int populate_sorting_table(std::vector<std::vector<double>> &table_contests)
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
    while (std::getline(ifile, line))
    {
        if(line.find('@') != std::string::npos)
        {
            std::string s {"Unsorted Vector Results(Avrage)"};
            line.replace(line.find('@'), 1, s);
            ofile << line << "\n";
            break;
        }
        ofile << line << "\n";
    }
    line.clear();
    while(std::getline(ifile, line))
    {
        while ( line.find('#') != std::string::npos)
        {
            if(table_contests[i].empty())
            {
                std::cerr << "There are no contents in the table list";
                return 1;
            }
            std::string number = std::to_string(table_contests[i].front());
            table_contests[i].erase(table_contests[i].begin());
            line.replace(line.find('#'), 1, number);
            if(table_contests[i].empty())
            {
                i++;
                break;
            }
        }
        ofile << line << "\n";
    }
    return 0;
}

namespace sorting_algorithms
{
    //Measure Sorting Algorithms
    class M_S_A
    {
        int iter_count_;
    public:
        std::vector<std::vector<double>> table_content;
        std::vector<std::vector<std::chrono::duration<double>>> time_keeper;
        std::chrono::time_point<std::chrono::system_clock> start, last;

        explicit M_S_A(const int iter_count, const int data_count)
        {
            this->iter_count_ = iter_count;
            //Reserve the number of data
            table_content.reserve(data_count);
            time_keeper.reserve(data_count);
        }

        //advanced sorting algorithms
        void H_Measure_Sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                int size = vector_list[i].size();
                for(int j = 0; j < iter_count_; j++)
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
        void M_Measure_Sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < iter_count_; j++)
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
        void Q_Measure_Sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                int size = vector_list[i].size();
                for(int j = 0; j < iter_count_; j++)
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
        void B_Measure_Sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < iter_count_; j++)
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
        void C_Measure_Sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                int size = vector_list[i].size();
                for(int j = 0; j < iter_count_; j++)
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
        void I_Measure_Sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < iter_count_; j++)
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
        void S_Measure_Sort(std::vector<std::vector<int>> &vector_list)
        {
            time_keeper.clear();
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < iter_count_; j++)
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

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



inline std::vector<std::chrono::duration<double>> insertion_sort(std::vector<std::chrono::duration<double>> vector_list)
{
    for(unsigned long i = 0; i < vector_list.size(); i++)
    {
        unsigned long j = i;
        while (j > 0 && vector_list[j].count() < vector_list[j-1].count())
        {
            std::iter_swap(vector_list.begin() + j, vector_list.begin() + (j-1));
            j--;
        }
    }
    return vector_list;
}

inline void create_table_content
(std::vector<std::vector<int>> &two_vector,
    std::vector<std::vector<std::chrono::duration<double>>> &time_keeper,
    std::vector<std::vector<double>> &avrage_table,
    std::vector<std::vector<double>> &max_table,
    std::vector<std::vector<double>> &min_table,
    std::vector<std::vector<double>> &median_table)

{
    double max {0};
    double min {10};
    for (int i = 0; i < two_vector.size(); ++i)
    {
        double sum {0};
        // std::cout << "size: " << two_vector[i].size() << std::endl;
        for (int j = 0; j < two_vector[i].size()-1; ++j)
        {
            auto duration = time_keeper[i][j];
            double a = duration.count();
            sum += a;
            if(max < a) max = a;
            if(min > a) min = a;
        }

        double avrage = sum / time_keeper[i].size();
        avrage_table[i].push_back(avrage);
        max_table[i].push_back(max);
        min_table[i].push_back(min);
        auto sorted_keeper {insertion_sort(time_keeper[i])};
        double median;
        if((sorted_keeper.size() % 2) == 0)
        {
            median = sorted_keeper.size()/2;
        }
        else
        {
            double f = std::floor(sorted_keeper.size()/2.0);
            double s = std::ceil(sorted_keeper.size()/2.0);
            median = (s + f)/ 2.0;
        }

        median = time_keeper[i][median].count();
        median_table[i].push_back(median);


        // std::cout << "Avrage Time in seconds: " << avrage << std::endl;
        // std::cout << "Worst Time: " << worst << std::endl;
        // std::cout << "Best Time: " << best << std::endl;
    }
}
/* Deprecated code
inline int populate_sorting_table(std::vector<std::vector<double>> &table_contests)
{
    std::fstream ifile;
    std::ofstream ofile;
    ifile.open("SortingTables/TemplateTable.txt");
    ofile.open("SortingTables/Unsorted_Avrage.txt");
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
*/
inline int print_table(std::vector<std::vector<double>> &table_contests, const char* file, const std::string &header)
{
    std::fstream ifile;
    std::ofstream ofile;
    ifile.open("SortingTables/TemplateTable.txt");
    ofile.open(file);
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
            std::string s {header};
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
        int data_count_;
    public:
        std::vector<std::vector<double>> avrage_table, median_table, max_table, min_table;
        std::vector<std::vector<std::chrono::duration<double>>> time_keeper;
        std::chrono::time_point<std::chrono::system_clock> start, last;

        explicit M_S_A(const int iter_count, const int data_count)
        {
            this->iter_count_ = iter_count;
            this->data_count_ = data_count;
            avrage_table.reserve(data_count);
            median_table.reserve(data_count);
            max_table.reserve(data_count);
            min_table.reserve(data_count);
        }

        void invoke_Algorithm(
            std::vector<std::vector<int>> &vector_list,
            void (*func)(std::vector<int> &list))
        {
            std::vector<std::vector<std::chrono::duration<double>>> time_keeper;
            time_keeper.reserve(data_count_);
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < iter_count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    func(vector_list[i]);
                    last = std::chrono::system_clock::now();

                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds);
                }
            }
            return create_table_content(vector_list, time_keeper,
                avrage_table,
                max_table,
                min_table,
                median_table);
        }

        void invoke_Algorithm(
            std::vector<std::vector<int>> &vector_list,
            void (*func)(std::vector<int> &list, int a))
        {
            std::vector<std::vector<std::chrono::duration<double>>> time_keeper;
            time_keeper.reserve(data_count_);
            for (int i = 0; i < vector_list.size(); i++)
            {
                for(int j = 0; j < iter_count_; j++)
                {
                    start = std::chrono::system_clock::now();
                    func(vector_list[i], vector_list[i].size());
                    last = std::chrono::system_clock::now();

                    std::chrono::duration<double> elapsed_seconds = last - start;
                    time_keeper[i].push_back(elapsed_seconds);
                }
            }
            return create_table_content(vector_list, time_keeper,
                avrage_table,
                max_table,
                min_table,
                median_table);
        }
        /* depricated code
        //advanced sorting algorithms
        void h_Measure_Sort(std::vector<std::vector<int>> &vector_list)
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
        void m_Measure_Sort(std::vector<std::vector<int>> &vector_list)
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
        void q_Measure_Sort(std::vector<std::vector<int>> &vector_list)
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
        void b_Measure_Sort(std::vector<std::vector<int>> &vector_list)
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
        void c_Measure_Sort(std::vector<std::vector<int>> &vector_list)
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
        void i_Measure_Sort(std::vector<std::vector<int>> &vector_list)
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
        void s_Measure_Sort(std::vector<std::vector<int>> &vector_list)
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
        */
    };
}



#endif //MAIN_H

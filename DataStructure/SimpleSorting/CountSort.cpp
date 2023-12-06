#include "CountSort.h"
#include <iostream>

namespace sorting_algorithms
{
    void count_sort_func(std::vector<int> &vector_list, const int amount)
    {
        vector_list = countSort::CountSort(vector_list, amount);

    }
}

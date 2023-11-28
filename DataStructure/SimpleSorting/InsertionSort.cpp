#include "InsertionSort.h"
#include <iostream>

namespace sorting_algorithms
{
    std::vector<int> InsertionSortFunc(std::vector<int> vector_list)
    {
        InsertionSort::SortVector(vector_list);
        return vector_list;
    }
}

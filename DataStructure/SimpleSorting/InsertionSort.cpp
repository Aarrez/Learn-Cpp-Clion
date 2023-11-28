#include "InsertionSort.h"
#include <iostream>

namespace sortingAlgorithms
{
    std::vector<int> InsertionSortFunc(std::vector<int> vector_list)
    {
        InsertionSort::SortVector(vector_list);
        return vector_list;
    }
}

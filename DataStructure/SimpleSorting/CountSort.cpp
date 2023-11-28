#include "CountSort.h"
#include <iostream>

namespace sorting_algorithms
{
    std::vector<int> CountSortFunc(std::vector<int> vector_list, const int amount)
    {
        std::vector<int> result = countSort::CountSort(vector_list, amount);

        return result;
    }
}

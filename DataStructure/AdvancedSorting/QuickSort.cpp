#include "QuickSort.h"
#include <iostream>

namespace sorting_algorithms
{
    std::vector<int> QuickSortFunc(std::vector<int> vector_list, int &amount)
    {
        QSort::quickSort(vector_list, amount - 1, 0);

        return vector_list;
    }
}


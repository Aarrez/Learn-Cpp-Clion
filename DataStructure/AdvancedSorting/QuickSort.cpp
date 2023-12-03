#include "QuickSort.h"
#include <iostream>

namespace sorting_Algorithms
{
    void quick_sort_func(std::vector<int> &vector_list, int amount)
    {
        QSort::quickSort(vector_list, amount - 1, 0);
    }
}


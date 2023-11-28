#include "SelectionSort.h"

namespace sorting_algorithms
{
    std::vector<int> SelectionSortFunc(std::vector<int> vector_list)
    {
        SelectionSort::selectionSort(vector_list);

        return vector_list;
    }
}


#include "SelectionSort.h"

namespace sortingAlgorithms
{
    std::vector<int> SelectionSortFunc(std::vector<int> vector_list)
    {
        SelectionSort::selectionSort(vector_list);

        return vector_list;
    }
}


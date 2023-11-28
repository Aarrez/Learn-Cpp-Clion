#include "HeapSort.h"

namespace sortingAlgorithms
{
    std::vector<int> HeapSortFunc(std::vector<int> vector_list, int amount)
    {
        heap_sort heapSort(amount);

        heapSort.HeapSort(vector_list);

        return vector_list;
    }
}


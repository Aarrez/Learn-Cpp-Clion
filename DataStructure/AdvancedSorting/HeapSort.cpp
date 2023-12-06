#include "HeapSort.h"

namespace sorting_algorithms
{
    void heap_sort_func(std::vector<int> &vector_list, int amount)
    {
        Heap_Sort heapSort(amount);

        heapSort.heap_sort(vector_list);

    }
}


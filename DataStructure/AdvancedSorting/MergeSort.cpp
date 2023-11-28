#include "MergeSort.h"
#include <iostream>

namespace sortingAlgorithms
{
    std::vector<int> MergeSortFunc(std::vector<int> vector_list)
    {
        std::vector<int> result = MergeSort::top_merge_sort(vector_list);

        return result;
    }

}

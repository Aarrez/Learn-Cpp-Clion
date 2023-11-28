#include "BubbleSort.h"
#include <iostream>

namespace sortingAlgorithms
{
    std::vector<int> BubbleSortFunc(std::vector<int> vector_list)
    {
        BubbleSort::bubbleSort(vector_list);

        return vector_list;
    }
}

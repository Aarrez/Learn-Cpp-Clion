#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <iostream>
#include <algorithm>

namespace sorting_algorithms
{
    class SelectionSort
    {
    public:
        static void selectionSort(std::vector<int> &vector_list)
        {
            const int size = static_cast<int>(vector_list.size()) - 1;
            for(int i = 0; i < size; i++)
            {
                int jMin = i;
                for (int j = i + 1; j < size + 1; ++j)
                {
                    //Find the smallest number in the list
                    if(vector_list[j] < vector_list[jMin])
                    {
                        jMin = j;
                    }
                }

                if(vector_list[jMin] != vector_list[i])
                {
                    iter_swap(vector_list.begin() + jMin, vector_list.begin() + i);
                }
            }
        }
    };


    std::vector<int> SelectionSortFunc(std::vector<int> vector_list);

}

#endif //SELECTIONSORT_H

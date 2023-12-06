#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <vector>

namespace sorting_algorithms
{
    class InsertionSort
    {
    public:
        static void SortVector(std::vector<int> &vector_list)
        {
            for(unsigned long i = 0; i < vector_list.size(); i++)
            {
                unsigned long j = i;
                while (j > 0 && vector_list[j] > vector_list[j-1])
                {
                    int a = vector_list[j];
                    vector_list[j] = vector_list[j-1];
                    vector_list[j-1] = a;
                    j--;
                }
            }
        };
    };

    void insertion_sort_func(std::vector<int> &vector_list);
}

#endif //INSERTIONSORT_H

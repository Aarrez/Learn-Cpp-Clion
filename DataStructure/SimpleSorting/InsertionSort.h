#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <vector>

namespace sorting_algorithms
{
    class InsertionSort
    {
    public:
        static void sort_Vector(std::vector<int> &vector_list)
        {
            for(unsigned long i = 0; i < vector_list.size(); i++)
            {
                unsigned long j = i;
                while (j > 0 && vector_list[j] > vector_list[j-1])
                {
                    auto a = vector_list.begin() + j;
                    auto b = vector_list.begin() + (j -1);
                    std::iter_swap(a, b);
                    j--;
                }
            }
        };
    };
    void insertion_sort_func(std::vector<int> &vector_list);
}

#endif //INSERTIONSORT_H

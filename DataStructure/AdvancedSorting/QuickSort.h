#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>

namespace sorting_algorithms
{
    class QSort
    {
        static int myPartition(std::vector<int> &vector_list, int hi, int lo)
        {
            const int a = ((hi - lo)/2) + lo;
            const int pivot = vector_list[static_cast<unsigned long>(a)];

            int i = lo - 1;
            int j = hi + 1;

            while(true)
            {
                do
                {
                    i++;
                }
                while(pivot < vector_list[static_cast<size_t>(i)]);

                do
                {
                    j--;
                }while(pivot > vector_list[static_cast<size_t>(j)]);

                if(i >= j) return static_cast<int>(j);

                const int b = vector_list.at(static_cast<size_t>(i));
                vector_list[static_cast<size_t>(i)] = vector_list[static_cast<size_t>(j)];
                vector_list[static_cast<size_t>(j)] = b;
            }
        }
    public:
        static void quickSort(std::vector<int> &vector_list, int hi, int lo)
        {
            int p;
            if(lo >= 0 && hi >= 0 && lo < hi)
            {
                p = myPartition(vector_list, hi, lo);
                quickSort(vector_list, p, lo);
                quickSort(vector_list, hi, p + 1);
            }
        }
    };

    void quick_sort_func(std::vector<int> &vector_list, int amount);

}

#endif //QUICKSORT_H

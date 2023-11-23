#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>

class QSort
{
    int myPartition(std::vector<int> &vector_list, int hi, int lo)
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
    QSort(std::vector<int> &vector_list, int size)
    {
        srand(static_cast<unsigned>(time(NULL)));
        for (int i = 0; i < size; ++i)
        {
            int random = rand() % size + 1;
            vector_list.push_back(random);
        }
    };
    QSort();
    void quickSort(std::vector<int> &vector_list, int hi, int lo)
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
#endif //QUICKSORT_H

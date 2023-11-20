#include "QuickSort.h"
#include <iostream>

int QSort :: myPartition(std::vector<int> &vector_list, const int hi, const int lo)
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

void QSort :: quickSort(std::vector<int> &vector_list, const int hi, const int lo)
{
    int p;
    if(lo >= 0 && hi >= 0 && lo < hi)
    {
        p = myPartition(vector_list, hi, lo);
        quickSort(vector_list, p, lo);
        quickSort(vector_list, hi, p + 1);
    }
}

int main()
{
    std::vector<int> vector_list;
    QSort q_sort(vector_list, 100);
    int i = vector_list[1];
    for(int i : vector_list)
    {
        std::cout << i << " ";
    }
    std::cout << "\n" << "--------------------" << std::endl;
    q_sort.quickSort(vector_list, static_cast<int>(vector_list.size()) - 1, 0);

    for(const int i : vector_list)
    {
        std::cout << i << " ";
    }
}

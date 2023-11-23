#include "QuickSort.h"
#include <iostream>

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

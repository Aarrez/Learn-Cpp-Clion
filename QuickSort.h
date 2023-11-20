#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>

class QSort
{
    int myPartition(std::vector<int> &vector_list, int hi, int lo);
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
    void quickSort(std::vector<int> &vector_list, int hi, int lo);
};
#endif //QUICKSORT_H

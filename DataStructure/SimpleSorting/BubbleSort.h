#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <vector>
#include <algorithm>

namespace sortingAlgorithms
{
    class BubbleSort
    {
    public:
        static void bubbleSort(std::vector<int> &vector_list)
        {
            int size = static_cast<int>(vector_list.size());
            do
            {
                int a = 0;
                for(int i = 1; i < size; i++)
                {
                    if(vector_list[i -1] > vector_list[i])
                    {
                        std::iter_swap(vector_list.begin() + i, vector_list.begin() + i - 1);
                        a = i;
                    }
                }
                size = a;
            }while(size >= 1);
        }
    };

    std::vector<int> BubbleSortFunc(std::vector<int> vector_list);
}


#endif //BUBBLESORT_H

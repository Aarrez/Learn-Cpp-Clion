#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <vector>
#include <algorithm>

namespace sorting_algorithms
{
    class heap_sort
    {
        int size;
        void BuildMaxHeap(std::vector<int> &vector_list)
        {
            size = vector_list.size() -1;
            int a = size/2;
            for(int i = a; i >= 0; i--)
            {
                Heapify(vector_list, i);
            }
        }

        void Heapify(std::vector<int> &vector_list , int i)
        {
            int left = 2 * i;
            int right = (2 * i) + 1;
            int max;
            if(left <= size && vector_list[left] > vector_list[i])
            {
                max = left;
            }
            else
            {
                max = i;
            }

            if(right <= size && vector_list[right] > vector_list[max])
            {
                max = right;
            }

            if(max != i)
            {
                auto a = vector_list.begin() + i;
                auto b = vector_list.begin() + max;
                std::iter_swap(a, b);
                Heapify(vector_list, max);
            }
        }

    public:

        explicit heap_sort(int size)
        {
            this->size = size;
        }

        void HeapSort(std::vector<int> &vector_list)
        {
            BuildMaxHeap(vector_list);
            for (int i = size; i >= 0; i--)
            {
                std::iter_swap(vector_list.begin(), vector_list.begin() + i);
                size--;
                Heapify(vector_list, 0);
            }
        }


    };

    std::vector<int> HeapSortFunc(std::vector<int> vector_list, int amount);

}

#endif //HEAPSORT_H

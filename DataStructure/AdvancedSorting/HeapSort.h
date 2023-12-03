#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <vector>
#include <algorithm>

namespace sorting_Algorithms
{
    class Heap_Sort
    {
        int size_;
        void build_max_heap(std::vector<int> &vector_list)
        {
            size_ = vector_list.size() -1;
            int a = size_/2;
            for(int i = a; i >= 0; i--)
            {
                heapify(vector_list, i);
            }
        }

        void heapify(std::vector<int> &vector_list ,const int i)
        {
            int left = 2 * i;
            int right = (2 * i) + 1;
            int max;
            if(left <= size_ && vector_list[left] > vector_list[i])
            {
                max = left;
            }
            else
            {
                max = i;
            }

            if(right <= size_ && vector_list[right] > vector_list[max])
            {
                max = right;
            }

            if(max != i)
            {
                auto a = vector_list.begin() + i;
                auto b = vector_list.begin() + max;
                std::iter_swap(a, b);
                heapify(vector_list, max);
            }
        }

    public:

        explicit Heap_Sort(const int size)
        {
            this->size_ = size;
        }

        void heap_sort(std::vector<int> &vector_list)
        {
            build_max_heap(vector_list);
            for (int i = size_; i >= 0; i--)
            {
                std::iter_swap(vector_list.begin(), vector_list.begin() + i);
                size_--;
                heapify(vector_list, 0);
            }
        }


    };

    void heap_sort_func(std::vector<int> &vector_list, int amount);

}

#endif //HEAPSORT_H

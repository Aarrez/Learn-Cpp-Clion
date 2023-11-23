#include "MergeSort.h"
#include <iostream>

int main()
{
    std::vector<int> vector_list;
    int amount {100};
    unsigned seed = time(nullptr);
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, amount);
    vector_list.reserve(amount);
    for (int i = 0; i < amount; ++i)
    {
        vector_list.push_back(distribution(generator));
    }
    int iterations {10};
    int sum {0};
    for (int i = 0; i < iterations; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> list = TopDownMSort::merge_sort(vector_list);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        sum += static_cast<int>(duration.count());
    }
    int avrage = sum/iterations;


    std::cout << "\n" <<"Time in microseconds: " << avrage;


    return 0;
}
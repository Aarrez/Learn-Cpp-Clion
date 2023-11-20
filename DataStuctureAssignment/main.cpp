#include "main.h"
#include <iostream>

std::vector<int> CSort::CountSort(std::vector<int> input, int k)
{
    std::vector<int> output;
    output.resize(input.size() - 1);
    std::vector<int> count;
    count.resize(static_cast<size_t>(k + 1));

    for (int i = 0; i <= input.size() -1; ++i)
    {
        count[input[i]] = count[input[i]] + 1;
    }

    for (int i = 1; i <= k; ++i)
    {
        count[i] = count[i] + count[i-1];
    }

    for (int i = input.size() - 1; i >= 0; --i)
    {
        count[input[i]] = count[input[i]] - 1;
        output[count[i]] = input[i];
    }
    return output;
}


int main()
{
    int amount = 20;
    std::vector<int> vector_list;
    for(int i = 0; i < amount - 1; i++)
    {
        int random = rand() % amount + 1;
        vector_list.push_back(random);
    }
    for(int i : vector_list)
    {
        std::cout << i << " ";
    }
    std::cout << "\n" << "-----------------------" <<std::endl;
    CSort csort;
    std::vector<int> some;
    some = csort.CountSort(vector_list, amount);
    for(int i: some)
    {
        std::cout << i << " ";
    }
    return 0;
}
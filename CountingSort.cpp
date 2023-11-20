#include "CountingSort.h"

void CountSort::CountingSort(std::vector<int> input, int k)
{
    std::vector<int> output;
    int count[static_cast<size_t>(k+1)];
    for(int i = 0; i < static_cast<int>(sizeof(count)) -1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i <= sizeof(input) - 1; ++i)
    {
        count[input[i]]++;
    }
    for(int i = 1; i <= k; i++)
    {
        count[i] = count[i] + count[i-1];
    }

    for(int i = static_cast<int>(sizeof(input)) - 1; i > 0; i--)
    {
        count[input[(size_t)i]] = count[input[(size_t)i]] - 1;
        output[input[i]] = input[i];
    }
    //return output;
}

int main()
{
    CountSort cSort;
    int amount = 20;
    std::vector<int> vector_list;
    for(int i = 0; i < amount - 1; i++)
    {
        int random = rand() % amount + 1;
        vector_list.push_back(random);
    }

    cSort.CountingSort(vector_list, amount);

    for (int i = 0; i < vector_list.size() - 1; ++i)
    {
        std::cout << vector_list[i] << " ";
    }

    return 0;
}

#ifndef LEARNINGCPP_COUNTSORT_H
#define LEARNINGCPP_COUNTSORT_H
#include <vector>
class CSort
{
public:
    std::vector<int> CountSort(std::vector<int> input, int k)
    {
        std::vector<int> output;
        output.resize(input.size());

        std::vector<int> count;
        count.resize(static_cast<size_t>(k + 1));

        for (int i = 0; i <= input.size() -1; ++i)
        {
            count[input[i]]++;
        }
        // for(int i: count)
        // {
        //     std::cout << i << " ";
        // }
        // std::cout << "\n" << count.size();

        for (int i = 1; i <= k; ++i)
        {
            count[i] += count[i-1];
        }
        // for(int i: count)
        // {
        //     std::cout << i << " ";
        // }
        // std::cout << "\n" << count.size();

        for (int i = input.size() - 1; i >= 0; --i)// Somewhere here I am doing something wrong
        {
            count[input[i]] = count[input[i]] - 1;
            output[count[input[i]]] = input[i];
        }
        return output;
    }

};
#endif //LEARNINGCPP_COUNTSORT_H

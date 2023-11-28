#ifndef UNSORTEDVECTOR_H
#define UNSORTEDVECTOR_H
#include <random>

namespace sorting_algorithms
{
    class UnsortedIntVector
    {
    public:
        static void UnsortedVector(int &amount, std::vector<int> &vector_list)
        {
            unsigned const seed = time(nullptr);
            std::default_random_engine generator(seed);
            std::uniform_int_distribution distribution(1, amount);
            vector_list.reserve(amount);
            for (int i = 0; i < amount; ++i)
            {
                vector_list.push_back(distribution(generator));
            }
        }
    };


}


#endif //UNSORTEDVECTOR_H

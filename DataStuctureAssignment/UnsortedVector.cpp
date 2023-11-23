#include "UnsortedVector.h"

void unsorted_vector::UnsortedList(const int amount,std::vector<int> &vector_list)
{
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < amount; ++i)
    {
        int random = rand() % amount + 1;
        vector_list.push_back(random);
    }
}

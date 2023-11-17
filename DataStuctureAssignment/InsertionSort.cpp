#include "InsertionSort.h"
#include "UnsortedVector.h"

void InsertionSort::SortVector(std::vector<int>&vector)
{
    for(unsigned long i = 0; i < vector.size(); i++)
    {
        unsigned long j = i;
        while (j > 0 && vector[j] > vector[j-1])
        {
            int a = vector[j];
            vector[j] = vector[j-1];
            vector[j-1] = a;
            j--;
        }
    }
}


int main()
{
    std::vector<int> vector_list;
    unsorted_vector::UnsortedList(10, vector_list);
    for(int i: vector_list)
    {
        std::cout << i << std::endl;
    }
    std::cout << "Amount: " << vector_list.size() << std::endl;
    std::cout << "--------------------------" << std::endl;
    InsertionSort::SortVector(vector_list);
    for(int i: vector_list)
    {
        std::cout << i << std::endl;
    }

}


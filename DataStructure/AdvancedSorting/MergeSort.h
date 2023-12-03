#ifndef LEARNINGCPP_MERGESORT_H
#define LEARNINGCPP_MERGESORT_H
#include <vector>
#include <random>

namespace sorting_Algorithms
{
    class MergeSort{
        static std::vector<int> merge(std::vector<int> &left, std::vector<int> &right)
        {
            std::vector<int> result;

            while(!left.empty() && !right.empty())
            {
                if(left.front() <= right.front()){
                    result.push_back(left.front());
                    left.erase(left.begin());
                }
                else
                {
                    result.push_back(right.front());
                    right.erase(right.begin());
                }
            }

            while(!left.empty()){
                result.push_back(left.front());
                left.erase(left.begin());
            }
            while (!right.empty()){
                result.push_back(right.front());
                right.erase(right.begin());
            }

            return result;
        }
    public:
        static std::vector<int> top_merge_sort(std::vector<int> &m)
        {
            if(m.size() <= 1)
                return m;

            std::vector<int> left;
            std::vector<int> right;

            for(int i = 0; i < m.size(); i++){
                if(i < static_cast<int>(m.size())/2)
                    left.push_back(m[i]);
                else
                    right.push_back(m[i]);
            }

            left = top_merge_sort(left);
            right = top_merge_sort(right);

            return merge(left, right);
        }
    };

    void merge_sort_func(std::vector<int> &vector_list);

}
#endif //LEARNINGCPP_MERGESORT_H

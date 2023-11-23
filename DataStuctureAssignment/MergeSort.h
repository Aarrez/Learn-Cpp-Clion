#ifndef LEARNINGCPP_MERGESORT_H
#define LEARNINGCPP_MERGESORT_H
#include <vector>
#include <random>
#include <array>


class TopDownMSort{
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
    static std::vector<int> merge_sort(std::vector<int> &m)
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

        left = merge_sort(left);
        right = merge_sort(right);

        return merge(left, right);
    }
};

// Had a try att bottom up merge sort but could not figure it out
//class BottomUpMSrot{
//
//    struct Node
//    {
//        Node* next;
//    };
//
//    Node* head = nullptr;
//public:
//    static Node* merge_sort(Node* &head, int size)
//    {
//        if(head){
//            return nullptr;
//        }
//        Node* nodeArray[size];
//        Node* reslut;
//        Node* next;
//        int i;
//        reslut = head;
//        while(reslut){
//            next = reslut->next;
//            reslut->next = nullptr;
//            for (i = 0; i < size && nodeArray[i]; ++i)
//            {
//                reslut = nodeArray[i];
//                nodeArray[i] = nullptr;
//            }
//        }
//    }
//};
#endif //LEARNINGCPP_MERGESORT_H

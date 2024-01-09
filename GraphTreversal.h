#ifndef GRAPHTREVERSAL_H
#define GRAPHTREVERSAL_H
#include "main.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace graph_Space;

template<typename T>
std::vector<double> Mesure_sorting(
    const int size,
    std::vector<std::shared_ptr<node>> &nodelist,
    int start[],
    int goal[],
    T (func) (std::vector<std::shared_ptr<node>> &nlist ,const std::shared_ptr<node> &f , const std::shared_ptr<node> &l))
{
    std::vector<double> duration_list;
    for (int i = 0; i < size; ++i)
    {
        auto s = std::chrono::system_clock::now();
        func(nodelist, nodelist[start[i]], nodelist[goal[i]]);
        auto e = std::chrono::system_clock::now();
        std::chrono::duration<double> d = e-s;
        double duration = d.count();
        duration_list.push_back(duration);
    }
    return duration_list;
}
template<typename T>
std::vector<double> Mesure_sorting(
    const int size,
    std::vector<std::shared_ptr<node>> &nodelist,
    int start[],
    int goal[],
    T (func) (std::vector<std::shared_ptr<node>> &nlist ,const std::shared_ptr<node> &f , const std::shared_ptr<node> &l, bool &foundgoal))
{
    bool foundg {false};
    std::vector<double> duration_list;
    for (int i = 0; i < size; ++i)
    {
        auto s = std::chrono::system_clock::now();
        func(nodelist, nodelist[start[i]], nodelist[goal[i]], foundg);
        auto e = std::chrono::system_clock::now();
        std::chrono::duration<double> d = e-s;
        double duration = d.count();
        duration_list.push_back(duration);
    }
    return duration_list;
}

#endif //GRAPHTREVERSAL_H

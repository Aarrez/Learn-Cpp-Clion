#ifndef GRAPHTREVERSAL_H
#define GRAPHTREVERSAL_H
#include "main.h"
#include <iostream>
#include <map>
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

class Depth
{
    std::shared_ptr<node> Search_depth_first
(std::vector<std::shared_ptr<node>> &nodelist, const std::shared_ptr<node> &first, const std::shared_ptr<node> &goal)
    {
        std::stack<std::shared_ptr<node>> iternodestack;
        iternodestack.push(first);
        iternodestack.top()->explored = true;
        while(!iternodestack.empty())
        {
            for(auto & b : iternodestack.top()->adjecent)
            {
                for(auto a = b->adjecent.begin(); a < b->adjecent.end(); ++a)
                {
                    auto n = *a;
                    if(n->id == goal->id)
                    {
                        for(auto & no : nodelist)
                        {
                            n->explored = false;
                        }
                        return n;
                    }
                    if(!n->explored)
                    {
                        n->explored = true;
                        std::cout << n->id << std::endl;
                        iternodestack.push(n);
                    }
                }
            }
            iternodestack.pop();
        }

        std::cerr << "Depth first could not find: " << goal->id << std::endl;
        return first;
    }
};

#endif //GRAPHTREVERSAL_H

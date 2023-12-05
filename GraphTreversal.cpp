#include "GraphTreversal.h"
#include <iostream>
#include <map>
#include <queue>
#include <stack>
using namespace graph_space;

std::shared_ptr<node> search_algorithms::searchbreadthfirst(std::shared_ptr<node> &first, std::shared_ptr<node> &goal)
{
    if(first->isblocker || goal->isblocker)
    {
        std::cerr << "First node or goal is a blocker and cant be found";
        return nullptr;
    }
    std::queue<std::shared_ptr<node>> nodequeue;
    first->explored = true;
    nodequeue.push(first);
    while(!nodequeue.empty())
    {
        auto v = nodequeue.front();
        nodequeue.pop();
        if(v->id == goal->id)
            return v;
        for(std::shared_ptr<node>& a : v->adjecent)
        {
            if(!a->explored)
            {
                a->explored = true;
                nodequeue.push(a);
            }
        }
    }
    std::cerr << "A path to the goal could not be determined";
    return nullptr;
}

std::shared_ptr<node> search_algorithms::searchbreadthfirst(std::vector<std::shared_ptr<node>> &nodelist, int firstid, int goalid)
{
    if(nodelist.at(firstid)->isblocker || nodelist.at(goalid)->isblocker)
    {
        std::cerr << "First node or goal is a blocker and can not be found";
        return nullptr;
    }
    std::queue<std::shared_ptr<node>> nodequeue;
    nodelist.at(firstid)->explored = true;
    nodequeue.push(nodelist.at(firstid));
    while(!nodequeue.empty())
    {
        auto v = nodequeue.front();
        nodequeue.pop();
        if(v->id == nodelist.at(goalid)->id)
        {
            std::cout << "Node was found";
            return v;
        }
        for(std::shared_ptr<node>& a : v->adjecent)
        {
            if(!a->explored)
            {
                a->explored = true;
                nodequeue.push(a);
            }
        }
    }
    std::cerr << "A path to the goal could not be determined";
    return nullptr;
}

int search_algorithms::searchdepthfirst(const std::shared_ptr<node> &first)
{
    if(first->isblocker)
    {
        std::cerr << "Fist node is a blocker and there for can not be used as first node";
        return 1;
    }
    first->explored = true;
    for(auto& a : first->adjecent)
    {
        if(!a->explored)
            search_algorithms:searchdepthfirst(a);
    }
}

double distance(const vector2 first, const vector2 last)
{
    return sqrt(pow((first.x - last.x),2) + pow((first.y - last.y), 2));
}

std::vector<std::shared_ptr<node>> reconsturct_path(
    std::vector<std::shared_ptr<node>> &camefrom,
    std::shared_ptr<node> &current)
{
    std::vector<std::shared_ptr<node>> total_path;
    total_path.push_back(current);
    for(const auto & i : camefrom)
    {
        total_path.push_back(i);

    }
    return total_path;
}

std::vector<std::shared_ptr<node>> astarsearch(std::shared_ptr<node> &first, std::shared_ptr<node> &goal)
{
    std::vector<std::shared_ptr<node>> openset;
    openset.push_back(first);

    std::vector<std::shared_ptr<node>> camefrom;

    std::unordered_map<std::shared_ptr<node>, double> gscore;
    gscore.reserve(std::numeric_limits<int>::infinity());
    gscore[first] = 0.0;

    std::unordered_map<std::shared_ptr<node>, double> fscore;
    fscore.reserve(std::numeric_limits<int>::infinity());
    double d = distance(first->position, goal->position);
    fscore[first] = d;
    while(!openset.empty())
    {
        std::shared_ptr<node> current;
        double b {100};
        int j {};
        for (int i = 0; i < openset.size(); i++)
        {
            double a = distance(openset[i]->position, goal->position);
            if(a < b)
            {
                b = a;
                current = openset[i];
                j = i;
            }
        }
         //node with the lowest fscore value
        if(current->id == goal->id)
        {
            return reconsturct_path(camefrom, current);
        }
        openset.erase(openset.begin() + j);
        for(auto & n :current->adjecent)
        {
            auto t_gscore = gscore[current] + distance(current->position, n->position);
            if(t_gscore > gscore[n])
            {
                camefrom.push_back(current);
                gscore[n] = t_gscore;
                fscore[n] = t_gscore + distance(n->position, goal->position);
                if(std::ranges::find(openset.begin(), openset.end(), n) == openset.end())
                {
                    openset.push_back(n);
                }
            }

        }
    }
    return openset;
}


/* Could not get depth first to work when useing iterators insted
 int search_algorithms::searchdepthfirst(std::shared_ptr<node> &first, std::shared_ptr<node> &goal)
 {
     if(first->isblocker)
     {
         std::cerr << "Fist node is a blocker and there for can not be used as first node";
         return 1;
     }
     std::stack<std::shared_ptr<node>> nodestack;
     first->explored = true;
     nodestack.push(first);
     int i {0};
     int j {0};
     while (!nodestack.empty())
     {
         if(nodestack.top()->adjecent.begin() + i < nodestack.top()->adjecent.end())
         {
             auto w = std::next(nodestack.top()->adjecent.begin(), i);
             if(!w->get()->explored)
             {
                 w->get()->explored = true;
                 nodestack.push(*w);
             }
             i++;
         }
         else
         {
             i = 0;
             j++;
             nodestack.pop();

         }

     }
     std::cerr << "Could not find goal " << j << std::endl;
     return 1;
}
*/



int main()
{
    std::vector<std::shared_ptr<node>> nodelist = graphimport();

    auto result = astarsearch(nodelist[0], nodelist[99]);

    for(auto & node : result)
    {
        std::cout << node->id << std::endl;
    }
    // int result = search_algorithms::searchdepthfirst(nodelist.at(10));
    //
    // std::cout << result;

    // search_algorithms::searchbreadthfirst(nodelist, 0, 60);

    // int nodeid = 39;
    // auto n = nodelist.at(nodeid);
    // auto pos = n->adjecent;
    // auto pos1 = nodelist.at(nodeid)->position;
    // std::cout << "main: " << "x: " << pos1.x << " y: "<< pos1.y << std::endl;
    // for(const auto& a: pos)
    // {
    //
    //     std::cout << "x: " << a->position.x << " y: " << a->position.y << std::endl;
    //     std::cout << "Id: " << a->id << std::endl;
    // }

    return 0;
}
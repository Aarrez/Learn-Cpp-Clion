#include "GraphTreversal.h"
#include <iostream>
#include <map>
#include <queue>
#include <stack>
using namespace graph_Space;
// std::shared_ptr<node> Search_Algorithms::Search_Breadth_First(std::vector<std::shared_ptr<node>>&nodelist, int firstid, int goalid)
// {
//     if(nodelist.at(firstid)->isblocker || nodelist.at(goalid)->isblocker)
//     {
//         std::cerr << "First node or goal is a blocker and can not be found";
//         return nullptr;
//     }
//     std::queue<std::shared_ptr<node>> nodequeue;
//     nodelist.at(firstid)->explored = true;
//     nodequeue.push(nodelist.at(firstid));
//     while(!nodequeue.empty())
//     {
//         auto v = nodequeue.front();
//         nodequeue.pop();
//         if(v->id == nodelist.at(goalid)->id)
//         {
//             std::cout << "Node was found";
//             return v;
//         }
//         for(std::shared_ptr<node>& a : v->adjecent)
//         {
//             if(!a->explored)
//             {
//                 a->explored = true;
//                 nodequeue.push(a);
//             }
//         }
//     }
//     std::cerr << "A path to the goal could not be determined";
//     return nullptr;
// }

std::shared_ptr<node> Search_Breadth_First(const std::shared_ptr<node> &first, const std::shared_ptr<node> &goal)
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

int Search_Depth_First(const std::shared_ptr<node> &first, const std::shared_ptr<node> &goal)
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
            search_algorithms:Search_Depth_First(a, goal);
    }
    if(first->id == goal->id)
    {
        std::cout << "Goal was found: " << first->id;
        return 0;
    }

    std::cerr << "No goal found";
    return 1;
}

double Distance(const vector2 first, const vector2 last)
{
    return sqrt(abs(first.x - last.x) + abs(first.y - last.y));
}

std::vector<std::shared_ptr<node>> Reconsturct_path(
    std::vector<std::shared_ptr<node>> &camefrom,
    std::shared_ptr<node> &current)
{
    std::vector<std::shared_ptr<node>> total_path;
    total_path.push_back(current);
    for (int i = static_cast<int>(camefrom.size()) - 1; i >= 0; --i)
    {
        total_path.push_back(camefrom[i]);
    }
    return total_path;
}

std::vector<std::shared_ptr<node>> Astar_search(const std::shared_ptr<node> &first, const std::shared_ptr<node> &goal)
{
    std::vector<std::shared_ptr<node>> openset;
    openset.push_back(first);
    std::vector<std::shared_ptr<node>> closedset;

    std::vector<std::shared_ptr<node>> camefrom;
    if(first->isblocker || goal->isblocker)
    {
        std::cerr << "Fist or goal is and blocker";
        return camefrom;
    }

    std::unordered_map<std::shared_ptr<node>, double> gscore;
    gscore.reserve(std::numeric_limits<int>::infinity());
    gscore[first] = 0.0;

    std::unordered_map<std::shared_ptr<node>, double> fscore;
    fscore.reserve(std::numeric_limits<int>::infinity());
    double d = Distance(first->position, goal->position);
    fscore[first] = d;
    while(!openset.empty())
    {
        std::shared_ptr<node> current = openset[0];
        int j {0};
        for (int i = 1; i < openset.size(); ++i)
        {
            if(fscore[openset[i]] < fscore[openset[i-1]])
            {
                current = openset[i];
                j = i;
            }
        }
        /* Deprecated code
        double b {1000};
        int j {};
        for (int i = 0; i < openset.size(); i++)
        {
            double a = Distance(openset[i]->position, goal->position);
            if(a < b)
            {
                b = a;
                current = openset[i];
                j = i;
            }
        }
        */
         //node with the lowest fscore value
        if(current->id == goal->id)
        {
            return Reconsturct_path(camefrom, current);
        }
        auto some = openset.erase(openset.begin() + j);
        closedset.push_back(*some);
        int s{0};
        for(auto & n :current->adjecent)
        {
            double t_gscore {gscore[current]};
            t_gscore += Distance(current->position, n->position);
            if(t_gscore > gscore[n])
            {
                if(std::ranges::find(camefrom.begin(), camefrom.end(), n) == camefrom.end())
                {
                    camefrom.push_back(current);
                }

                gscore[n] = t_gscore;
                fscore[n] = t_gscore + Distance(n->position, goal->position);
                if(std::ranges::find(closedset.begin(), closedset.end(), n) == closedset.end())
                {
                    openset.push_back(n);
                }
            }
        }
    }
    return openset;
}


/* Could not get depth first to work when useing iterators
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
template<typename T>
std::vector<double> Mesure_sorting(
    const int size,
    std::shared_ptr<node> start[],
    std::shared_ptr<node> goal[],
    T (*func) (const std::shared_ptr<node> &f , const std::shared_ptr<node> &l))
{
    std::vector<double> duration_list;
    for (int i = 0; i < size; ++i)
    {
        auto s = std::chrono::system_clock::now();
        func(start[i], goal[i]);
        auto e = std::chrono::system_clock::now();
        std::chrono::duration<double> d = e-s;
        double duration = d.count();
        duration_list.push_back(duration);
    }
    return duration_list;
}

int main()
{
    std::vector<std::shared_ptr<node>> nodelist = graphimport();

    // 0 , 10, 50, 100
    std::shared_ptr<node> start[]{nodelist[0], nodelist[10], nodelist[50], nodelist[100]};

    //50 , 100, 250, 350
    std::shared_ptr<node> goal[]{nodelist[50], nodelist[100], nodelist[250], nodelist[350]};

    int size = sizeof(start)/sizeof(std::shared_ptr<node>);

    auto astar = Mesure_sorting(size, start, goal, &Astar_search);
    auto breadth = Mesure_sorting(size, start, goal, &Search_Breadth_First);
    auto deapth = Mesure_sorting(size, start, goal, &Search_Depth_First);


    for(auto value : astar)
    {
        std::cout << value << std::endl;
    }

    // auto result = Astar_search(nodelist[0], nodelist[10]);


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
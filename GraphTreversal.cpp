#include "GraphTreversal.h"

std::shared_ptr<node> Search_breadth_first
(std::vector<std::shared_ptr<node>> &nodelist, const std::shared_ptr<node> &first, const std::shared_ptr<node> &goal)
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
        auto v {nodequeue.front()};

        nodequeue.pop();
        if(v->id == goal->id)
        {
            for(auto & n : nodelist)
            {
                n->explored = false;
            }
            return v;
        }
        for(std::shared_ptr<node> & a : v->adjecent)
        {
            if(!a->explored)
            {
                a->explored = true;
                nodequeue.push(a);
            }
        }
    }
    std::cerr << "error" <<first->id << " " << goal->id << std::endl;
    std::cerr << "A path to the goal could not be determined" << std::endl;
    return nullptr;
}

void Search_depth_first
(std::vector<std::shared_ptr<node>> &nodelist, const std::shared_ptr<node> &first, const std::shared_ptr<node> &goal, bool &goalfound)
{
    first->explored = true;

    if(goalfound)
    {
        return;
    }
    if(first->id == goal->id)
    {
        for(auto & n : nodelist)
        {
            n->explored = false;
        }
        goalfound = true;
        std::cout << "Goal found: " << first->id<< std::endl;
        return;
    }
    for(auto & neibor : first->adjecent)
    {
        if(!neibor->explored)
        {
            Search_depth_first(nodelist, neibor, goal, goalfound);
        }
        if(goalfound)
        {
            return;
        }
    }
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

std::vector<std::shared_ptr<node>> Astar_search
(std::vector<std::shared_ptr<node>> &nodelist, const std::shared_ptr<node> &first, const std::shared_ptr<node> &goal)
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
    gscore.reserve(nodelist.size());

    std::unordered_map<std::shared_ptr<node>, double> fscore;
    fscore.reserve(nodelist.size());

    for(std::shared_ptr<node> & n : nodelist)
    {
        gscore[n] = std::numeric_limits<double>::max();
        fscore[n] = std::numeric_limits<double>::max();
    }

    gscore[first] = 0.0;

    const double d = Distance(first->position, goal->position);
    fscore[first] = d;

    while(!openset.empty())
    {
        //node with the lowest fscore value
        int j {0};
        std::shared_ptr current {openset[j]};
        for (int i = 1; i > openset.size(); ++i)
        {
            if(fscore[openset[i]] < fscore[openset[i-1]])
            {
                current = openset[i-1];
                j = i;
            }
        }

        if(current->id == goal->id)
        {
            return Reconsturct_path(camefrom, current);
        }
        closedset.push_back(openset[j]);
        openset.erase(openset.begin() + j);
        for(auto & n : current->adjecent)
        {
            double t_gscore {gscore[current]};
            t_gscore += Distance(current->position, n->position);
            if(t_gscore < gscore[n])
            {
                /* Does nothing for some reson.
                 * Should compare n to the existing items in the vector and if they are the same n should not be added to camefrom vector.
                 * However if I do it correcly no items get added to the vector.
                 * At the end it != camefrom.end() is the correct way too do it but it does not work for some reson.
                 */
                if(auto it = std::ranges::find(camefrom, n); it == camefrom.end())
                    camefrom.push_back(current);
                gscore[n] = t_gscore;
                fscore[n] = t_gscore + Distance(n->position, goal->position);
                //Also does nothing
                if(auto it = std::ranges::find(closedset, n); it == closedset.end())
                {
                    openset.push_back(n);
                }
            }
        }
    }
    std::cerr << "Astar goal was not found" << std::endl;
    return openset;
}

int main()
{
    std::vector<std::shared_ptr<node>> astarlist = graphimport();
    std::vector<std::shared_ptr<node>> breathlist = graphimport();


    int startnodes[] {0, 100, 150, 250};
    int goalnodes[] {99, 200, 300, 399};

    // Array of all the start nodes

    constexpr int arrsize = sizeof(startnodes)/sizeof(int);

    std::cout << "Astar search: " << std::endl;
    auto astar = Mesure_sorting(arrsize, astarlist ,startnodes, goalnodes, Astar_search);
    for(auto const value : astar)
    {
        std::cout << "Time in seconds: "<< value << std::endl;
    }
    std::cout << "Breadth search: " << std::endl;
    auto breadth = Mesure_sorting(arrsize, breathlist,startnodes, goalnodes, Search_breadth_first);
    for(auto const value : breadth)
    {
        std::cout << "Time in seconds: " << value << std::endl;
    }
    std::cout << "Depth search: " << std::endl;
    auto depth = Mesure_sorting(arrsize, astarlist ,startnodes, goalnodes, Search_depth_first);
    for(auto const value : astar)
    {
        std::cout << "Time in seconds: "<< value << std::endl;
    }
    return 0;
}
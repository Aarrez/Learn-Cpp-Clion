#include "GraphTreversal.h"
#include <iostream>

using namespace graph_space;

void search_algorithms::searchbreadthfirst(node* first, node* goal)
{

}

int main()
{
    std::vector<std::shared_ptr<node>> nodelist = graphimport();

    // for (int i = 0; i < 400; ++i)
    // {
    //     auto pos = g.getbyid(i)->position;
    //     std::cout << "x: " << pos.x << " y: " << pos.y << std::endl;
    // }

    auto pos = nodelist.at(31)->adjecent;
    auto pos1 = nodelist.at(31)->position;
    std::cout << "main: " << "x: " << pos1.x << " y: "<< pos1.y << std::endl;
    for(const auto& a: pos)
    {

        std::cout << "x: " << a->position.x << " y: " << a->position.y << std::endl;
    }

    return 0;
}
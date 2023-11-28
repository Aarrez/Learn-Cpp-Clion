#include "GraphImport.h"
#include <iostream>
#include <fstream>

namespace graph_space
{
    graph graphimport()
    {
        std::fstream stream {"AssignmentNodes.txt", std::ios::in | std::ios::out};
        if(!stream)
            std::cerr << ".txt file could not be opend";

        char chChar{};
        int xlenth {10};
        int id {0};
        int i {0};
        int j {0};
        node* temp;
        std::vector<node*> nodelist;
        while(stream.get(chChar))
        {
            switch (chChar)
            {
                case 'o':
                    temp = new node;
                    temp->id = id;
                    temp->position = {i, j};
                    nodelist.push_back(temp);
                    i++;
                    id++;
                    if(i == xlenth)
                    {
                        i = 0;
                        j++;
                    }
                break;
                case 'X':
                    temp = new node;
                    temp->position = {i, j};
                    temp->isblocker = true;
                    nodelist.push_back(temp);
                    i++;
                    id++;
                    if(i == xlenth)
                    {
                        i = 0;
                        j++;
                    }
                break;
                default:
                    break;
            }
        }

        graph agraph(nodelist);
        stream.close();
        return agraph;
    }


}

int main()
{
    graph_space::graph g = graph_space::graphimport();
    auto pos = g.getbyid(21)->position;
    std::cout << "x: " << pos.x << " y: " << pos.y;
    return 0;
}



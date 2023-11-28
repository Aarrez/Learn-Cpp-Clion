#include "GraphImport.h"
#include <iostream>
#include <fstream>

namespace graph_space
{
    void graphimport()
    {
        std::ifstream stream {"AssignmentNodes.txt"};
        if(stream.is_open())
        {
            char the {'o'};
            stream.read(&the, sizeof(int));
            int i {0};
            for(std::string line; std::getline(stream, line, 'o');)
            {
                i++;
            }
            std::cout << i;
        }
        else
        {
            std::cout << ".txt file could not be opend";
        }
    }
}

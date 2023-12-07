#include "GraphImport.h"
#include <iostream>
#include <fstream>

namespace graph_Space
{
    std::vector<std::shared_ptr<node>> graphimport()
    {
        const char* some {"AssignmentNodes.txt"};
        std::fstream stream {some, std::ios::in | std::ios::out};
        if(!stream)
            std::cerr << ".txt file could not be opend";

        char chChar{};
        int xlenth {20};
        int id {0};
        int i {0};
        int j {0};
        std::shared_ptr<node> temp;
        std::vector<std::shared_ptr<node>> nodelist;
        // std::istream_iterator<std::string> fileiterator(stream);
        // std::istream_iterator<std::string> enditerator;
        //
        // while(fileiterator != enditerator)
        // {
        //     std::cout << *fileiterator << std::endl;
        //     ++fileiterator;
        // }
        while(stream.get(chChar))
        {
            switch (chChar)
            {
                case 'o':
                    temp = std::make_shared<node>();
                    temp->id = id;
                    temp->position = {i, j};
                    nodelist.push_back(temp);
                    i++;
                    id++;
                    if(i == xlenth)
                    {
                        temp->isedge = true;
                        i = 0;
                        j++;
                    }
                break;
                case 'X':
                    temp = std::make_shared<node>();
                    temp->position = {i, j};
                    temp->isblocker = true;
                    nodelist.push_back(temp);
                    i++;
                    id++;
                    if(i == xlenth)
                    {
                        temp->isedge = true;
                        i = 0;
                        j++;
                    }
                break;
                default:
                    break;
            }
        }
        addadjecentnodes(nodelist);
        stream.close();
        return nodelist;
    }

    void addadjecentnodes(std::vector<std::shared_ptr<node>> &nodelist)
    {
        for (int i = 0; i < nodelist.size()-1; ++i)
        {
            if(nodelist[i]->isblocker) continue;
            int y = nodelist[i]->position.y;
            int x = nodelist[i]->position.x;
            int j = i + 1;
            if(!nodelist[j]->isblocker)
            {
                if(!nodelist[i]->isedge)
                {
                    nodelist[i]->adjecent.push_back(nodelist[j]);
                    nodelist[j]->adjecent.push_back(nodelist[i]);
                }
            }

            if(y > 0)
            {
                int a = x;
                if(y > 1)
                {
                    a = x + ((y-1) * 20);
                }
                if(nodelist[a]->isblocker) continue;
                nodelist[a]->adjecent.push_back(nodelist[i]);
                nodelist[i]->adjecent.push_back(nodelist[a]);
            }
        }
    }
}


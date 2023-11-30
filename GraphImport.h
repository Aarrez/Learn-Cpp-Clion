#ifndef GRAPHIMPORT_H
#define GRAPHIMPORT_H
#include <vector>

namespace graph_space
{
    struct vector2
    {
        int x;
        int y;
    };
    struct node
    {
        int id {0};
        bool isblocker {false};
        bool explored {false};
        std::vector<std::shared_ptr<node>> adjecent;
        vector2 position {0, 0};
    };

    std::vector<std::shared_ptr<node>> graphimport();
    void addadjecentnodes(std::vector<std::shared_ptr<node>> &nodelist);
}
#endif //GRAPHIMPORT_H

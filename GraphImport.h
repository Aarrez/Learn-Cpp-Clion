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
        node** adjecent {nullptr};
        vector2 position {0, 0};
    };


    class graph
    {
        std::vector<node*> nodelist_;
    public:

        explicit graph(std::vector<node*> &nodelist)
        {
            this->nodelist_ = nodelist;
        }

        void searchastar(node* first, node* goal);
        void searchbreadthfirst(node* first, node* goal);
        void searchdepthfirst(node* first, node* goal);
        node* getbyid(int id)
        {
            return nodelist_[id];
        }
        ~graph()
        {
            for (auto i: nodelist_)
            {
                delete i;
            }
        };
    };
    graph graphimport();
}
#endif //GRAPHIMPORT_H

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
        node** adjecent {nullptr};
        vector2 position {0, 0};
    };
    class graph_import
    {
    public:
        explicit graph_import() = delete;
        ~graph_import() = delete;
    };
    class graph
    {
    public:
        std::vector<node*> nodelist;
        explicit graph(std::vector<node*> &nodelist)
        {
            this->nodelist = nodelist;
        };
        void searchastar(node* first, node* goal);
        void searchbreadthfirst(node* first, node* goal);
        void searchdepthfirst(node* first, node* goal);
        ~graph() = delete;
    };
    void graphimport();
}
#endif //GRAPHIMPORT_H

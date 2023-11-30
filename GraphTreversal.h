#ifndef GRAPHTREVERSAL_H
#define GRAPHTREVERSAL_H
#include "main.h"
namespace graph_space
{
    class search_algorithms
    {
    public:
        void searchastar(node* first, node* goal);
        void searchbreadthfirst(node* first, node* goal);
        void searchdepthfirst(node* first, node* goal);
    };

}

#endif //GRAPHTREVERSAL_H

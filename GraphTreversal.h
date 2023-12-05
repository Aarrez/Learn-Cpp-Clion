#ifndef GRAPHTREVERSAL_H
#define GRAPHTREVERSAL_H
#include "main.h"
namespace graph_space
{
    class search_algorithms
    {
    public:
        static std::shared_ptr<node> searchbreadthfirst(std::shared_ptr<node> &first, std::shared_ptr<node> &goal);
        static std::shared_ptr<node> searchbreadthfirst(std::vector<std::shared_ptr<node>> &nodelist, int firstid, int goalid);

        static int searchdepthfirst(const std::shared_ptr<node> &first);

        static int searchdepthfirst(std::vector<std::shared_ptr<node>> &nodelist, int fisrtid);
    };

}

#endif //GRAPHTREVERSAL_H

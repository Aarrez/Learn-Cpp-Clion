//The CORRECT WAY
void Search_depth_first
(std::vector<std::shared_ptr<node>> &nodelist, const std::shared_ptr<node> &first, const std::shared_ptr<node> &goal)
{
    std::stack<std::shared_ptr<node>> iternodestack;
    std::stack<std::shared_ptr<node>> adjnodestack;
    iternodestack.push(first);
    iternodestack.top()->explored = true;
    while(!iternodestack.empty())
    {
        for(auto & b : iternodestack.top()->adjecent)
        {
            if(b->id == goal->id)
            {
                for(auto & no : nodelist)
                {
                    no->explored = false;
                }
                return;
            }
            if(!b->explored)
            {
                b->explored = true;
                // std::cout << b->id << std::endl;
                adjnodestack.push(b);
            }
        }
        iternodestack.pop();
        for(int i = 0; i < adjnodestack.size() - 1; i++)
        {
            iternodestack.push(adjnodestack.top());
            adjnodestack.pop();
        }
    }

    std::cerr << "Depth first could not find: " << goal->id << std::endl;
}


//The WRONG WAY
    std::shared_ptr<node> Search_depth_first
(std::vector<std::shared_ptr<node>> &nodelist, const std::shared_ptr<node> &first, const std::shared_ptr<node> &goal)
    {
        std::stack<std::shared_ptr<node>> iternodestack;
        iternodestack.push(first);
        iternodestack.top()->explored = true;
        while(!iternodestack.empty())
        {
            for(auto & b : iternodestack.top()->adjecent)
            {
                for(auto a = b->adjecent.begin(); a < b->adjecent.end(); ++a)
                {
                    auto n = *a;
                    if(n->id == goal->id)
                    {
                        for(auto & no : nodelist)
                        {
                            n->explored = false;
                        }
                        return n;
                    }
                    if(!n->explored)
                    {
                        n->explored = true;
                        std::cout << n->id << std::endl;
                        iternodestack.push(n);
                    }
                }
            }
            iternodestack.pop();
        }

        std::cerr << "Depth first could not find: " << goal->id << std::endl;
        return first;
    }
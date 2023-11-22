#ifndef GRAPHTRAVERSAL_H
#define GRAPHTRAVERSAL_H
#include <iostream>
#include <queue>
#include <stack>

class Graph;
struct Node;

struct adjNode
{
    Node* node = nullptr;
    int weight = 0;
};

struct Node
{
    int id {0};
    bool expored = false;
    std::vector<adjNode*> neighbors;
};

class Graph
{
public:
    std::vector<Node*> vectornode;

    Graph()
    = default;

    explicit Graph(const int size)
    {
        for(int i = 0; i < size; i++)
        {
            auto node = new Node;
            node->id = i;
            vectornode.push_back(node);
        }
    }

    void AddAdjNode()
    {
        srand(static_cast<unsigned>(time(NULL)));
        for (int i = 0; i < vectornode.size()-1; ++i)
        {
            for (int j = 0; j < vectornode.size()-1; ++j)
            {
                if(i != j)
                {
                    int weight = rand() % 3;
                    const auto node_adj = new adjNode;
                    node_adj->node = vectornode[j];
                    node_adj->weight = weight;
                    vectornode[i]->neighbors.push_back(node_adj);
                }
            }
        }
    }

    ~Graph()
    {
       for(const auto a: vectornode)
       {
           for (const auto b: a->neighbors)
           {
               delete b;
           }
           delete a;
       }
    }
};

class Traveral
{
public:
    static Node* breadthFirstSeartch(Graph &graph, Node* root, const int goal){
        std::queue<Node*> q;
        root->expored = true;
        q.push(root);
        while (!q.empty())
        {
            const auto v = q.front();
            q.pop();
            if(v->id == goal)
                return v;

            for(const adjNode* i : graph.vectornode[v->id]->neighbors)
            {
                if(!i->node->expored)
                {
                    i->node->expored = true;
                    q.push(i->node);
                }
            }
        }
        return nullptr;
    }

    static Node* depthFirstSearch(Graph &graph, Node* node)
    {
        std::stack<Node*> nodeStack;
        node->expored = true;
        nodeStack.push(node);
        while(!nodeStack.empty())
        {
            if(!nodeStack.top()->neighbors.empty())
            {
                bool some = true;
                for (int i = 0; i < nodeStack.top()->neighbors.size()-1; ++i)
                {
                    auto w = nodeStack.top()->neighbors[i]->node;
                    if(!w->expored)
                    {
                        w->expored = true;
                        nodeStack.push(w);
                        some = false;
                    }
                }
                if(some)
                {
                    nodeStack.pop();
                }

            }
        }
        return node;
    };
};
#endif //GRAPHTRAVERSAL_H

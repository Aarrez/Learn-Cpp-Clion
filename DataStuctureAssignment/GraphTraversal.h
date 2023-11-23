#ifndef GRAPHTRAVERSAL_H
#define GRAPHTRAVERSAL_H
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>

class Graph;
struct Node;

struct adjNode
{
    Node* node = nullptr;
    float weight = 0;
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

    void AddAdjNode() const
    {
        srand(static_cast<unsigned>(time(nullptr)));
        for (int i = 0; i < vectornode.size()-1; ++i)
        {
            for (int j = 0; j < vectornode.size()-1; ++j)
            {
                if(i != j)
                {

                    float weight = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
                    if (weight < 0.4f){
                        weight = 0.0f;
                    }
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
    static Node* breadthFirstSeartch(Graph const &graph, Node* root, const int goal){
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

    static Node* depthFirstSearch(Node* node)
    {
        std::stack<Node*> nodeStack;
        node->expored = true;
        nodeStack.push(node);
        while(!nodeStack.empty())
        {
            if(!nodeStack.top()->neighbors.empty())
            {
                bool some = true;
                for (int i = 0; i < static_cast<int>(nodeStack.top()->neighbors.size())-1; ++i)
                {
                    if(auto w = nodeStack.top()->neighbors[i]->node; !w->expored)
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
    }


    static Graph reconstuct_path(Graph* cameFrom, Node* current)
    {

    }

    static Graph aStarSearch(Node* start, const int goal)
    {
        std::priority_queue<Node*> openset;
        openset.push(start);

        auto cameFrom = new Graph();

        auto gScore = std::make_unique<Graph>(10000);

        auto fScore = std::make_unique<Graph>(10000);


        while (openset.top()->neighbors.empty())
        {
            auto current = new adjNode;
            current->weight = 0;
            for(auto a: openset.top()->neighbors)
            {
                if(a->weight < current->weight)
                {
                    current = a;
                }
            }
            if (current->node->id == goal)
                return reconstuct_path(cameFrom, current->node);
            openset.pop();
            for(auto i: current->node->neighbors)
            {
                auto tentative_gScore = i->weight;

            }
            delete current;
        }

        return Graph();
    }
};
#endif //GRAPHTRAVERSAL_H

#include <list>

struct vec2
{
    vec2(float x, float y)
    {
      this->x = x;
        this->y = y;
    }

    float x,y;
};
struct Node
{
    int id {0};
    std::list<Node*> neighbours;
};
template<class T>
class GetRandomElementInArray
{
public:
    T static RandomizeArray(T givenArray[], int index)
    {


        return givenArray;
    }
};

class Graph
{

private:
    Node* root;
    std::list<Node*> nodes;
    int id {0};

public:
    Graph()
    {
        Node* node {nullptr};
        node = new Node();
        node->id = this->id;
        nodes = this->nodes;
        root = *&node;
    }

    Node* MakeNodes(vec2* pos)
    {
        id++;
        Node* node = new Node();
        node->id = id;
        nodes.push_back(node);
        return node;
    }

    void MakeConnections(Node nodelist[], int minConnections)
    {
        srand(static_cast<unsigned>(time(nullptr)));
        for (int i = 0; i < sizeof(nodelist); ++i)
        {
            while(sizeof(nodelist[i].neighbours) < minConnections)
            {
                int a = rand() % 9;
                while(a == i)
                {
                    a = rand() % 9;
                }
                nodelist[i].neighbours.push_back(&nodelist[a]);
            }
        }
    }

    void DepthFirstSearch(Node nodelist[], Node* firstNode, std::list<Node*> foundNodeList)
    {

    }

~Graph()
    {
        delete root;
    }
};


int main()
{
    Node* nodeList[10];
    Graph* graph = new Graph();
    vec2* pos = new vec2(1, 1);
    for(int i = 0; i < sizeof(nodeList); i++)
    {
        Node* node = graph->MakeNodes(pos);
        nodeList[i] = node;
        delete node;
    }

    delete graph;

}
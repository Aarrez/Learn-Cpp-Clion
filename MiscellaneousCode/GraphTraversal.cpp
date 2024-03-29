#include "GraphTraversal.h"


int main()
{
    int amount = 10;
    int toFind = amount/2;

    Graph graph(amount);
    graph.AddAdjNode();

    // {
    //     auto start = std::chrono::high_resolution_clock::now();
    //     Node* goal = Traveral::breadthFirstSeartch(graph, graph.vectornode[0], toFind);
    //     auto stop = std::chrono::high_resolution_clock::now();
    //     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    //     std::cout << "Goal was found: " << goal->id <<std::endl;
    //     std::cout<< "Microseconds: "<< duration.count() << std::endl;
    // }
    // {
    //     auto start = std::chrono::high_resolution_clock::now();
    //     Node* goal = Traveral::depthFirstSearch(graph, graph.vectornode[0]);
    //     auto stop = std::chrono::high_resolution_clock::now();
    //     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    //     std::cout<< "Microseconds: "<< duration.count() << std::endl;
    // }



    for (int i = 0; i < amount; ++i)
    {
        std::cout << "Index: " << graph.vectornode[i]->id << "; ";
        for (int j = 0; j < amount - 1; ++j)
        {
            std::cout << "(" << graph.vectornode[i]->neighbors[j]->node->id << ")";
            std::cout << std::setprecision(2) << graph.vectornode[i]->neighbors[j]->weight << " ";
        }
        std::cout << "" << std::endl;
    }
    return 0;
}
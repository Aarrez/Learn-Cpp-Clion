#include "QSLLProject.h"
#include <iostream>

template<class T>
MyQueue<T>::MyQueue()
{
    node = nullptr;
}

template<class T>
void MyQueue<T>::AddToBack(Node* node, Node* node_to_add)
{
    if(node->back == nullptr)
    {
        node->back = node_to_add;
    }
    else
    {
        AddToBack(node->back, node_to_add);
    }
}


template<class T>
void MyQueue<T>::push_back(T variable)
{
    if(node)
    {
        Node* temp_node = new Node;
        temp_node->data = variable;
        AddToBack(*&node, temp_node);
    }
    else
    {
        node = new Node;
        node->data = variable;
    }
}

template<class T>
T MyQueue<T>::pop()
{
    T i{};
    if(!node)
    {
        std::cout << "No more items in queue" << std::endl;
        return i;
    }

    Node* temp_node = node->back;
    if (node)
    {
        i = node->data;
        delete node;
        node = temp_node;
    }
    return i;
}


int main()
{
    MyQueue<int> queue;

    queue.push_back(10);
    queue.push_back(9);
    queue.push_back(8);


    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;

    return 0;
}

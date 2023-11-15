#ifndef SECONDLESSON_QSLLPROJECT_H
#define SECONDLESSON_QSLLPROJECT_H
template<class T>
class MyQueue
{
struct Node
{
    T data;
    Node* fwrd;
    Node* back;
};
    Node* node;

    void AddToBack(Node* node, Node* node_to_add);
    Node* GetBack(Node node);

public:
    MyQueue();

    T pop();

    void push_back(T variable);

    T front()
    {
       return node->data;
    }

    T back()
    {
       return GetBack()->data;
    }
    ~MyQueue()
    {
        delete node;
    }
};

#endif //SECONDLESSON_QSLLPROJECT_H

#include <iostream>
#include <queue>

struct Node
{
    int data {0};
    Node* left {nullptr};
    Node* right {nullptr};
};

class Tree
{
    Node* root {nullptr};

    void InsertValue(Node* node, const int data)
    {
        if(node->data >= data)
        {
            if(node->left)
                InsertValue(node->left, data);
            else
            {
                node->left = new Node;
                node->left->data = data;
            }
        }
        else
        {
            if(node->right)
                InsertValue(node->right, data);
            else
            {
                node->right = new Node;
                node->right->data = data;
            }
        }
    }

public:
    Tree(Node* &root, const int data)
    {
        root = new Node();
        this->root = *&root;
        root->data = data;
    }

    void InsertValue(const int data)
    {
        if(root->data >= data)
        {
            if(root->left)
                InsertValue(root->left, data);
            else
            {
                root->left = {new Node};
                root->left->data = data;
            }
        }
        else
        {
            if(root->right)
                InsertValue(root->right, data);
            else
            {
                root->right = {new Node};
                root->right->data = data;
            }
        }
    }

    void PrintTree(const Node* node)
    {
        if (node->left)
        {
            PrintTree(node->left);
        }
        std::cout << node->data << std::endl;
        if (node->right)
        {
            PrintTree(node->right);
        }
    }
};

int main()
{
    Node* parent = {nullptr};
    Tree tree(parent, 50);
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < 100; i++)
    {
        int randomNr = rand() % 100 + 1;
        tree.InsertValue(randomNr);
    }

    tree.PrintTree(parent);
}

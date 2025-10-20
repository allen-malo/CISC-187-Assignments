// BinaryTreesLab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T>
struct Node {

    T value;
    Node<T>* rightNode = nullptr;
    Node<T>* leftNode = nullptr;
};

template <typename T>
class BinaryTree {

private:

    Node<T>* rootNode;

    void destroyTree(Node<T>* node)
    {
        if (node != nullptr)
        {
            destroyTree(node->leftNode);
            destroyTree(node->rightNode);
            delete node;
        }
    }

public:
    BinaryTree() : rootNode(nullptr) {}

    ~BinaryTree()
    {
        destroyTree(rootNode);
        rootNode = nullptr;
    }

    void insert(T value)
    {
        Node<T>* newNode = new Node<T>;
        newNode->value = value;
        if (rootNode == nullptr) // Is there a root node?
        {
            rootNode = newNode; // No root node, so this node is now the root
            return;
        }

        Node<T>* current = rootNode;
        Node<T>* parent = nullptr;

        while (current != nullptr)
        {
            parent = current;
            if (value < current->value)
            {
                current = current->leftNode;
            }
            else 
            {
                current = current->rightNode;
            }
        }
        if (value < parent->value)
        {
            parent->leftNode = newNode;
        }
        else
        {
            parent->rightNode = newNode;
        }
    }

    T findGreatestValue()
    {
        Node<T>* current = rootNode; // Start at root node

        // Since the greater value is always going to be towards the right, we are going to traverse to the rightmost node
        while (current->rightNode != nullptr)
        {
            current = current->rightNode;
        }
        // No more rightmost nodes to traverse, so return the value at this node
        return current->value;
    }
};

int main()
{
    //std::cout << "Hello World!\n";

    BinaryTree<int> tree = BinaryTree<int>();
    int values[] = { 1, 5, 9, 2, 4, 13, 10, 6, 3, 8 };
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
    {
        tree.insert(values[i]);
    }

    int greatest = tree.findGreatestValue();
    std::cout << "The greatest value in the tree is: " << greatest << std::endl;
}


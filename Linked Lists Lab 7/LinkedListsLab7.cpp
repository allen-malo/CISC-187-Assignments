// LinkedListsLab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Node struct for LinkedList
template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

// LinkedList class
template <typename T>
class LinkedList
{
private:
    Node<T>* rootNode;

public:

    LinkedList() : rootNode(nullptr) {}

    ~LinkedList()
    {
        Node<T>* current = rootNode;
        while (current != nullptr)
        {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Appends an element to the front of the linkedlist
    void appendElementFront(T value)
    {
        Node<T>* newNode = new Node<T>(); // Create the new node
        newNode->value = value; // Have the new node value point to the specified value
        newNode->next = rootNode; // The new node will point to the previous root node
        rootNode = newNode; // The root node is now the new node.
    }

    // Appends an element to the reat of the linkedlist
    void appendElementRear(T value)
    {
        Node<T>* newNode = new Node<T>();
        newNode->value = value; // New node value points to the specified value

        if (rootNode == nullptr)
        {
            newNode->next = rootNode;
            rootNode = newNode; // Root Node was a null pointer, so assign this node as the root node
            return;
        }
        // Nodes are already in the linkedlist, so we need to iterate to the last node.
        Node<T>* current = rootNode;
        while (current->next != nullptr) // Keep iterating until the pointer to the next node is null (only the last node in the linkedlist will do this)
        {
            current = current->next;
        }
        current->next = newNode; // Have the pointer to the next node at the last node point to the new node.
        
    }

    // Prints out the linkedlist to the console
    void outputList()
    {
        Node<T>* current = rootNode;
        while (current != nullptr)
        {
            std::cout << current->value << std::endl;
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Removes the element at the front of the linkedlist
    T popFront()
    {
        if (rootNode == nullptr)
        {
            return NULL; // Nothing to delete, list is empty
        }
        Node<T>* oldRoot = rootNode; // Old root
        T value = oldRoot->value; // Get value of old node
        rootNode = rootNode->next; // Set the root node to be the next node

        delete oldRoot; // Free memory from old node

        return value; // Return the value from the old root
    }

    // Removes the element at the end of the linkedlist
    T popRear()
    {
        if (rootNode == nullptr)
        {
            return NULL; // Nothing to delete, list is empty
        }
        Node<T>* current = rootNode;
        if (current->next == nullptr)
        {
            // This must be a single node linkedlist
            T value = current->value;
            delete rootNode; // Free memory
            rootNode = nullptr; // Root node is now a null pointer
            return value;
        }
        // More than one node in the linkedlist
        while (current->next->next != nullptr) // Check if the node ahead of the next one is a null pointer (this is how we'll find the second-to-last node)
        {
            current = current->next;
        }
        // Found second-to-last node
        Node<T>* lastNode = current->next; // This is the last node
        T value = lastNode->value; // Value at the last node
        current->next = nullptr; // Second-to-last node will now point to a null pointer
        delete lastNode; // Free memory
        return value; // Return the value from the last node
    }

    // Returns the value at the front of the linkedlist
    T peekFront()
    {
        if (rootNode == nullptr)
        {
            return NULL;
        }
        return rootNode->value;
    }

    // Returns the value at the end of the linkedlist
    T peekRear()
    {
        if (rootNode == nullptr)
        {
            return NULL;
        }
        Node<T>* current = rootNode;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        return current->value;
    }
};


int main()
{
    LinkedList<int> list = LinkedList<int>();
    list.appendElementFront(5);
    list.appendElementFront(4);
    list.appendElementRear(2);
    list.appendElementRear(3);
    list.appendElementFront(1);
    list.outputList();

    int popFront = list.popFront();
    int popRear = list.popRear();
    std::cout << "Popped front value: " << popFront << std::endl;
    std::cout << "Popped rear value: " << popRear << std::endl;
    int peekFront = list.peekFront();
    int peekRear = list.peekRear();
    std::cout << "Peeked front value: " << peekFront << std::endl;
    std::cout << "Peeked rear value: " << peekRear << std::endl;
    list.outputList();
}


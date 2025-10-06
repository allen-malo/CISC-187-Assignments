// StacksAndQueuesLab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Stack {

private:
    int arrSize;
    int top;
    int* arr;
    
public:

    Stack(int size) : arrSize(size)
    {
        arr = new int[size];
        top = 0;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int value)
    {
        if (top > arrSize - 1)
        {
            std::cout << "Stack is full!" << std::endl;
            return;
        }
        arr[top] = value; // Place value at current top position
        top++; // Increment top position by 1
    }

    void pop()
    {
        top--; // Decrement top position
    }

    bool isEmpty()
    {
        return top == 0; // If the top is the first index, then the stack is empty
    }

    int peak()
    {
        return arr[top]; // Get the value at the top of the stack
    }

    void print()
    {
        for (int i = 0; i < top; i++)
        {
            std::cout << "Stack " << i << ": " << arr[top - 1 - i] << std::endl;
        }
        std::cout << std::endl;
    }
};

class Queue
{
private:
    int arrSize;
    int head;
    int tail;
    int elements;
    int* arr;

public:

    Queue(int size) : arrSize(size)
    {
        head = 0;
        tail = 0;
        elements = 0;
        arr = new int[size];
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            std::cout << "Queue is full!" << std::endl;
            return; // Prevent overflow
        }
        arr[tail] = value;
        tail = (tail + 1) % arrSize;
        // Set the new tail position
        // If the new tail position ends up going over the arrSize, then it loops back to the first position of the array

        elements++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty!" << std::endl;
            return; // Prevent underflow
        }
        // Set the new head position
        // If the new head position ends up going over the arrSize, then it loops back to the first position of the array
        head = (head + 1) % arrSize;
        elements--;
    }

    int peak()
    {
        return arr[head];
    }

    bool isEmpty()
    {
        return elements == 0;
    }

    bool isFull()
    {
        return (elements == arrSize);
    }

    void print()
    {
        if (isEmpty())
        {
            return;
        }
        for (int i = 0; i < elements; i++)
        {
            // Get the sum of the head index plus this iteration of the loop, then get the remainder when divided by the arrSize
            // This will get the actual beginning/end of the queue.
            // Ex: If the head is 1, then the tail is 0
            // 1 % 6 = 1
            // 0 % 6 = 0
            int index = (head + i) % arrSize;
            std::cout << "Queue " << i << ": " << arr[index] << std::endl;
        }
        std::cout << std::endl;
    }
};

class Deque
{
private:
    int arrSize;
    int head;
    int tail;
    int elements;
    int* arr;

public:
    Deque(int size)
    {
        head = 0;
        tail = 0;
        elements = 0;
        arrSize = size + 1;
        arr = new int[arrSize];
    }

    ~Deque()
    {
        delete[] arr;
    }

    void addFront(int value)
    {
        if (isFull())
        {
            std::cout << "Deque is full!" << std::endl;
            return;
        }
        head = (head - 1 + arrSize) % arrSize;
        arr[head] = value;
    }

    void addRear(int value)
    {
        if (isFull())
        {
            std::cout << "Deque is full!" << std::endl;
            return;
        }

        arr[tail] = value;
        tail = (tail + 1) % arrSize;
    }

    void removeFront()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty!" << std::endl;
        }
        head = (head + 1) % arrSize;
    }

    void removeRear()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty!" << std::endl;
            return;
        }
        tail = (tail - 1 + arrSize) % arrSize;
    }

    int peakFront()
    {
        return arr[head];
    }

    int peakRear()
    {
        return arr[tail - 1 % arrSize];
    }

    bool isEmpty()
    {
        return head == tail;
    }

    bool isFull()
    {
        return (tail + 1) % arrSize == head;
    }

    void print()
    {
        if (isEmpty())
        {
            return;
        }
        // For this structure, let's iterate until we've reached the tail
        int i = head;
        while (i != tail)
        {
            // This will be the index for the next iteration
            // Once we go over the last position in the array, we'll go straight back to the first position in the array
            
            std::cout << "Deque : " << arr[i] << std::endl;
            i = (i + 1) % arrSize;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Stack testStack = Stack(6);
    testStack.push(4);
    testStack.push(1);
    testStack.push(3);
    testStack.pop();
    testStack.push(8);
    testStack.pop();
    testStack.print();

    Queue testQueue = Queue(6);
    testQueue.enqueue(4);
    testQueue.enqueue(1);
    testQueue.enqueue(3);
    testQueue.dequeue();
    testQueue.enqueue(8);
    testQueue.dequeue();
    testQueue.print();

    Deque testDeque = Deque(6);
    testDeque.addFront(4);
    testDeque.addRear(3);
    testDeque.addRear(2);
    testDeque.addFront(1);
    testDeque.addFront(5);
    testDeque.addFront(6);
    testDeque.addFront(7);
    std::cout << "Front: " << testDeque.peakFront() << std::endl;
    std::cout << "Back: " << testDeque.peakRear() << std::endl;
    testDeque.print();
}
// RecursionLab12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void printEveryOther(int low, int high)
{
    cout << low << endl;
    if (low >= high)
    {
        return; // This is the base case (when the 'low' value reaches or exceeds the 'high' value)
    }
    printEveryOther(low + 2, high);
}

int factorial(int n)
{
    if (n <= 1) // n == 1 is NEVER true if n is originally passed as an even number
    {
        return 1;
    }
    return n * factorial(n - 2);
}

int sum(int low, int high)
{
    if (high <= low) // Added base case
    {
        return 1;
    }
    return high + sum(low, high - 1);
}

int main()
{
    printEveryOther(0, 10);

    int task2 = factorial(10);
    cout << "Task 2: " << endl;
    cout << task2 << endl;

    int task3 = sum(1, 10);
    cout << "Task 3" << endl;
    cout << task3 << endl;
}



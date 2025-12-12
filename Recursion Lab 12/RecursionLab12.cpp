// RecursionLab12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <variant>

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

// Struct for storing Array given for Task 4.
// Task 4's array contains multiple data types (ints, arrays, etc.), so a variant data structure with ints and vectors of itself should be used.
struct NestedArray 
{
    variant<int, vector<NestedArray>> data;
};

void recursive_function(const vector<NestedArray>& main_array, size_t index)
{
    if (index >= main_array.size()) // Have we reached the end of the current array?
    {
        return; // Reached end.
    }
    if (holds_alternative<int>(main_array[index].data)) // Is this an int?
    {
        cout << get<int>(main_array[index].data) << endl; // Print the int
        recursive_function(main_array, index + 1); // Go to the index element/array
    }
    else // Not an int, so this is a vector
    {
        const auto& sub_array = get<vector<NestedArray>>(main_array[index].data);
        recursive_function(sub_array, 0); // Traverse through the sub array
        recursive_function(main_array, index + 1); // Print what is in the sub-array
    }
}

int main()
{
    cout << "Task 1:" << endl;
    printEveryOther(0, 10);
    cout << endl;

    int task2 = factorial(10);
    cout << "Task 2: " << endl;
    cout << task2 << endl << endl;

    int task3 = sum(1, 10);
    cout << "Task 3:" << endl;
    cout << task3 << endl << endl;

    vector<NestedArray> array = {
    {1},
    {2},
    {3},
    {vector<NestedArray>{
        {4}, {5}, {6}
    }},
    {7},
    {vector<NestedArray>{
        {8},
        {vector<NestedArray>{
            {9}, {10}, {11},
            {vector<NestedArray>{
                {12}, {13}, {14}
            }}
        }}
    }},
    {vector<NestedArray>{
        {15}, {16}, {17}, {18}, {19},
        {vector<NestedArray>{
            {20}, {21}, {22},
            {vector<NestedArray>{
                {23}, {24}, {25},
                {vector<NestedArray>{
                    {26}, {27}, {29}
                }}
            }},
            {30}, {31}
        }},
        {32}
    }},
    {33}
    };


    cout << "Task 4:" << endl;
    recursive_function(array, 0);
}

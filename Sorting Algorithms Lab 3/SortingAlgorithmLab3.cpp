// SortingAlgorithmLab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int doubleThenSum(int* arr, const int size)
{
    int* doubledArr = new int[size];
    int steps = 0;
    for (int i = 0; i < size; i++)
    {
        steps++;
        doubledArr[i] = arr[i] * 2;
    }

    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        steps++;
        sum += doubledArr[i];
    }
    std::cout << "Steps: " << steps << std::endl;
    return sum;

    // The time complexity of this algorithm is O(N), since there is a fixed amount of steps per step
}

void multipleCases(std::string* arr, int size)
{
    int steps = 0;
    for (int i = 0; i < size; i++)
    {
        std::string str = arr[i];
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        std::cout << str << std::endl;
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::cout << str << std::endl;
        std::transform(str.begin(), str.begin() + 1, str.begin(), ::toupper);
        std::cout << str << std::endl;
        steps += 3;
    }
    std::cout << "Steps: " << steps << std::endl;
    // The time complexity of this algorithm is O(N), since there is a fixed amount of steps per step
}

void everyOther(int* arr, int size)
{
    int steps = 0;
    for (int i = 0; i < size; i++)
    {
        int n = arr[i];
        steps++;
        if (i % 2 == 0)
        {
            std::cout << "Even index found!" << std::endl;
            for (int j = 0; j < size; j++)
            {
                steps++;
                std::cout << n + arr[j] << std::endl;
            }
        }
    }
    std::cout << "Steps: " << steps << std::endl;

    // This algorithm has a time complexity of O(N^2)
    // The amount of steps per step IS NOT fixed, and is entirely dependent on the size of the array, since we are iterating and doing steps through the array every other step.
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 6, 8 , 9, 10, 12};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    std::string strs[] = {"apple", "orange", "banana", "mango", "peach", "grape"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);

    int doubleSum = doubleThenSum(arr, arrSize);
    std::cout << "Double Sum: " << doubleSum << std::endl;

    multipleCases(strs, strsSize);

    everyOther(arr, arrSize);
}

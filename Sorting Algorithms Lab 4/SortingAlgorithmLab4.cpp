// SortingAlgorithmLab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

void outputArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

void insertionSort(int* arr, int size)
{
    
    for (int i = 1; i < size; i++)
    {
        std::cout << "Index of inspected value: " << i << std::endl;
        int j = i;
        // arr[j] is the inspected value, which is changing for each iteration of the outer loop
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j -= 1;
        }        
    }
}

bool containsX(std::string str)
{
    bool foundX = false;
    int steps = 0;
    for (int i = 0; i < str.length(); i++)
    {
        steps++;
        if (str[i] == 'X')
        {
            foundX = true;
        }
    }
    std::cout << "The linear search took: " << steps << " step(s) to complete!" << std::endl;
    return foundX;
}

std::string bubbleSortLetters(std::string str)
{
    int len = str.length();
    bool swapped;
    int totalSteps = 0;
    for (int i = 1; i < len; ++i)
    {
        swapped = false;
        int steps = 0;
        for (int j = 1; j < len - i + 1; ++j)
        {
            steps++;
            if (str[j - 1] > str[j])
            {
                char temp = str[j - 1];
                str[j - 1] = str[j];
                str[j] = temp;
                swapped = true;
                steps++;
            }
        }
        totalSteps += steps;
        if (!swapped)
        {
            break;
        }
    }
    std::cout << "Steps for 'bubbleSortLetters': " << totalSteps << std::endl;
    return str;
}

bool containsXBinary(std::string str)
{
    int l = 0;
    int r = str.length() - 1;
    int steps = 0;
    while (l <= r)
    {
        steps++;
        int i = floor((l + r) / 2);
        if (str[i] < 'X')
        {
            l = i + 1;
        }
        else if (str[i] > 'X')
        {
            r = i - 1;
        }
        else
        {
            std::cout << "The binary search took " << steps << " step(s) to complete!" << std::endl;
            return true;
        }
    }

    return false;
}

bool containsXInterpolation(std::string str)
{
    int l = 0;
    int r = str.length() - 1;
    char target = 'X';
    int steps = 0;
    while (l <= r && target >= str[l] && target <= str[r])
    {
        steps++;
        int rl = r - l;
        int rlDiff = str[r] - str[l];
        int targetlDiff = target - str[l];
        int i = l + ((rl) * (targetlDiff) / (rlDiff)); // Guess the estimated position of the desired value in the array
        if (str[i] > target)
        {
            l = i + 1;
        }
        else if (str[i] < target)
        {
            r = i - 1;
        }
        else
        {
            std::cout << "The interpolation search took " << steps << " step(s) to complete!" << std::endl;
            return true;
        }
    }
    return false;
}

int main()
{

    int arr[] = { 5, 4, 3, 2, 1 };
    insertionSort(arr, 5);
    outputArray(arr, 5);
    
    std::string str = "XFEDCBA";
    str = bubbleSortLetters(str);

    std::cout << str << std::endl;

    bool hasX = containsX(str); // O(N) time complexity
    bool hasXBinary = containsXBinary(str); // O(Log(2, N)) time complexity
    bool hasXInterpolation = containsXInterpolation(str); // O(Log(2, Log(2, N))) time complexity

    std::cout << "Has X: " << hasX << std::endl;
    std::cout << "Has X (Binary): " << hasXBinary << std::endl;
    std::cout << "Has X (Interpolation): " << hasXInterpolation << std::endl;
}

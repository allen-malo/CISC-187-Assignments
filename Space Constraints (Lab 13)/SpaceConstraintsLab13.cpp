// SpaceConstraintsLab13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <typename T>
stack<T> wordbuilder(vector<T> array)
{
    stack<T> collection;
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array.size(); j++)
        {
            if (i != j)
            {
                collection.push(array[i] + array[j]);
            }
        }
    }
    return collection;

    // Space Complexity: O(N^2)
    // For each position in the array, we are iterating over the entire array. We are creating N^2 combinations and pushing them to the stack.
}

template <typename T>
vector<T> reverse(vector<T> array)
{
    vector<T> newArr(0);
    for (int i = array.size() - 1; i >= 0; i--)
    {
        newArr.push_back(array[i]);
    }
    return newArr;

    // Space Complexity: O(N)
    // We are creating a new array to store the elements in reverse.
}

template <typename T>
vector<T> reverseNew(vector<T> array)
{
    int left = 0;
    int right = array.size() - 1;

    while (left < right)
    {
        // Swap element from the left with element from the right
        T temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++; // Move left position closer to center
        right--; // Move right position closer to center
    }
    // Left and right indices have met. We are done reversing the array.
    return array;

    // Space Complexity: O(1)
    // No new array is created to store elements. Placement of elements are swapped.
}

template <typename T>
vector<T> doubleArray1(vector<T> array)
{
    vector<T> newArray(0);
    for (int i = 0; i < array.size(); i++)
    {
        newArray.push_back(array[i] * 2);
    }
    return newArray;

    // Time Complexity: O(N)
    // - Iterating through whole array, which contains N elements.
    // 
    // Space Complexity: O(N)
    // - Creates a whole new array to copy to, which will contain N elements.
}

template <typename T>
vector<T> doubleArray2(vector<T> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        array[i] *= 2;
    }
    return array;

    // Time Complexity: O(N)
    // - Iterating through whole array, which contains N elements.
    //
    // Space Complexity: O(1)
    // - Everything takes place in the same array. No new arrays are made.
}

template <typename T>
vector<T> doubleArray3(vector<T> array, int index)
{
    if (index >= array.size())
    {
        return array;
    }
    array[index] *= 2;
    
    return doubleArray3(array, index + 1);

    // Time Complexity: O(N)
    // - Iterating through whole array, which contains N elements.
    //
    // Space Complexity: O(N)
    // - Despite using the same array that was provided, each recursive call adds a frame to the call stack. This gives us N frames for N elements, hence the space complexity of O(N)
}

template <typename T>
void printArray(vector<T>& array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
}

template <typename T>
void printStack(stack<T> stack)
{
    for (int i = 0; i < stack.size(); i++)
    {
        cout << stack.top() << ", ";
        stack.pop();
    }
    cout << endl;
}

int main()
{
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
    stack<int> coll = wordbuilder(arr);
    printStack(coll);

    vector<int> reverseArrOld = reverse(arr);
    vector<int> reverseArrNew = reverseNew(arr);

    printArray(reverseArrOld);
    printArray(reverseArrNew);

    vector<int> double1 = doubleArray1(arr);
    vector<int> double2 = doubleArray2(arr);
    vector<int> double3 = doubleArray3(arr, 0);

    printArray(double1);
    printArray(double2);
    printArray(double3);
}

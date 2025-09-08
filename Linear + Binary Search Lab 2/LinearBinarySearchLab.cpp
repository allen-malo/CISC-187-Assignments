#include <iostream>

using namespace std;

int linearSearch(int* arr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Step " << i + 1 << " for linear search" << endl;
        if (arr[i] == value)
        {
            // Value at this position in the array matches the value we are searching for!
            cout << "The linear search took " << i + 1 << " step(s) to complete!" << endl;
            return i;
        }
    }
    return -1;
}

int binarySearch(int* arr, int size, int value)
{
    int l = 0;
    int r = size - 1;
    int steps = 0;
    while (l <= r)
    {
        steps++;
        cout << "Step " << steps << " for binary search" << endl;
        int i = floor((l + r) / 2);
        if (arr[i] < value) 
        {
            // Value we want is bigger than the value at this position
            // So, let's shift our search towards the right
            cout << "move right" << endl;
            l = i + 1;
        }
        else if (arr[i] > value)
        {
            // Value we want is smaller than the value at this position
            // So, let's shift our search towards the left
            cout << "move left" << endl;
            r = i - 1;
        }
        else
        {
            // Found the value!
            cout << "The binary search took " << steps << " step(s) to complete!" << endl;
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 13};
    int arrSize = sizeof(arr) / sizeof(int);

    linearSearch(arr, arrSize, 13);
    binarySearch(arr, arrSize, 13);
}



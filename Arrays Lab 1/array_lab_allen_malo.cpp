//
// Created by allen on 8/31/2025.
//

#include <iostream>

using namespace std;

void outputArray(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": " << arr[i] << endl;
    }
}

int main() {

    // TASK 1 (Creating an array)
    int size = 100;
    int arr[size]; // Create an array with 100 elements

    int newArr[100];

    for (int i = 0; i < size; i++) arr[i] = 0; // Initialize each element in the array with a value of 0

    outputArray(arr, size);


    // TASK 2 (Size of each element in an array)
    int elementSize = sizeof(arr[0]);

    cout << "Element Size: " << elementSize << endl;

    // TASK 5 (How to get the memory address of an array)
    cout << &arr << endl;

    return 0;
}
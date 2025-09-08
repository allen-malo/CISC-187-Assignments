
**1. How many steps would it take to perform a linear search for the number 8 in the ordered array: [2, 4, 6, 8, 10, 12, 13]?**

Using a linear search for the number 8 in the given array would take 4 steps, since the number 8 is the 4th element (index 3) of this array. Given that 8 is the 'x'th element of an array of length 'N', the linear search would take 'x' steps to find the number 8.

In Big O Notation, the linear search algorithm step count is expressed as O(N), where N is the size of the array. Since the number 8 is the 4th element of this array, this could be expressed as O(4).

**2. How many steps would a binary search take for the previous example?**

Using a binary search algorithm on the array mentioned previously to find the number 8 would take only 1 step. The algorithm attempts to start as close as it can to the center of the array, and since 8 is located at the middle index, only one step was needed to find it.

In Big O Notation, the binary search algorithm step count is expressed as O(log<sub>2</sub>N), where N is the size of the array.

**3. What is the maxiumum numbers of steps it would take to perform a binary search on an array size of 100,000?**

In Big O Notation, the binary search algorithm step count is expressed as O(log<sub>2</sub>N), where N is the size of the array. If the array size is 100,000, then the search will take at most log<sub>2</sub>100000 steps, which is equal to 17 steps (rounded up from 16.6096404744).

**4. Write C++ code that implements the linear and binary search algorithms. The algorithm should be able to calculate the number of steps against the given search.**

These are functions that implement the linear and binary search. When the desired value is found in the array, the index of the element in the array is returned. If the value is never found, then -1 is returned.

Linear Search:
```cpp

int linearSearch(int* arr, int size, int value)
{
  for (int i = 0; i < size; i++)
  {
    cout << "Step " << i + 1 << " for linear search" << endl;
    if (arr[i] == value)
    {
      cout << "The linear search took " << i + 1 << "step(s) to complete!" << endl;
      return i;
    }
  }
  return -1;
}
```

Binary Search:
```cpp
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
      l = i + 1;
    }
    else if (arr[i] > value)
    {
      r = i - 1;
    }
    else
    {
      cout << "The binary search took " << steps << "step(s) to complete!" << endl;
      return i;
    }
  }
  return -1;
}
```

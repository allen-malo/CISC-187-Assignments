[Video Link](https://youtu.be/D2q7eV3q7Tk)

**1. Proof that, under the average-case scenario, the insertion sort has a time complexity of _O(N<sup>2</sup>)_. Draw a clear figure and show all the operations clearly**

The average-case scenario for the insertion sort algorithm will have a time complexity of _O(N<sup>2</sup>)_. Let's prove it!

Let's say we are on the _i_-th element of the array we are sorting (A[_i_]). This element is being considered for insertion into our already-sorted subarray. For this, we'll have to find the total number of expected comparisons and shifts for each element from i = 2 to N, which can be written as:

$\sum_{i=2}^n \frac{i+1}{2}$

When this sum is fully simplified, it becomes:

$\frac{1}{2}$ $\sum_{i=1}^n i - (1 + 1)$

= $\frac{1}{2}$ * $\frac{(N + 1)(N + 2)}{2}$ - 2

Which in Big O Notation, becomes _O(N<sup>2</sup>)_

**2. At the start of the insertion sort, the index of the inspected value is set to 1. Change the index of the inspected value and verify that the total number of operations equals 20. Consider the worst-case scenario. Use N=5, where N is the number of elements.**

So, if we change the index of the inspected value, we will have 20 total operations (worst case scenario). Why is this?

- When the iterator is at 1, we are inspecting the second element in the array vs the first element (index 0). There will be 2 operations here. One operation is for a comparison, and the other is for shifting elements.
- When the iterator is at 2, we are inspecting the third element in the array, and comparing it to the second (index 1) and first (index 0). There will be 4 operations total here. Two for comparisons, and two for shifting elements.
- When the iterator is at 3, we are inspecting the fourth element in the array, and comparing it with all elements at the previous indicies. There will be 6 operations total here. Three for comparisons, and three for shifting elements.
- When the iterator is at 4, we are inspecting the final element in the array, and comparing it will all previous elements. There will be 8 operations total here. Four for comparisons, and four for shifting elements.
- In total, we have 2 + 4 + 6 + 8, which is 20 total operations!

**3. The following function returns whether or not a capital "X" is present within a string.**

**a) What is this function's time complexity regarding Big O Notation?**

Since this function is performing a linear search to find a capital "X", the time complexity will be _O(N)_.

**b) Then, modify the code to improve the algorithm's efficiency for best- and average-case scenarios.**

Original function (Linear Search):
- Best-case: _O(1)_ (First position in the string)
- Average-case: _O(N)_ (Middle position in the string)

New Function (Interpolation Search):
- Best-case _O(1)_ (Algorithm correctly guesses the position of the value to find)
- Average-case: _O(log<sub>2</sub>(log<sub>2</sub>N))_ (Algorithm keeps moving in the general direction of the value to find)
- **NOTE:** this will only work if the characters in the string are sorted!

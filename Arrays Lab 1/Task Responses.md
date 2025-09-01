[Video Link](https://youtu.be/LCuI1Jfgrhg)

**1. Explain how to create an array of 100 elements.**

An array of 100 ints can be created by typing:

int arr[100];

or...

int arr[] = {1, 2, 3, ..., 97, 98, 99, 100};

Initializing each element in the array is also just as easy, which can be done using a for loop. The loop is: 

for (int i =0; i < 100; i++) arr[i] = 0;

**2. What will be the size of each element of an array?**

The size of each element in an array is the amount of bytes that data type occupies in memory. For example, in an array of int data types, each element would take up 4 bytes of memory.

**3. For an array containing 100 elements, provide the number of steps the following operations would take:**
**a) Reading**

This would take 100 steps, since there are 100 elements and each read operation is 1 step.

**b) Searching for a value not contained within an array**

Searching for a value not contained in an array would mean that we've searched the entire array and did not find the value we were searching for. This would take 100 steps, since we are reading through 100 variables.

**c) Insertion at the beginning of the array**

Insertion at the beginning of an array would take 101 steps. The compiler/interpreter needs to increase the array size and allocate a new memory address for the new element. Since we are inserting the element at the start of the array, all elements in the array need to be shifted up by 1 position, which takes 100 steps. Finally, we can insert the new element into the starting index of the array, which takes 1 step.

**d) Insertion at the end of the array**

Insertion at the end of the array would take 1 step. The compiler/interpreter needs to increase the array size and allocate a new memory address, and then insert the element at the last index of the array (the new position created).

**e) Deletion at the beginning of the array**

Deletion at the beginning of the array would take 100 steps. We need to first delete the first element in the array (1 step), and then shift all the remaining elements back 1 position (99 steps).

**f) Deletion at the end of the array**

Deletion at the end of the array would only take 1 step, which is just deleting the last element in the array.

**4. Normally the search operation in an array looks for the first instance of a given value. But sometimes we may want to look for every instance of a given value. For example, say we want to count how many times the value "apple" is found inside an array. How many steps would it take to find all the "apples"? Give your answer in terms of N.**

If a linear search algorithm is used, it could take up to N steps to find all the "apples", since N is the array size.
HOWEVER, if our data was organized by value, we could make use of a log search algorithm, where we start at the middle index of the array, and use the current value and target value to determine which direction to search in next. This can help speed up the search speed

**5. Research how to find the memory address of an array. You can use any programming language of your choice.**

The memory address of an array in C++ can be found easily by using a "cout" line where you try to output the array directly. The "address-of" operator, "&", can also be used as a prefix for the array variable being called

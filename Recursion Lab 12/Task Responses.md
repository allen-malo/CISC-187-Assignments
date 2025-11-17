
**1. The following function prints every other number from a low number to a high number. For example, if low is 0 and high is 10, it would print:** ```0, 2, 4, 6, 8, 10```**. Identify the base case in the function**

```
def print_every_other(low, high)
  return if low > high
  puts low
  print_every_other(low + 2, high)
end
```

Before we go over where the base case is located in this function, we need to understand what a recursive function is, and what exactly it contains.

A recursive function is a function that calls upon itself, acting very similar in behavior to a loop. These functions contain two vital components: The recursive case, and the base case.

The recursive case is the part of the recursive function that gives it its name. It's what allows the code to 'loop', and effectively makes this a function that calls itself.

The base case of the function is what effectively terminates the recursiveness of the function. We cannot have a recursive function call itself forever, as the call stack only has so much memory to store functions it's currently calling. Without the base case, our recursive function would endlessly call itself until a stack overflow occurs, meaning that the computer no longer has enough room in memory to keep calling the function.

For a recursive function to work, both the base case and recursive case MUST be reachable.

Now that we've gone over what a recursive function is, and what it contains, we can clearly see that the base case in the function is the first line of code, ```return if low > high```.

**2. My kid was playing with my computer and changed my factorial function so that it computes factorial based on (n - 2) insteaad of (n - 1). Predict what will happen when we run factorial(10) using this function:**

```
def factorial(n)
  return 1 if n == 1
  return n * factorial(n - 2)
end
```

At first, you might think that upon running this function, we'd get 10 * 8 * 6 * 4 * 2, but this is not the case! Our base case checks if n == 1, and returns 1 if true. However, since we are staring with an even number and subtracting 2 upon each call, we will NEVER reach the base case of this factorial function, thus leading to a stack overflow.

If we decide to fix the function to accomodate this change, then we should check if n <= 1 so that when we reach 0, we can actually reach the base case and end our recursive calls. With the fix, this function will return 3840.

**3. Following is a function in which we pass in two numbers called low and high. The function returns the sum of all the numbers from low to high. For example, if low is 1 and high is 10, the function will return the sum of all numbers from 1 to 10, which is 55. However, our code is missing the base case, and will fun indefinitely! Fix the code by adding the correct base case:**

```
def sum(low, high)
  return high + sum(low, high - 1)
end
```

This function here is clearly missing a base case, and calling the function in its current state will lead to a stack overflow. Here, we want to check if ```high <= low``` is true, and return 1 if so.

Here is the C++ implementation of the function with the fix:

```
int sum(int low, int high)
{
  if (high <= low) // Added base case
  {
    return 1;
  }
  return high + sum(low, high - 1);
}
```

**4. Here is an array containing both numbers as well as other arrays, which in turn contain numbers and arrays:**

```
array = [1, 2, 3, [4, 5, 6], 7, [8, [9, 10, 11, [12, 13, 14]]], [15, 16, 17, 18, 19, [20, 21, 22, [23, 24, 25, [26, 27, 29]], 30, 31], 32, ], 33,]
```

**Write a recursive function that prints all the numbers (and just numbers).**

For this specific task, we are going to write this in Python. This does not change the understanding and concepts of recursion.

This array contains many integers that are scattered and grouped in an odd configuration of arrays within arrays. Let's see how this looks recursively.

For this function, we are going to have two parameters: 
- The main array
- The starting index

Since this will be a recursive function, we also need a base case, and a recursive case.

Our base case will check if the index passed through is equal to or greater than the length of the array passed through. If this is true, then we end the current function call. Otherwise, we'll go onto our recursive cases.

For our recursive cases, this is where things can get tricky. We're first going to check if the element at the current index of the array is an integer or an array. If it is an integer, then we are going to print the integer, and perform a recursive call where we increment the index by 1. If the element is a list, then we will call the function recursively by passing the current element (an array) to a recursive call, starting at the first index of this array. However, we are not done yet. If we forget this last, important step, then our function stops after 6, since the base case is reached and nothing else is called for printing the next numbers. In order to keep printing our numbers in this complex array, we have to perform a recursive call on the main array and increment the index by 1. That way, after processing the sub-array, we go back to the main to continue.

With all of this said, our function will look like this:

```
def recursive_function(main_array, index):
  if index >= len(main_array): # Have we reached the end of the current array?
    return
  var_type = type(main_array[index])
  if var_type == int: # Are we on an int?
    # We are, so print the contents
    print(main_array[index])
    recursive_function(main_array, index + 1)
  elif var_type == list: # Are we on a list?
    # In a sub-array, so get the sub-array
    sub_array = main_array[index]
    recursive_function(sub_array, 0) # Print what is in the sub-array

    recursive_function(main_array, index + 1) # Done printing the numbers in the sub array, so go back to the main array

```

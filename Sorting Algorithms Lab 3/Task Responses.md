[Video Link](https://youtu.be/akyxCLAxH0A)

**1. Use Big O Notation to describe the time complexity of an algorithm that takes $4N + 16 steps$.**

The time complexity of an algorithm that takes $4N + 16 steps$ in Big O Notation is just $O(N)$. An important thing to note about Big O Notation is that it ignores constants and numbers that aren't exponents. So for $4N + 16$, 4 and 16 are ignored because they are both numbers/constants that aren't exponents.

**2. Use Big O Notation to describe the time complexity of an algorithm that takes $2N^2 steps$**

The time complexity of an algorithm that takes $2N^2 steps$ in Big O Notation is just $O(N^2)$. Remember that the 2 preceeding $N$ is just a number/constant that isn't related to an exponent, so it is ignored. However, the 2 that acts as an exponent is not ignored because the role the exponent plays as $N$ gets larger stays relevant.

**3. Use Big O Notation to describe the time complexity of the following function, which returns the sum of all numbers of an array after the numbers have been doubled**

This algorithm is going to take $2N$ steps. It will take $N$ steps to double all the numbers in the array, and then another $N$ steps to get the sum of all the numbers in the array. In terms of Big O Notation, the time complexity of this function is $O(N)$.

**4. Use Big O Notation to describe the time complexity of the following function, which accepts an array of strings and prints each string in multiple cases**

Similar to the last function, this function is iterating over the entire array, which takes $N$ steps to do. At each step, we are printing the string in uppercase, lowercase, and capitalized, which is 3 additional steps for every step. That means this function will take $6N$ steps to complete, which is described as $O(N)$ in Big O Notation.

**5. The next function iterates over an array of numbers, and for each number whose index is even, it prints the sum of that number plus every number in the array. What is this function's efficiency in terms of Big O Notation?**

In terms of Big O Notation, this functions efficiency is $O(N^2)$. We are iterating over the entire array (which takes $N$ steps), and then for every even index, we are iterating over the entire array again (which also takes $N$ steps). Ignoring all numbers/constants that aren't exponents, the efficiency of the function in Big O Notation is $O(N^2)$ (because $N * N = N^2$).

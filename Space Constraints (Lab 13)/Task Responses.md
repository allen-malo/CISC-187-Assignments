[Video Link](https://youtu.be/8n0FXnNkINM)

**1. Following the the 'Word Builder' algorithm. Describe its space complexity in terms of Big O:**
```
function wordBuilder(array) { 
		let collection = [];
		for(let i = 0; i < array.length; i++) { 
				for(let j = 0; j < array.length; j++) {
						if (i !== j) {
								collection.push(array[i] + array[j]);
						}
				}
		}
		return collection; 
}
```

Before we go over the space complexity of this function, let's go over what space complexity is, and what it means.

Space complexity is a measure of how much memory an algorithm needs to run, relative to its output. Computers do not have infinite memory (some have very little), so we need a way to measure how much memory algorithms can use. Similarly to time complexity, it is measure in Big O Notation. Having a lower space complexity is better, and sometimes it can come with tradeoffs (such as a slower time complexity). This would be useful for hardware that doesn't have a lot of memory to work with.

The space complexity of the 'Word Builder' algorithm is _O(N<sup>2</sup>)_, where _N_ is the array size. We are iterating over the entire array, and for each position except its own, we push the sum of the elements to the stack. We'll have a total of _N(N-1)_ combinations, which simplifies to _N<sup>2</sup>_ in Big O Notation (Since we ignore constants and lower degree terms). This gives us a space complexity of N<sup>2</sup>, since we are creating N<sup>2</sup> combinations.

**2. Following is a function that reverses an array. Describe its space complexity in terms of Big O:**
```
function reverse(array) { 
		let newArray = [];
		for (let i = array.length - 1; i >= 0; i--) { 
				newArray.push(array[i]);
		}
		return newArray;
}
```

The space complexity of this array is _O(N)_. We are creating a new array to store _N_ elements in reverse order. 

**3. Create a new function to reverse an array that takes up just O(1) extra space.**

Since we want a space complexity of _O(1)_, we **must** make use of the existing array we pass through the function. Therefore, we'll make an algorithm to swap the places of elements from front to back as so:

```
template <typename T>
vector<T> reverseNew(vector<T> array)
{
  int left = 0;
  int right = array.size() - 1;
  while (left < right)
  {
    // Swap element from the left with elements from the right
    T temp = array[left];
    array[left] = array[right];
    array[right] = temp;
    left++; // Move left position closer to center
    right--; // Move right position closer to center
  }
  return array;
}
```

**4. Following are three different implementation of a function that accepts an array of numbers and returns an array containing those numbers multiplied by 2. For example, if the input is [5, 4, 3, 2 ,1], the output will be [10, 8, 6, 4, 2].**
```
function doubleArray1(array) { 
	let newArray = [];

	for(let i = 0; i < array.length; i++) { 
		newArray.push(array[i] * 2);
	}
	return newArray; 
}


function doubleArray2(array) {
	for(let i = 0; i < array.length; i++) {
  	array[i] *= 2;
  }
	return array; 
}


function doubleArray3(array, index=0) { 
	if (index >= array.length) { return; }
  array[index] *= 2;
  doubleArray3(array, index + 1);
	return array; 
}
```
**Fill in the table that follows to describe the efficiency of these three versions in terms of both time and space:**

| Version    | Time complexity | Space complexity |
| ---------- | --------------- | ---------------- |
| Version #1 | ?               | ?                |
| Version #2 | ?               | ?                |
| Version #3 | ?               | ?                |

The completed table is as follows:

| Version    | Time complexity | Space complexity |
| ---------- | --------------- | ---------------- |
| Version #1 | O(N)            | O(N)             |
| Version #2 | O(N)            | O(1)             |
| Version #3 | O(N)            | O(N)             |

**Justification for Version #1:**

The time complexity is _O(N)_ since we are iterating over the entire array and performing operations on _N_ elements in the array. The space complexity is _O(N)_ as well, since we are creating a new array that will contain _N_ elements.

**Justification for Version #2:**

The time complexity is _O(N)_ since we are iterating over the entire array and performing operations on _N_ elements in the array. The space complexity is _O(1)_, since we are reusing the old array instead of creating a new one.

**Justification for Version #3:**

The time complexity is _O(N)_ sincer we are iterating over the entire array and performing operations on _N_ elements in the array. The space complexity is _O(N)_, since we use recursion to iterate through the array. Each recursive call adds a frame to the call stack, thus giving us N frames for N elements.

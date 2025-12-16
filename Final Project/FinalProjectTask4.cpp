
#include <iostream>
#include <vector>

using namespace std;

// Task 4 (DONE)

// This is a struct used to save a number and its position
struct NumberVar {
	int number = 0;
	int position = -1;
};

int findGreatestProduct(vector<int> arr)
{
	// Time Complexity MUST be O(N)

	// The struct above this function is used to save values from the array. Since duplicates are possible, we need to save the value AND index of the largest and smallest
	// values. That way, when we go to multiply these values with other values in the array, we:
	// - Don't multiply an element with itself (element in the same position)
	// - Can multiply with duplicates if duplicate elements are present.

	// 1. Let's save the largest and smallest numbers in the array, as well as their positions. We save their positions for the possibility of duplicates.

	// 2. Now that we've saved the largest and smallest numbers in the array, let's use a for-loop for each to find the largest products for both

	// 3. Now that we've found the largest products for both, we'll only return the largest of the two.

	// Time complexity: O(N)
	// O(N) - From looping over array to find the largest and smallest numbers
	// O(N) - From looping over the array again to find the largest product using the smallest number
	// O(N) - From looping over the array again to find the largest product using the largest number

	if (arr.empty())
	{
		return 0; // No elements in the array. Just return 0
	}
	if (arr.size() < 2)
	{
		return arr[0]; // Only one element in the array. Just return the only element given.
	}
	NumberVar smallest;
	NumberVar largest;

	for (int i = 0; i < arr.size(); i++)
	{
		int number = arr[i];
		if (smallest.number > number)
		{
			smallest.number = number;
			smallest.position = i;
		}
		else if (largest.number < number)
		{
			largest.number = number;
			largest.position = i;
		}
	}

	int largestProduct = INT_MIN;

	// Find products using smallest number found
	for (int i = 0; i < arr.size(); i++)
	{
		if (smallest.position == i)
		{
			continue; // Do not multiply number with itself. This doesn't count
		}

		int product = smallest.number * arr[i];
		if (product > largestProduct)
		{
			largestProduct = product;
		}
	}

	// Find products using largest number found
	for (int i = 0; i < arr.size(); i++)
	{
		if (largest.position == i)
		{
			continue; // Do not multiply number with itself. This doesn't count
		}

		int product = largest.number * arr[i];
		if (product > largestProduct)
		{
			largestProduct = product;
		}
	}

	// Return the largest product
	return largestProduct;
}

int main()
{
	vector<int> arr = { 5, -10, -6, 9, 4 };

	int largestProduct = findGreatestProduct(arr);
	cout << "Task 4:" << endl;
	cout << "The largest product from the given array is: " << largestProduct << endl << endl;
}
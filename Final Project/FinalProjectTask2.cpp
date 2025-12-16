#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Task 2 (DONE)
int findMissingNumber(vector<int> arr)
{
	// Time Complexity MUST be O(N)

	// 1. This algorithm uses an unordered set to save the integers from the array as keys. We'll also get the highest number in the array, since this is N.
	// Inserting the numbers into the unordered set and finding N provides a time complexity of O(N).

	// 2. Once we get the highest value in the array, we'll use that to know that we need every number from 0-N
	// Since the numbers from the array are now saved as keys in the unordered set, we'll loop through every number from 0-N. If a key does not exist for a number between 0 and N, then that means we've found the missing number.
	// This has a time complexity of O(N), since we are looping over N elements and unordered sets have a lookup time of O(1).

	// From both these steps, we have a final time complexity of O(N)

	// Find the highest value in the array.

	if (arr.empty())
	{
		return -1; // Empty array
	}

	unordered_set<int> numbers;
	int max = 0;
	for (int number : arr)
	{
		numbers.insert(number);
		if (number > max)
		{
			max = number;
		}
	}

	for (int i = 0; i < max; i++)
	{
		if (numbers.find(i) == numbers.end()) // Is this the missing number?
		{
			return i; // Missing number found
		}
	}

	return max + 1; // No number is missing, so return -1
}

int findMissingNumberSummation(vector<int> arr)
{

	// ALTERNATIVE APPROACH:
	// Find the sum of the numbers from 0-N (Expected Sum), where N is the array size
	// Compare with the sum of the values from the given array (Actual Sum)
	// The difference between the Expected Sum and Actual Sum is the missing number

	int n = arr.size();

	int expectedSum = n * (n + 1) / 2;

	int actualSum = 0;
	for (int num : arr)
	{
		actualSum += num;
	}
	return expectedSum - actualSum;
}

int main()
{
	vector<int> arr1 = { 2, 3, 0, 6, 1, 5 };
	vector<int> arr2 = { 8, 2, 3, 9, 4, 7, 5, 0, 6 };

	vector<int> arr3 = { 1, 2, 3, 4 };
	vector<int> arr4 = { 0, 1, 2, 3, 4 };

	int missing1 = findMissingNumber(arr1);
	int missing2 = findMissingNumber(arr2);

	int missing3 = findMissingNumberSummation(arr3);
	int missing4 = findMissingNumberSummation(arr4);

	cout << "Task 2:" << endl;
	cout << "The missing number for array 1 is: " << missing1 << endl;
	cout << "The missing number for array 2 is: " << missing2 << endl;
	cout << "The missing number for array 3 is: " << missing3 << endl;
	cout << "The missing number for array 4 is: " << missing4 << endl << endl;
}

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Task 6
int findLongestStreak(vector<int> numbers)
{
	// Time complexity MUST be O(N)

	// For this function, we want to keep track of what numbers are present in the given array and keep track of the current streak and longest streak found.

	// 1. Create an unordered set that contains the numbers from the given array. The time complexity here is O(N).

	// 2. Declare an int for tracking the longest streak.

	// 3. Loop through all the elements in the unordered set.
	// During this looping, we'll want to keep track of the following:
	// - Current streak
	// - Longest streak
	// In order to find a streak, we must find the first number of that sequence. In order to do so, we'll check to see if the previous number is present in the set.
	// - If the previous number is present in the set, we are not at the start of the sequence. Do not start counting the streak.
	// - If the previous number is NOT present in the set, we can start counting the sequence and keeping track of the streak.
	// After we run out of consecutive numbers (streak breaks), then we set the longest streak to be the biggest of the two:
	// - The current longest streak
	// - The streak just found.
	//
	// The MOST amount of times a number will be visited in the set is TWICE:
	// - First time to check if it is the start of a sequence.
	// - Second time to check if it part of a sequence.
	// From this, we'd get a step count of N + S, where...
	// - N is the array size
	// - S is the sum of all the lengths of the streaks present in the set. S will NEVER be larger than N; it can only be less than or equal to N.
	// This means in a worst-case scenario, all numbers in the array are checked twice, giving 2N steps.
	//
	// Given the time complexity from Step 1, and the step count from Step 3, the time complexities for each step are:
	// - O(N)
	// - O(N)
	// This gives a time complexity of O(N) for this function!

	unordered_set<int> nums(numbers.begin(), numbers.end());
	int longestStreak = 1;
	for (int num : nums)
	{
		if (nums.find(num - 1) == nums.end())
		{
			int currentNum = num;
			int currentStreak = 1;

			while (nums.find(currentNum + 1) != nums.end())
			{
				currentNum++;
				currentStreak++;
			}

			longestStreak = max(longestStreak, currentStreak);
		}
	}

	return longestStreak;
}

int main()
{
	cout << "Task 6:" << endl;
	vector<int> ex1 = { 10, 5, 12, 3, 55, 30, 4, 11, 2 };
	vector<int> ex2 = { 19, 13, 15, 12, 18, 14, 17, 11 };

	int longestStreak1 = findLongestStreak(ex1);
	int longestStreak2 = findLongestStreak(ex2);

	cout << "The longest streak for array 1 is: " << longestStreak1 << endl;
	cout << "The longest streak for array 2 is: " << longestStreak2 << endl;
}
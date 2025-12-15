// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <queue>

using namespace std;

// Task 1 (DONE)
class PlayerData {
private:
	string firstName;
	string lastName;
	string team;

public:
	PlayerData(string firstName, string lastName, string team)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->team = team;
	}

	string getFirstName()
	{
		return this->firstName;
	}

	string getLastName()
	{
		return this->lastName;
	}

	string getTeam()
	{
		return this->team;
	}
};

vector<string> findPlayersInBothSports(vector<PlayerData> sport1, vector<PlayerData> sport2)
{
	// Time Complexity MUST be O(N + M)

	// 1. This algorithm will take one of the given arrays of PlayerData, and put it into an unordered set. This step gives a time complexity of O(N).
	// The keys for the unordered set are the player's full names.
	
	// 2. We will then loop over the second sport's player data onto the unordered map to check for any matches, giving a time complexity of O(M).
	// Unordered maps have an average constant-time complexity of O(1) for searches, insertions, and deletions.

	if (sport1.empty() || sport2.empty())
	{
		return vector<string>(); // Return an empty array. There is no player in common if at least one of the arrays is empty
	}

	unordered_set<string> players;
	for (PlayerData playerData : sport1) 
	{
		string key = playerData.getFirstName() + " " + playerData.getLastName();
		players.insert(key);
	}

	vector<string> commonPlayers;
	for (PlayerData playerData : sport2)
	{
		string key = playerData.getFirstName() + " " + playerData.getLastName();
		if (players.find(key) != players.end())
		{
			commonPlayers.push_back(key);
		}
	}
	return commonPlayers;
}

void task1()
{
	vector<PlayerData> basketballPlayers = {
		PlayerData("Jill", "Huang", "Gators"),
		PlayerData("Janko", "Barton", "Sharks"),
		PlayerData("Wanda", "Vakulskas", "Sharks"),
		PlayerData("Jill", "Moloney", "Gators"),
		PlayerData("Luuk", "Watkins", "Gators")
	};

	vector<PlayerData> footballPlayers = {
		PlayerData("Hanzla", "Radosti", "32ers"),
		PlayerData("Tina", "Watkins", "Barleycorns"),
		PlayerData("Alex", "Patel", "32ers"),
		PlayerData("Jill", "Huang", "Barleycorns"),
		PlayerData("Wanda", "Vakulskas", "Barleycorns")
	};

	vector<string> commonPlayers = findPlayersInBothSports(basketballPlayers, footballPlayers);
	cout << "Task 1:" << endl << "These players play both sports:" << endl;
	for (string name : commonPlayers)
	{
		cout << name << endl;
	}
	cout << endl;
}


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

void task2()
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

// Task 3 (DONE)
int findGreatestProfitTransaction(vector<int> prices)
{
	// Time Complexity MUST be O(N)

	// For this function, we'll want to keep track of the best day to buy, and the best day to sell.
	// The general algorithm is as follows:
	// - Start on the first day. 
	// - Check the profit for this day compared to the price of purchase. If the profit of this transaction is greater than what was previously saved, then save it as 'maxProfit'
	// - If the next day results in a loss, we've found a better day to buy. Save this as the 'smallestPrice' 
	// (DO NOT overwrite 'maxProfit' unless the difference between this smaller number and a potentially larger number later on result in a better profit. This step just marks a 
	// day as 'might be a good day to buy?')

	// 1. Set the initial smallest price to be the first element in the array
	// 
	// 2. The initial profit should be the difference between Day 2's price and Day 1's price.
	// NOTE: There is some ambiguity here. This Task DOES NOT state whether a transaction is required with the given prices.
	// - If a transaction is REQUIRED, the initial max profit should be what Step 2 previously mentioned
	// - If a transaction is NOT REQUIRED, the initial max profit should be 0, since no moves are made.

	// 3. Let's use a for-loop here, starting at the 3rd position.
	// Since we've already got the transaction amount from our initial interaction, we really just have to check if this moves results in a loss/gain. If it is a loss, then
	// the new smallestPrice is the 2nd element. We'll also check if this is a new smallest price, and update our know smallest price as so.
	// NOTE: If a transaction is NOT REQUIRED, then we'll start at the 2nd position, comparing the original smallest price (the first element) to the 2nd, and seeing if this is a loss/gain.

	// Inside the for-loop, we'll check the difference of today's price with the potentially invested price. If profit is found, then let's save this profit.
	// If profit is not found, then we've found a better day to invest. Let's save this day as 'smallestPrice'
	// This repeats until we've traversed the whole array.

	// 4. At the end, we return the maxProfit found.
	// - If a transaction is REQUIRED, then it's possible the value returned could be negative if the prices given constantly decline
	// - If a transaction is NOT REQUIRED, then it's possible the value returned could be 0, since we'd only want to make moves that result in making money.

	// Since we are only traversing the array once, this gives a time complexity of O(N).

	// If the array is empty, just return 0.
	if (prices.empty())
	{
		return 0; // Nothing to analyze
	}
	if (prices.size() < 2) // Does the array contain just one element?
	{
		return 0; // Return 0. No profit can be made with only one price
	}
	// Find smallest
	int smallestPrice = prices[0]; // Assume the smallest is the first element
	int maxProfit = prices[1] - smallestPrice; // Assume the best profit for now is the second - first prices.
	if (maxProfit < 0) // Is this negative?
	{
		smallestPrice = prices[1]; // There is a better day to buy. If the maxProfit originally comes out to be negative, then this implies there is a better day to buy
	}
	if (prices.size() == 2) // Are there more possible transactions?
	{
		return maxProfit; // Only two days of prices given. This is our best profit.
	}
	for (int i = 2; i < prices.size(); i++) // Start at the third element.
	{
		int profit = prices[i] - smallestPrice; // What's the current profit?
		if (profit > maxProfit) // Is this better than what we have?
		{
			maxProfit = profit; // This is a better profit compared to previous data. Save it
		}
		if (profit < 0) // Check if this is a smaller price than the previously saved one (is the profit negative?)
		{
			smallestPrice = prices[i];
		}
	}

	return maxProfit;
}

void task3()
{
	vector<int> prices = { 10, 7, 5, 8, 11, 2, 6 };

	int maxProfit = findGreatestProfitTransaction(prices);
	cout << "Task 3:" << endl;
	cout << "The max profit here is: " << maxProfit << endl << endl;
}

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

void task4()
{
	vector<int> arr = { 5, -10, -6, 9, 4 };

	int largestProduct = findGreatestProduct(arr);
	cout << "Task 4:" << endl;
	cout << "The largest product from the given array is: " << largestProduct << endl << endl;
}

// Task 5
vector<double> sortFromSmallestToGreatest(vector<double> temperatures)
{
	// Time Complexity MUST be O(N)

	// NOTE: We are limited to the tenths place, with the range being [97, 99].
	// This means there are 21 possible numbers we could receive.
	// Removing one of these rules would make the O(N) time complexity IMPOSSIBLE
	// - Removing the [97, 99] bound means could get a number with any possible place value for a digit before the tenths place. This is impossible to sort in O(N) time.
	// - Removing the tenths place restriction means any number can appear in the decimal place (0.1, 0.11, 0.24252, etc.). This is impossible to sort in O(N) time.

	// Smallest Value: 97
	// Largest Value: 99

	// Steps for O(N) time complexity:

	// 1. We need to determine if the max and min in the given array are 97 and 99. 
	// - If we are within the bounds, then we can use the O(N) algorithm.
	// - If we are NOT within the bounds, then we resort to the O(N Log(N)) sorting.
	// We also need to determine if the data given only goes to the tenths place.
	// - If there are no variables that go beyond the tenths place, then we are clear to use the O(N) algorithm.
	// - If there are variables that go beyond the tenths place, then we CANNOT use the O(N) algorithm.

	// Every step after the first is if we are within the bounds of [97, 99]
	// 2. We need to count how many times each of the 21 possible values appears in the given array. The time complexity for this step is O(N).
	// In order to get counts, we'll need an array that can store 21 variables. The index for a value will be determined as follows:
	// - Multiply the value by 10 to remove any decimal places.
	// - Get the remainder between this number and 97 (modulo). This is the index in the counter array.
	// - Add 1 to the counter for the appropriate variable
	
	// 3. Loop through the array that keeps count of how many of each variable there are, and reconstruct the variables
	// 
	// LOOPING:
	// 
	// RECALL: There are only 21 POSSIBLE values at this point!
	// What does this mean?:
	// This means that the step count is N+21, giving a time complexity of O(N), where:
	// - N is the given array size.
	// CLARIFICATION: Why this is NOT 21N steps:
	// - This step is NOT 21N steps because even though we have nested loops, the inner loop's TOTAL ITERATION COUNT across all outer loop iterations add up to N.
	// We ARE NOT processing N elements for M steps!
	// We are processing N elements ACROSS M steps!
	// It costs 1 step to check each bucket, and across each bucket, there will be N steps. This give N+21 steps, which gives a time complexity of O(N)
	//
	// RECONSTRUCTION:
	// 
	// Reconstructing is simple, so here's how it's done:
	// - Multiply the outer loop iteration count by 0.1. This gives the additional amount to add to 97 (the min)
	// Ex: If i = 13, then we will add 1.3 to 97 for this value that i represents, which is 98.3
	// Add this variable to 97, and add it to the array that will be returned.
	
	// Use bool to determine if we CANNOT use the O(N) sorting algorithm
	int min = 97;
	int max = 99;
	bool flag = false;
	for (double temp : temperatures)
	{
		int floorVal = floor(temp * 10); // Multiply by 10 and floor

		// Determine if the floored value and temperature value * 10 are the same.
		// - If they are the same, then there are no more decimal place values
		// - If they are NOT the same, then there are decimal place values beyond the tenths place. 
		// Since we know that any variable having a decimal place beyond the tenths breaks the O(N)
		// sorting algorithm, set the bool variable to true and break out of the loop

		// Also check if the temp is either less than the minimum (97) or greater than the max (99)
		if ((floorVal != (temp * 10)) || (temp < min) || (temp > max))
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		// Use O(N Log(N)) sorting. We CANNOT sort this dataset in O(N) time
		vector<double> sorted = temperatures;

		// Use C++'s sort function to sort the array
		sort(sorted.begin(), sorted.end());
		return sorted;
	}

	int counts[21] = {};
	vector<double> sorted;
	for (double temp : temperatures)
	{
		int tempValue = temp * 10;
		int index = tempValue % 97; // Get the index of where to count this number
		counts[index]++;
	}
	for (int i = 0; i < 21; i++)
	{
		int countVal = counts[i];
		for (int j = 0; j < countVal; j++)
		{
			double additional = i * 0.1;
			double value = 97 + additional; // Rebuild the value
			sorted.push_back(value);
		}
	}

	return sorted;
}

void task5()
{
	// Decimal point NEVER goes beond the tenth's place, and values are between [97, 99]
	vector<double> temperatures = { 98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1 };

	vector<double> sorted = sortFromSmallestToGreatest(temperatures);

	cout << "Task 5:" << endl;
	for (double temp : sorted)
	{
		cout << temp << ", " << endl;
	}
	cout << endl;
}

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

void task6()
{
	cout << "Task 6:" << endl;
	vector<int> ex1 = { 10, 5, 12, 3, 55, 30, 4, 11, 2 };
	vector<int> ex2 = { 19, 13, 15, 12, 18, 14, 17, 11 };

	int longestStreak1 = findLongestStreak(ex1);
	int longestStreak2 = findLongestStreak(ex2);

	cout << "The longest streak for array 1 is: " << longestStreak1 << endl;
	cout << "The longest streak for array 2 is: " << longestStreak2 << endl;
}

int main()
{
	task1();
	task2();
	task3();
	task4();
	task5();
	task6();
}

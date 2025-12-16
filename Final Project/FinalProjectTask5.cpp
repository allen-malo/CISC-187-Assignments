
#include <iostream>
#include <vector>

using namespace std;

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
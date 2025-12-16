
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

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

int main()
{
	vector<int> prices = { 10, 7, 5, 8, 11, 2, 6 };

	int maxProfit = findGreatestProfitTransaction(prices);
	cout << "Task 3:" << endl;
	cout << "The max profit here is: " << maxProfit << endl << endl;
}
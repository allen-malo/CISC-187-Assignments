
**1. You're working on software that analyzes sports players. Following are two arrays of players of different sports:**
```
basketball_players = [
      {first_name: "Jill", last_name: "Huang", team: "Gators"},
      {first_name: "Janko", last_name: "Barton", team: "Sharks"},
      {first_name: "Wanda", last_name: "Vakulskas", team: "Sharks"},
      {first_name: "Jill", last_name: "Moloney", team: "Gators"},
      {first_name: "Luuk", last_name: "Watkins", team: "Gators"}
]

football_players = [
      {first_name: "Hanzla", last_name: "Radosti", team: "32ers"},
      {first_name: "Tina", last_name: "Watkins", team: "Barleycorns"},
      {first_name: "Alex", last_name: "Patel", team: "32ers"},
      {first_name: "Jill", last_name: "Huang", team: "Barleycorns"},
      {first_name: "Wanda", last_name: "Vakulskas", team: "Barleycorns"}
]
```
**If you look carefully, you'll see that some players participate in more than one sport. Jill Huang and Wanda Vakulskas play both basketball and football. You are to write a function that accepts two arrays of players and returns an array of the players who play in both sports. In this case, that would be:**
```
["Jill Huang", "Wanda Vakulskas"]
```
**While there are players who share first names and players who share last names, we can assume there's only one person who has a particular full name (meaning first and last name). We can use a nested-loops approach, comparing each player from one array against each player from the other, but this would have a runtime of O(N * M). Your job is to optimize the function so that it can run in just O(N + M).**

For this algorithm, Let's first check if either one of the arrays is empty. If this is true, then that means no player plays both sports, so we just return an empty array. If not, we will take one of the given arrays of player data, and put it into an unordered set, where the keys are a player's first and last name combined into one string (Unordered sets have O(1) lookup time). Creating this set requires N steps, giving a time complexity of O(N) (N is the array size for sport 1).

Next, we'll create an array for storing the player names present in both sports. After, we'll iterate through the second array, where at each step, we'll create a key in the same format previously mentioned (first and last name) and check if the unordered set contains that name. If the unordered set contains the name, then we'll add the name to the array of common players. This step will take M steps, giving a time complexity of O(M) (M is the array size for sport 2).

In total, this gives us a time complexity of O(N + M), where N is the array size for sport 1, and M is the array size for sport 2.

**2. You're writing a function that accepts an array of distinct integers from 0, 1, 2, 3,... up to N. However, the array will be missing one integer, and your function is to return the missing one. For example, this array has all the integers from 0 to 6, but is missing the 4:**
```
[2, 3, 0, 6, 1, 5]
```
**The next example has all the integers from 0 to 9, but is missing the 1:**
```
[8, 2, 3, 9, 4, 7, 5, 0, 6]
```
**In this case, the function should return 1.
Using a nested-loops approach would take up to O(N<sup>2</sup>). Your job is to optimize the code so that it has a runtime of O(N).**

For this algorithm, if the array is empty, we'll return -1. Othwerwise, we can use an unordered set to save the integers from the array as keys. We'll also save the highest number in the array, since this is N. Doing this would take N steps, giving a time complexity of O(N).

Once we get the highest integer in the array, we'll use that to know that we need every integer from 0-N. Since the integers from the array are now keys in the set, we'll loop through every integer from 0-N. IF a key DOES NOT exist for an integer between 0 and N, then that means we've found the missing number, so we can return that number to end the function. In total this step gives a time complexity of O(N), since we loop through each integer up to N once. If there are no missing integers, we'll return -1.

In total, this gives a time complexity of O(N).

**3. You're working on some more stock-prediction software. The function you're writing accepts an array of predicted prices for a particular stock over the course of time. For example this array of seven prices:**
```
[10, 7, 5, 8, 11, 2, 6]
```
**predicts that a given stock will have these prices over the next seven days. (On Day 1, the stock will close at $10; on Day 2, the stock will close at $7, and so on.) Your function should calculate the greatest profit that could be made from a single "buy" transaction followed by a single "sell" transaction. In the previous example, the most money could be made if we bought the stock when it was worth $5 and sold it when it was worth $11. This yields a profit of $6 per share. Note that we could make even more money if we buy and sell multiple times, but for now, this function focuses on the most profit that could be made from just one purchase followed by one sale. Now, we could use nested loops to find the profit of every possible buy and sell combination. However, this would be O(N<sup>2</sup>) and too slow for our hotshot trading platform.

Your job is to optimize the code so that the function clocks in at just O(N)**

Since this algorithm must have a time complexity of O(N), we'll want to keep track of the best day to buy, and the best day to sell. First, we'll check if the array is empty. If the array is empty, then we'll return 0. We'll also check if the array contains only one element. If this is true, then we'll return 0.

The first step will be to create variables that store the first price to be the initial smallest price, and a variable that stores the initial max profit to be the difference between the second price and the first price (initial smallest). If the difference between the prices is negative, then that means there is a better day to buy (the second day), so we'll overwrite the smallest price to be the price on day 2. After, we'll check if there are more than 2 elements in the array. If there aren't, then we're done, and return the only move found.

HOWEVER, there is some slight ambiguity here. The Task NEVER states whether a transaction MUST take place! If a transaction must take place, then the initial max profit will be the difference between the second and first prices. If a transaction is not required, such as if we gave an array of prices that constantly decrease, then the initial profit should be the maximum between 0 and the difference between the second and first prices.

If there are more than 2 elements, then we'll use a for-loop to loop through the array, starting at the third index. We'll get the profit for selling on that day by using the difference between the current day price and the smallest price found. If this day gives a profit greater than the previous greatest profit, then we'll update the max profit to reflect this. Otherwise, we'll check to see if the profit for this transaction is negative. If this is true, then we've found a potentially better day to invest. This step would give a time complexity of O(N), since we are iterating through the entire array once.

After iterating through the array is complete, we return the max profit found.


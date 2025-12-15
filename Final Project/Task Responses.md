
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

Before we dive into this problem, there is a condition that we must make clear: there is ALWAYS a missing number! This means that no array is EVER considered "complete".

For example, let's compare the following arrays:
```
arr1 = [1, 2, 3, 4];
arr2 = [0, 1, 2, 3, 4];
```
At first glance, ```arr2``` might look "complete" by definition in comparison to ```arr1```. However, the Task states that there is ALWAYS a missing number, and does not include to check for the validity of something being missing. As a result, this function should return 0 for ```arr1``` and 5 for ```arr2```.

For this algorithm, if the array is empty, we'll return -1. Othwerwise, we can use an unordered set to save the integers from the array as keys. We'll also save the highest number in the array, since this is N. Doing this would take N steps, giving a time complexity of O(N).

Once we get the highest integer in the array, we'll use that to know that we need every integer from 0-N. Since the integers from the array are now keys in the set, we'll loop through every integer from 0-N. IF a key DOES NOT exist for an integer between 0 and N, then that means we've found the missing number, so we can return that number to end the function. In total this step gives a time complexity of O(N), since we loop through each integer up to N once. If there are no missing integers between 0 and the max value found, we'll return the max value + 1, since this has to be the missing number.

In total, this gives a time complexity of O(N).

There is an alternate way that can also give the same result. Instead of using an unordered set, we can get the expected sum of the numbers from 0-N (N is the array size), and compare it to the actual sum of numbers from the given array. The difference between the expected sum and actual sum is the missing number.

**3. You're working on some more stock-prediction software. The function you're writing accepts an array of predicted prices for a particular stock over the course of time. For example this array of seven prices:**
```
[10, 7, 5, 8, 11, 2, 6]
```
**predicts that a given stock will have these prices over the next seven days. (On Day 1, the stock will close at $10; on Day 2, the stock will close at $7, and so on.) Your function should calculate the greatest profit that could be made from a single "buy" transaction followed by a single "sell" transaction. In the previous example, the most money could be made if we bought the stock when it was worth $5 and sold it when it was worth $11. This yields a profit of $6 per share. Note that we could make even more money if we buy and sell multiple times, but for now, this function focuses on the most profit that could be made from just one purchase followed by one sale. Now, we could use nested loops to find the profit of every possible buy and sell combination. However, this would be O(N<sup>2</sup>) and too slow for our hotshot trading platform.**

**Your job is to optimize the code so that the function clocks in at just O(N)**

Since this algorithm must have a time complexity of O(N), we'll want to keep track of the best day to buy, and the best day to sell. First, we'll check if the array is empty. If the array is empty, then we'll return 0. We'll also check if the array contains only one element. If this is true, then we'll return 0.

The first step will be to create variables that store the first price to be the initial smallest price, and a variable that stores the initial max profit to be the difference between the second price and the first price (initial smallest). If the difference between the prices is negative, then that means there is a better day to buy (the second day), so we'll overwrite the smallest price to be the price on day 2. After, we'll check if there are more than 2 elements in the array. If there aren't, then we're done, and return the only move found.

HOWEVER, there is some slight ambiguity here. The Task NEVER states whether a transaction MUST take place! If a transaction must take place, then the initial max profit will be the difference between the second and first prices. If a transaction is not required, such as if we gave an array of prices that constantly decrease, then the initial profit should be the maximum between 0 and the difference between the second and first prices.

If there are more than 2 elements, then we'll use a for-loop to loop through the array, starting at the third index. We'll get the profit for selling on that day by using the difference between the current day price and the smallest price found. If this day gives a profit greater than the previous greatest profit, then we'll update the max profit to reflect this. We'll also check to see if the profit for this transaction is negative. If this is true, then we've found a potentially better day to invest, so we'll update our smallest price accordingly. This step would give a time complexity of O(N), since we are iterating through the entire array once.

After iterating through the array is complete, we return the max profit found. The total time complexity would be O(N).


**4. You're writing a function that accepts an array of numbers and computes the highest product of any two numbers in the array. At first glance, this is easy, as we can just find the two greatest numbers and multiply them. However, our array can contain negative numbers and look like this:**
```
[5, -10, -6, 9, 4]
```
**Would could use the nested loops approach to multiply every possible pair of numbers, but this would take O(N<sup>2</sup>) time. Your job is to optimize the function so that it's a speedy O(N).**

The first step is to, of course, check if the array is empty. If this is true, then we'll return 0. If the array contains only 1 element, then we'll return that one element.

Since we want a time complexity of O(N), and know that negative numbers are possible to find in a given array, we first need to find the smallest and largest values in the array. I've chosen to create structs for tracking the smallest and largest number, as well as their index in the array. We keep track of the position of the given number in the array because when we go to multiply this number by every number in the array to find the largest product, we DO NOT want to multiply this number by the number at the same position in the array (that would be itself). The reason for this check is because if we wanted to have duplicate numbers at different positions in the array, this allows us to do that. In total, this step gives a time complexity of O(N), since we loop through the array once.

After, we'll create an int variable that stores the largest product found, initializing it to be the smallest possible integer value. you could also initialize the smallest product to be 0, but keep in mind the only time you'd be getting a negative product is if there are only two elements in the array, where one is positive and the other is negative. For checking the products with the smallest and largest numbers, we'll use two different for-loops that iterate through the rest of the array, giving a time complexity of O(N) since we loop through the array twice, and constants are ignored.

The process for both iterations is the same. First, we'll check if the loop is currently on the same position as the smallest/largest element. If this is true, then we skip this iteration. Otherwise, we'll get the product between the smallest/largest value and the current value. If the product found is larger than what was previously found, then we'll save this product as the largest product. After both iterations are complete, we'll return the largest product found. This gives a time complexity of O(N), since we iterate through both arrays twice, and they are not nested.

In total the time complexity comes out to the speed O(N) that we're aiming for.


**5. You're creating software that analyzes the data of body temperature readings taken from hundreds of human patients. These readings are taken from healthy people and range from 97 degrees Fahrenheit to 99 degrees Fahrenheit. An important point: within this application, the decimal point NEVER goes beyond the tenths place. Here's a sample array of temperature readings:**
```
[98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1]
```
**You are to write a function that sorts these readings from lowest to highest. Using a classic sorting algorithm such as Quicksort would take O(NlogN). However, in this case, writing a faster sorting algorithm is possible. Yes, that's right. Evne though you've learned that the fastest sorts are O(NlogN), this case is different. Why? In this case, there are limited possibilities for the readings. In such a case, we can sort these values in O(N). It may be N multiplied by a constant, but that's still considered O(N).**

Before we go over how we can get the O(N) time complexity for sorting this data, there are a few key details we must cover that allow for this:
1. Our values are bounded by [97, 99]. If we DO NOT have this bound, we CANNOT sort in O(N) time, and can sort in O(NlogN) time at the fastest.
2. All values DO NOT go beyond the tenths place. If this is false, then we CANNOT sort in O(N) time, and must resort to O(NlogN) sorting.

Now that that's cleared up, let's go over how we can achieve a O(N) time complexity for sorting this dataset.

Since we are given that the bounds are [97, 99] and only going up to the tenths place, that means there are only 21 possible values this array could contain. We'll start by creating three variables: an int variable that represents the minimum bound (97), an int variable that represents the max (99), and a bool variable that we can call 'flag', which will track whether the criteria for the O(N) time complexity is not possible. Let's loop through all elements in the array to ensure these bounds and rules are met.

When we loop through the array to verify our data is valid, we'll first create an int that stores the current value from the array multiplied by 10 and floored, and compare it to the current value only multiplied by 10. This preserves the value from the tenths place while checking that there are no more decimal places after that. If these two value ARE NOT equal, or the current value is outside the bounds of [97, 99], we'll set our bool to true and break out of the loop since we can no longer sort in O(N) time. If this break statement is never reached, then our dataset is healthy for O(N) sorting. This step will take up to N steps (possibly less since we could break out of the loop early), giving a time complexity of O(N). If our dataset is healthy for the O(N) sorting, then we'd take N steps to verify, but this still gives a time complexity of O(N).

After looping, we'll check if our flag variable was set to true. If this is the case, then we CANNOT sortin O(N) time, and must resort to O(NlogN) sorting. For this fallback, I've chosen to go with C++'s sort algorithm, which gives a time complexity of O(NlogN). We'll then return the sorted array.

If our flag variable is false, then we can process with O(N) sorting. We'll create an array that stores 21 ints, which will keep track of the 21 possible values our array can contain, and an empty array that will store our sorted data. To get the counts for each of the 21 variables, we'll have to loop through the array again, and the index for where to store the count for said variable will be determined as follows:
- Multiply the value by 10
- Get the remaineder when this value is divded by 97 (our min).
The remainder will be the index of the given variable, which is where we'll keep count of that variable. This is comparable to a bucket sort, but specialized for this purpose. We loop through the given array once, giving a time complexity of O(N).

Now, we can finally sort the array, and we'll iterate through every index in the array that contains the count of the 21 possible numbers. We'll have an outer loop that loops through each index of the array that keeps count of each variable, and an inner loop that adds those values to the array. Values will be reconstructed as follows:
- The original value to insert in the array will be assumed to be 97.
- From the outer loop iterator int value, we'll divide this value by 10, giving the additional value that this part of the array that keeps the counts for each variable represents (ex: when i = 0, this is represents 97; when i = 13, this represents 98.3; etc.). We'll then insert this value into the array.
The total step count for this step is N + 21, giving a time complexity of O(N). The step count IS NOT 21*N because even though we have nested loops, the nested loop's total amount of iterations adds up to N, and we are checking across 21 buckets. That means there are 21 checks and N steps happen across all buckets, giving N + 21 steps.

In total, we'd get a time complexity of O(N).


**6. You're writing a function that acceps an array of unsorted integers and returns the length of the longest consecutive sequence among them. The sequence is formed by integers that increase by 1. For example, in the array:**
```
[10, 5, 12, 3, 55, 30, 4, 11, 2]
```
**the longest consecutive sequence is 2-3-4-5. These four integers form an increasing sequence because each integer is one greater than the previous one. While there's also a sequence of 10-11-12, it's only a sequence of three integers. In this case, the function should return 4, since that's the length of the longest consecutive sequence that can be formed from this array. One more example:**
```
[19, 13, 15, 12, 18, 14, 17, 11]
```
**this array's longest sequence is 11-12-13-14-15, so the function would return 5. Your job is to optimize the function so that it takes O(N) time.**

For this function to achieve a time complexity of O(N), we'll want to keep track of what numbers are present in the current array, as well as the current streak and longest streak of consecutive integers.

Firstly, we'll create an unordered set for tracking what integers are present in the array. This will take N steps, giving a time complexity of O(N).

Next, we'll create an int variable that tracks the longest streak, initializing it to 1.

Next, we'll iterate through every present integer in the unordered set. In order to identify our sequence, we'll check to see if the previous number is present. If the previous number is present, then that means we aren't at the beginning of the possible sequence. If the previous number is NOT present, then that means we've found the beginning of a possible sequence. We'll keep track of the current number, and create an int variable that tracks the current streak, initializing it to 1. We'll use a while-loop to determine if the next number is present in the sequence. If the next number is present, we'll increment both the current number and the current streak count. Once the streak is broken, we'll assign the longest streak variable the larger of the two values: the current longest streak, and the streak just found. After iterating through all numbers found in the array, we'll return the longest streak. In total each number gets checked AT MOST 2 times, meaning there would be 2N steps, giving a time complexity of O(N).

In total, this method gives a time complexity of O(N).

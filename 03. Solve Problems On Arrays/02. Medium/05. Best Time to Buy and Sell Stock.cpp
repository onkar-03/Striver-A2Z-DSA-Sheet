#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force
 * For each possible pair of days (i, j), where i is the buying day and j is the selling day, the algorithm checks if the selling price (arr[j]) is greater than the buying price (arr[i]).
 * If so, it calculates the profit and updates the maximum profit accordingly.
 * ----------------------------
 * Time Complexity: O(n^2)
 * - The algorithm uses two nested loops, one iterating over the buying days and the other iterating over the
 *   selling days, resulting in a time complexity of O(n^2), where n is the size of the input array.
 * ----------------------------
 * Space Complexity: O(1)
 * - The space complexity is constant because only a few variables (`maxPro`, `i`, `j`, and `n`) are used,
 *   and no additional data structures are required.
 */

class Solution
{
public:
  int maxProfit(vector<int> &arr)
  {
    int maxPro = 0;     // Variable to store the maximum profit
    int n = arr.size(); // Get the size of the array

    // Loop through every possible pair of days (i, j)
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        // If arr[j] > arr[i], it's a potential profit scenario
        if (arr[j] > arr[i])
        {
          // Update the maximum profit if a larger profit is found
          maxPro = max(arr[j] - arr[i], maxPro);
        }
      }
    }

    // Return the maximum profit found
    return maxPro;
  }
};

/*
 * Approach-2: DP on Stocks
 * The algorithm maintains two variables:
 * 1. `minPrice` to track the minimum stock price seen so far (indicating the best time to buy).
 * 2. `maxPro` to track the maximum profit, which is updated as we find a better selling price (i.e., higher than the previous minimum price).
 * At each step, it computes the potential profit (current price - `minPrice`) and updates the `maxPro` if the current profit is higher.
 * ----------------------------
 * Time Complexity: O(n)
 * - The algorithm traverses the array once, so the time complexity is linear, O(n), where n is the size of the input array.
 * ----------------------------
 * Space Complexity: O(1)
 * - The space complexity is constant because the algorithm uses only a few variables (`maxPro`, `minPrice`, and `i`), and no additional data structures are required.
 */

class Solution
{
public:
  int maxProfit(vector<int> &arr)
  {
    int maxPro = 0;         // Variable to store the maximum profit
    int minPrice = INT_MAX; // Initialize the minimum price to the highest possible value

    // Loop through the array to find the minimum price and maximum profit
    for (int i = 0; i < arr.size(); i++)
    {
      // Update the minimum price to the lowest price encountered so far
      minPrice = min(minPrice, arr[i]);

      // Calculate the potential profit for the current price and update maxPro if higher
      maxPro = max(maxPro, arr[i] - minPrice);
    }

    // Return the maximum profit found
    return maxPro;
  }
};
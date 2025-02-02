#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force - Generate All Subarrays)
 * Time Complexity: O(n^3)
 * - The outer two loops generate all subarrays of the input array.
 * - The inner loop calculates the product of each subarray, which takes O(n) time.
 * ---------------------------
 * Space Complexity: O(1)
 * - We only use a constant amount of space for variables to store results and intermediate values.
 */
class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int result = INT_MIN; // Initialize the result to the smallest integer value

    // Loop through each possible subarray
    for (int i = 0; i < nums.size() - 1; i++)
    {
      for (int j = i + 1; j < nums.size(); j++)
      {
        int prod = 1; // Variable to store the product of the current subarray

        // Calculate the product of elements in the current subarray
        for (int k = i; k <= j; k++)
        {
          prod *= nums[k];
        }

        // Update the result with the maximum product found so far
        result = max(result, prod);
      }
    }

    // Return the maximum product of any subarray
    return result;
  }
};

/*
 * Approach-2: (Prefix and Suffix Product Calculation)
 * The idea is to traverse the array once while calculating two products:
 * 1. Prefix product (`pre`): This holds the product of all elements up to the current element from the left.
 * 2. Suffix product (`suff`): This holds the product of all elements from the current element to the end from the right.
 * ---------------------------
 * Time Complexity: O(n)
 * - We iterate through the array once to calculate the prefix and suffix products.
 * - The maximum product is calculated during the same iteration.
 * ---------------------------
 * Space Complexity: O(1)
 * - Only a constant amount of extra space is used for variables to store intermediate results.
 */
class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int n = nums.size(); // Size of array

    int pre = 1, suff = 1;
    int ans = INT_MIN; // Initialize answer to the smallest possible integer

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
      // Reset pre and suff if they become zero i.e if we encounter 9 in our array then after that 0 we start fresh
      if (pre == 0)
        pre = 1;
      if (suff == 0)
        suff = 1;

      // Calculate the prefix product and suffix product
      pre *= nums[i];
      suff *= nums[n - i - 1];

      // Update the maximum product found so far
      ans = max(ans, max(pre, suff));
    }

    // Return the maximum product found
    return ans;
  }
};

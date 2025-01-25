#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force Simple Iteration
 * ----------------------------
 * T.C: O(n^2)
 * - Outer loop (i): Iterates through the array -> O(n)
 * - Inner loop (j): Iterates from i to n -> O(n)
 * - Total: O(n * n) = O(n^2)
 * ----------------------------
 * S.C: O(1)
 * - Constant space is used for variables `maxi` and `sum`.
 */

class Solution
{
public:
  int maxSubarraySum(vector<int> &arr)
  {
    int n = arr.size();
    int maxi = INT_MIN; // Initialize the maximum sum to the smallest possible integer

    // Outer loop to select the starting index of the subarray
    for (int i = 0; i < n; i++)
    {
      int sum = 0; // Initialize the sum for the current subarray

      // Inner loop to select the ending index of the subarray
      for (int j = i; j < n; j++)
      {
        // Add the current element arr[j] to the sum
        sum += arr[j];

        // Update the maximum sum if the current subarray sum is larger
        maxi = max(maxi, sum);
      }
    }

    return maxi; // Return the maximum subarray sum
  }
};

/*
 * Approach-2: Kandan's Algorithm
 * This code implements Kadane's Algorithm to find the maximum subarray sum in an array.
 * It iterates through the array, maintaining the sum of the current subarray. If the sum becomes negative, it resets the sum to 0, effectively discarding the negative subarrays. The global maximum sum is update whenever the current sum is larger.
 * ----------------------------
 * T.C: O(n)
 * - The algorithm iterates through the array once, so the time complexity is O(n), where n is the size of the array.
 * ----------------------------
 * S.C: O(1)
 * - Constant space is used as no additional data structures are utilized.
 */

class Solution
{
public:
  long long maxSubarraySum(vector<int> &arr)
  {
    long long maxi = LONG_MIN; // Initialize the maximum sum to the smallest possible value
    long long sum = 0;         // Initialize the sum of the current subarray

    // Iterate through the array to calculate the sum of subarrays
    for (int i = 0; i < arr.size(); i++)
    {
      sum += arr[i]; // Add the current element to the sum

      // Update the global maximum sum if the current sum is larger
      maxi = max(maxi, sum);

      // If the sum becomes negative, reset it to 0
      if (sum < 0)
      {
        sum = 0;
      }
    }

    // Return the maximum subarray sum
    return maxi;
  }
};

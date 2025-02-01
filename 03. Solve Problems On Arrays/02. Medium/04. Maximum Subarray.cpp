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
  int maxSubarraySum(vector<int> &nums)
  {
    int n = nums.size();
    int maxi = INT_MIN; // Initialize the maximum sum to the smallest possible integer

    // Outer loop to select the starting index of the subarray
    for (int i = 0; i < n; i++)
    {
      int sum = 0; // Initialize the sum for the current subarray

      // Inner loop to select the ending index of the subarray
      for (int j = i; j < n; j++)
      {
        // Add the current element arr[j] to the sum
        sum += nums[j];

        // Update the maximum sum if the current subarray sum is larger
        maxi = max(maxi, sum);
      }
    }

    return maxi; // Return the maximum subarray sum
  }
};

/*
 * Approach-2: Kandan's Algorithm
 * This code implements Kadane's Algorithm to find the maximum subarray sum in an array. * It iterates through the array, maintaining the sum of the current subarray.
 * If the sum becomes negative, it resets the sum to 0, effectively discarding the negative subarrays as max Sum won't be a negetive value + something as it would decrease the overall value of the sum
 * The global  maximum sum is update whenever the current sum is larger.
 * ----------------------------
 * T.C: O(n)
 * - The algorithm iterates through the array once, so the time
 * complexity is O(n), where n is the size of the array.
 * ----------------------------
 * S.C: O(1)
 * - Constant space is used as no additional data structures are
 * utilized.
 */

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    // Initialize the maximum sum to the smallest
    // possible value
    long long maxi = LONG_MIN;

    // Initialize the sum of the current subarray
    long long sum = 0;

    // Iterate through the array to calculate the sum of subarrays
    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i]; // Add the current element to the sum

      // Update the global maximum sum if the current sum is larger
      maxi = max(maxi, sum);

      // If the sum becomes negative, reset it to 0
      // This is becasuse we want to maximize the Sum of Subarrays and a Negetive value will eventually decrease the Sum of the Subarray hence we make the Sum as Zero again and start fresh
      if (sum < 0)
      {
        sum = 0;
      }
    }

    // Return the maximum subarray sum
    return maxi;
  }
};

///////////////////////////////////////////////////////////////////////////////
// --- FOLLOW UP QUESTION --- (Return the Subaray as well)
/*
 * Approach-3: Kadane's Algorithm with Subarray Tracking
 * This code implements Kadane's Algorithm to find the maximum subarray sum, with an additional feature of tracking the subarray itself.
 * It maintains the current sum of the subarray, and if the sum becomes negative, it resets the sum to 0. The start and end indices of the subarray are updated whenever the maximum sum is found.
 * ----------------------------
 * T.C: O(n)
 * - The algorithm iterates through the array once, so the time complexity is O(n), where n is the size of the array.
 * ----------------------------
 * S.C: O(1)
 * - Constant space is used for variables `maxi`, `sum`, `start`, `ansStart`, and `ansEnd`.
 */

class Solution
{
public:
  long long maxSubarraySum(vector<int> &arr)
  {
    // Initializing variables:
    long long maxi = LONG_MIN; // Stores the maximum sum found so far
    long long sum = 0;         // Stores the current sum of the subarray being processed

    // Variables to track the start and end indices of the maximum subarray:
    int start = 0;                  // The starting index of the current subarray
    int ansStart = -1, ansEnd = -1; // The starting and ending indices of the subarray with the maximum sum

    // Traverse through each element of the array:
    for (int i = 0; i < arr.size(); i++)
    {
      // If sum becomes 0, this means we are starting a new subarray from index i:
      if (sum == 0)
      {
        start = i; // Update the starting index of the current subarray
      }

      sum += arr[i]; // Add the current element to the sum of the subarray

      // If the current sum is greater than the previously found maximum sum, update the maximum sum
      // and store the start and end indices of this subarray:
      if (sum > maxi)
      {
        maxi = sum;       // Update the maximum sum
        ansStart = start; // Update the start index of the subarray
        ansEnd = i;       // Update the end index of the subarray
      }

      // If the sum becomes negative, reset it to 0 as starting a new subarray is better
      if (sum < 0)
      {
        sum = 0;
      }
    }

    // Printing the subarray with the maximum sum:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
      cout << arr[i] << " "; // Print each element of the subarray
    }
    cout << "]\n"; // End the subarray output

    return maxi; // Return the maximum sum found
  }
};
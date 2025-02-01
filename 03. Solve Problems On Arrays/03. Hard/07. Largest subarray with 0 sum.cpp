#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force
 * - We use two nested loops to generate all possible subarrays.
 * - The outer loop selects the starting index.
 * - The inner loop iterates over the end indices and calculates the sum.
 * - If we find a subarray with sum 0, we update the maximum length.
 * --------------------
 * T.C: O(N^2) -> Two nested loops to check all subarrays.
 * --------------------
 * S.C: O(1) -> No extra space used apart from variables.
 */

class Solution
{
public:
  int maxLen(vector<int> &arr)
  {
    // Get the size of the array
    int n = arr.size();

    // Stores maximum length of subarray with sum 0
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
      int sum = 0; // Initialize sum for current subarray

      for (int j = i; j < n; j++)
      {
        sum += arr[j]; // Compute sum from index i to j

        if (sum == 0)
        {                              // Check if sum is 0
          maxi = max(maxi, j - i + 1); // Update maximum length
        }
      }
    }

    return maxi; // Return maximum length of subarray with sum 0
  }
};

/*
 * Approach-2: Optimal Using HashMap
 * - We use a hash map to store the first occurrence index of a prefix sum.
 * - As we traverse the array, we maintain a running sum.
 * - If the sum becomes 0 at any index, it means the subarray from the start to this index has a sum of 0.
 * - If the sum has been seen before, the subarray between the previous occurrence and the current index also has a sum of 0.
 * - We update the maximum length accordingly.
 *
 * T.C: O(N) -> We traverse the array once, and each lookup in the unordered_map takes O(1).
 * S.C: O(N) -> In the worst case, we store all prefix sums in the unordered_map.
 * --------------------
 */

class Solution
{

public:
  int maxLen(vector<int> &arr)
  {

    // Stores first occurrence of each prefix sum
    unordered_map<int, int> mpp;

    // Size of Array
    int n = arr.size();

    // Stores maximum length of subarray with sum 0
    int maxi = 0;

    // Running sum
    int sum = 0;

    // Iterate over all the Array Elements
    for (int i = 0; i < n; i++)
    {
      // Update running sum
      sum += arr[i];

      if (sum == 0)
      {
        // If sum is 0, update maximum length
        maxi = i + 1;
      }
      else
      {
        // If sum was seen before
        if (mpp.find(sum) != mpp.end())
        {
          // Update max length
          maxi = max(maxi, i - mpp[sum]);
        }
        else
        {
          // Store first occurrence of this sum
          mpp[sum] = i;
        }
      }
    }

    // Return maximum length of subarray with sum 0
    return maxi;
  }
};
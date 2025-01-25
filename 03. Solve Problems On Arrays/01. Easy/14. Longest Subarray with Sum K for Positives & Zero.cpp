#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Brute Force (Using nested loops to calculate subarray sums)
 * ---------------------------
 * - The idea is to consider every possible subarray by using two nested loops.
 * - The outer loop represents the starting index of the subarray, and the inner loop calculates the sum of elements from that index onward.
 * - If the sum equals `k`, we return the length of that subarray.
 *
 * T.C: O(n^2)
 * - We use two nested loops to calculate the sum for all subarrays, resulting in a time complexity of O(n^2).
 * - Constants: Each sum calculation is done by summing the elements of the subarray.
 *
 * S.C: O(1)
 * - Only a few extra variables are used for sum and indices, so the space complexity is constant.
 * ----------------------------
 */
class Solution
{
public:
  int longestSubarray(vector<int> &arr, int k)
  {
    int n = arr.size();
    int sum = 0;

    // Iterate through all possible subarrays
    for (int i = 0; i < n; i++)
    {
      // Reset sum for each new subarray starting at index i
      sum = 0;

      for (int j = i; j < n; j++)
      {
        sum += arr[j]; // Add the element to the current subarray sum

        // If the sum matches k, return the length of the subarray
        if (sum == k)
        {
          return (j - i + 1);
        }
      }
    }

    return -1; // In case no valid subarray is found
  }
};

/*
 * Approach: Using Prefix Sum & Hash Map
 * ---------------------------
 * - We maintain a running sum of the array elements.
 * - For each element, we calculate the prefix sum and check if the sum equals k.
 * - We also check if the sum minus k (remaining sum) exists in the map, meaning there’s a subarray with sum k.
 * - The length of such subarrays is calculated and the maximum length is updated.
 * ----------------------------
 * T.C: O(n)
 * - We iterate through the array once and perform constant time operations for each element (lookup and insert in map).
 * - Constants: The operations in the map are O(log n) for each insertion and lookup, so the overall complexity is O(n log n).
 * ----------------------------
 * S.C: O(n)
 * - The space complexity comes from the hash map storing the prefix sums.
 * ----------------------------
 */
class Solution
{
public:
  int longestSubarray(vector<int> &arr, int k)
  {
    int n = arr.size(); // Size of the input array

    // Map to store the prefix sum and its corresponding index
    map<long long, int> preSumMap;

    // Running sum of the array elements
    long long sum = 0;

    // Variable to track the maximum length of subarray with sum k
    int maxLen = 0;

    // Iterate through the array to process each element
    for (int i = 0; i < n; i++)
    {
      // Add the current element to the running sum
      sum += arr[i];

      // If the current sum equals k, it means the subarray from index 0 to i has a sum of k
      if (sum == k)
      {
        // Update the max length with the subarray ending at index i
        maxLen = max(maxLen, i + 1);
      }

      long long rem = sum - k; // Calculate the remaining sum (sum - k)

      // If rem exists in the map, it means there is a subarray from the index after the stored index to i that has a sum equal to k
      if (preSumMap.find(rem) != preSumMap.end())
      {
        int len = i - preSumMap[rem]; // Length of the subarray with sum k
        maxLen = max(maxLen, len);    // Update the max length
      }

      // Update the map to store the current sum and its index, but only if the sum is not already in the map
      // This ensures we are storing the first occurrence of each sum, which gives the longest subarray
      // This way we tackle the zero value addition case as well
      if (preSumMap.find(sum) == preSumMap.end())
      {
        preSumMap[sum] = i; // Store the sum and the index
      }
    }

    return maxLen; // Return the maximum length of subarray with sum k
  }
};

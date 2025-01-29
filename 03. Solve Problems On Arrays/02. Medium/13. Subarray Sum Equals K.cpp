#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-2: Optimal using Prefix Sum
 * To find the number of subarrays with a given sum, we use a brute-force approach.
 * We check each possible subarray (starting from every index) and compute its sum.
 * If the sum matches `k`, we increase the count.
 * We loop through all possible subarrays and maintain a counter for those whose sum equals `k`.
 *
 * T.C: O(n^2)
 * - We have two nested loops: one for the starting index and another for the ending index of each subarray.
 *
 * S.C: O(1)
 * - We use only a few integer variables to store the sum and count, so the space complexity is O(1).
 *
 * ----------------------------
 */
class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    // Size of the given array
    int n = nums.size();

    // Count of subarrays whose sum equals k
    int cnt = 0;

    // Loop through each starting index
    for (int i = 0; i < n; i++)
    {
      // Initial Sum as 0
      int sum = 0;
      {
        // Loop through each ending index for the subarray
        for (int j = i; j < n; j++)
          // Add element at index j to the sum of the subarray
          sum += nums[j];
        {
          // Check if the sum equals the target sum k
          if (sum == k)
            // If yes, increase the count of valid subarrays
            cnt++;
        }
      }
    }

    return cnt; // Return the count of subarrays with sum equal to k
  }
};

/*
 * Approach-2: Optimal Search usign Hash Map
 * We calculate the prefix sum as we traverse the array. For each element, we calculate the difference between
 * the current prefix sum and the target sum `k`. If this difference has been encountered before (exists in the map),
 * it means there exists a subarray whose sum is equal to `k`. We increment the count accordingly.
 * We also store the current prefix sum in the map to keep track of how many times each sum has occurred.
 *
 * T.C: O(n)
 * - We only traverse the array once, and each lookup and update in the map is O(1) on average, so the time complexity is O(n).
 *
 * S.C: O(n)
 * - In the worst case, the map will store the prefix sum for every element, leading to a space complexity of O(n).
 *
 * ----------------------------
 */

class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    // Size of the given array
    int n = nums.size();

    // Map to store the frequency of prefix sums
    map<int, int> mpp;
    int preSum = 0, cnt = 0;

    // Initialize the map with prefix sum 0 occurring once (needed for subarrays starting at index 0)
    mpp[0] = 1;

    for (int i = 0; i < n; i++)
    {
      // Add current element to the prefix sum
      preSum += nums[i];

      // Calculate the required previous prefix sum (preSum - k)
      int remove = preSum - k;

      // Check if the required prefix sum (preSum - k) exists in the map
      // If found, it means there is a subarray that sums up to k
      if (mpp.find(remove) != mpp.end())
      {
        // Increment the count by the number of times remove has occurred
        cnt += mpp[remove];
      }

      // Store the current prefix sum in the map
      mpp[preSum] += 1;
    }

    return cnt; // Return the total count of subarrays with sum equal to k
  }
};

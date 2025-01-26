#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force
 * ----------------------------
 * Time Complexity: O(n)
 * - We iterate over the input array twice (once to segregate and once to rearrange), resulting in O(n) time complexity, where n is the size of the array.
 * ----------------------------
 * Space Complexity: O(n)
 * - We use two extra vectors (positive and negative), each of size O(n/2), so the space complexity is O(n).
 * 
 */

class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    // Define 2 vectors, one for storing positive
    // and the other for negative elements of the array.
    vector<int> pos;
    vector<int> neg;

    // Segregate the array into positives and negatives.
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > 0)
        pos.push_back(nums[i]);
      else
        neg.push_back(nums[i]);
    }

    // By Observation we know: Positives on even indices, negatives on odd indices
    // Hence we update the nums array with positive and negetive alternate values
    for (int i = 0; i < nums.size() / 2; i++)
    {
      // Place positive numbers at even indices
      nums[2 * i] = pos[i];

      // Place negative numbers at odd indices
      nums[2 * i + 1] = neg[i];
    }

    // Return the rearranged array.
    return nums;
  }
};

#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Normal Brute Force
 * - Traverse the array and compare each pair of adjacent elements.
 * - If for any `i`, `nums[i] > nums[i + 1]`, the array is not sorted, so return false.
 * - If the loop completes without finding any such pair, the array is sorted, so return true.
 * ----------------------------
 * Time Complexity (T.C.): O(n), where n is the size of the array.
 * - The array is traversed once, making it linear in time.
 * ----------------------------
 * Space Complexity (S.C.): O(1)
 * - No additional space is used apart from a few variables.
 * ----------------------------
 */

class Solution
{
public:
  // Function to check if the array is sorted in non-decreasing order
  bool check(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array

    for (int i = 0; i < n - 1; i++) // Loop through the array up to the second last element
    {
      if (nums[i] > nums[i + 1]) // If the current element is greater than the next element
      {
        return false; // The array is not sorted, so return false
      }
    }

    return true; // If the loop completes, the array is sorted, so return true
  }
};

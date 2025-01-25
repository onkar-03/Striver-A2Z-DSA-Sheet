#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Brute Force
 * - Traverse the array while maintaining a `streak` counter to count the current number of consecutive 1's.
 * - Use a variable `maxi` to store the maximum streak encountered during traversal.
 * - If a 0 is encountered, reset the `streak` counter to 0.
 * - Update `maxi` in each iteration to ensure the maximum streak is recorded.
 * - Return `maxi` as the result after the loop ends.
 * ----------------------------
 * T.C: O(n)
 * - The array is traversed once, so the time complexity is linear with respect to the size of the array.
 * - Constants: Each iteration involves simple comparisons and updates.
 * ----------------------------
 * S.C: O(1)
 * - Only a constant amount of extra space is used for variables (`streak` and `maxi`).
 */
class Solution
{
public:
  int findMaxConsecutiveOnes(vector<int> &nums)
  {
    // Get the size of the array
    int n = nums.size();

    // Initialize variables to track the current streak and maximum streak
    int streak = 0;
    int maxi = 0;

    // Traverse the array to find the maximum consecutive 1's
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 1)
      {           // If the current element is 1
        streak++; // Increment the streak counter
      }
      else
      {             // If the current element is 0
        streak = 0; // Reset the streak counter
      }
      maxi = max(maxi, streak); // Update the maximum streak
    }

    // Return the maximum streak of consecutive 1's
    return maxi;
  }
};

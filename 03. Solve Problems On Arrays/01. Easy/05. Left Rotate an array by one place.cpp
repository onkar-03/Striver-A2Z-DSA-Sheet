#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Simple Traversal
 * ---------------
 * The idea for a left rotation by 1 is to move each element of the array one position to the left.
 * - The first element of the array is stored in a temporary variable.
 * - We shift all elements from the second element to the last element by one position to the left.
 * - Finally, we place the first element in the last position of the array.
 *
 * Time Complexity (T.C): O(n)
 * - We are looping through the array once, so the time complexity is O(n), where n is the size of the array.
 *
 * Space Complexity (S.C): O(1)
 * - We use a constant amount of space (only one temporary variable), so the space complexity is O(1).
 */

class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    int temp = nums[0]; // Store the first element

    // Shift all elements to the left by one position
    for (int i = 1; i < n; i++)
    {
      // Move each element one position to the left
      nums[i - 1] = nums[i];
    }

    nums[n - 1] = temp; // Place the first element in the last position
  }
};

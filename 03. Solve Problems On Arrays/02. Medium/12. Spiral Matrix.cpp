#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Only One Optimal Solution
 * We are traversing a matrix in spiral order and storing the result in a vector.
 * The algorithm proceeds as follows:
 * 1. We initialize the matrix dimensions and define boundary pointers: `top`, `left`, `bottom`, `right`.
 * 2. We use a `while` loop to traverse the matrix until all elements are visited.
 * 3. For each of the four directions (left to right, top to bottom, right to left, bottom to top), we traverse along the boundary and push the elements into the `ans` vector.
 * 4. After each traversal, the corresponding boundary is adjusted (increment/decrement) to move inward, narrowing the region to be processed.
 * ----------------------------
 * Time Complexity: O(n * m)
 * - We traverse each element of the matrix exactly once. So, the time complexity is O(n * m), where n is the number of rows and m is the number of columns in the matrix.
 * ----------------------------
 * Space Complexity: O(n * m)
 * - The space complexity is O(n * m) because we are storing all elements of the matrix in the result vector `ans`.
 */

class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    // Step 1: Initialize the necessary variables and boundary pointers.
    vector<int> ans;          // Define ans array to store the result
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns

    // Initialize boundary pointers for traversal: top, left, bottom, and right
    int top = 0, left = 0, bottom = n - 1, right = m - 1;

    // Step 2: Loop until all elements are traversed
    while (top <= bottom && left <= right)
    {

      // For moving left to right (traverse the top row)
      for (int i = left; i <= right; i++)
      {
        ans.push_back(matrix[top][i]); // Push each element into ans
      }
      top++; // Move the top boundary downwards

      // For moving top to bottom (traverse the rightmost column)
      for (int i = top; i <= bottom; i++)
      {
        ans.push_back(matrix[i][right]); // Push each element into ans
      }
      right--; // Move the right boundary to the left

      // For moving right to left (traverse the bottom row)
      if (top <= bottom)
      { // Check if there are still rows to traverse
        for (int i = right; i >= left; i--)
        {
          ans.push_back(matrix[bottom][i]); // Push each element into ans
        }
        bottom--; // Move the bottom boundary upwards
      }

      // For moving bottom to top (traverse the leftmost column)
      if (left <= right)
      { // Check if there are still columns to traverse
        for (int i = bottom; i >= top; i--)
        {
          ans.push_back(matrix[i][left]); // Push each element into ans
        }
        left++; // Move the left boundary to the right
      }
    }

    // Step 3: Return the result
    return ans;
  }
};

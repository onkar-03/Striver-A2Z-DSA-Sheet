#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force usign SImple Maths & Observation
 * The problem is about rotating a square matrix by 90 degrees in clockwise direction.
 * We can achieve this in two steps:
 * 1. First, we transpose the matrix: Swap rows with columns.
 * 2. Then, we reverse each row to get the final rotated matrix.
 * ----------------------------
 * Time Complexity: O(n^2)
 * - We traverse each element of the matrix twice (once for transposition and once for row reversal),
 *   resulting in a time complexity of O(n^2).
 * ----------------------------
 * Space Complexity: O(1)
 * - We perform the operation in-place by modifying the matrix directly,
 *   so the space complexity is O(1) (ignoring the space used for input and output).
 */
class Solution
{
public:
  vector<vector<int>> rotate(vector<vector<int>> &matrix)
  {
    // Get the number of rows (or columns, as it's a square matrix)
    int n = matrix.size();

    // Step 1: Initialize a new matrix to store the rotated result
    vector<vector<int>> rotated(n, vector<int>(n, 0)); // Create a matrix of the same size filled with zeros

    // Step 2: Traverse the matrix and place elements in the rotated position
    { // Loop through rows of the original matrix
      for (int i = 0; i < n; i++)
      { // Loop through columns of the original matrix
        for (int j = 0; j < n; j++)
          // Move the element to the rotated position
          rotated[j][n - i - 1] = matrix[i][j];
      }
    }

    return rotated; // Return the rotated matrix
  }
};

/*
 * Approach-2: Optimal Transpose + Reverse
 * The problem is about rotating a square matrix by 90 degrees in clockwise direction.
 * We can achieve this in two steps:
 * 1. First, we transpose the matrix: Swap rows with columns.
 * 2. Then, we reverse each row to get the final rotated matrix.
 * ----------------------------
 * Time Complexity: O(n^2)
 * - We traverse each element of the matrix twice (once for transposition and once for row reversal),
 *   resulting in a time complexity of O(n^2).
 * ----------------------------
 * Space Complexity: O(1)
 * - We perform the operation in-place by modifying the matrix directly,
 *   so the space complexity is O(1) (ignoring the space used for input and output).
 */
class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int n = matrix.size();

    // Step 1: Transpose the matrix by swapping rows and columns
    { // Note: only iterate for upper triangle to avoid redundant swaps
      // For every i we move from i + 1 to n-1 in columns
      // For transposing the whole Matrtix we traverse from 0 to n-2th row
      // All diagonal elements are untoched
      for (int i = 0; i < n; i++)
      {
        for (int j = i + 1; j < n; j++)
          swap(matrix[i][j], matrix[j][i]);
      }
    }

    // Step 2: Reverse each row to complete the 90-degree rotation
    for (int i = 0; i < n; i++)
    {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};

#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force (Using Row and Column Marking)
 * In this approach, we iterate through the matrix to identify cells with zeros.
 * For each zero cell, we mark the corresponding entire row and column by setting
 * non-zero elements to -1, avoiding modifying zeros directly. After marking the rows
 * and columns, we iterate through the matrix again and change all -1 values to zero.
 * ---------------------------
 * Time Complexity: O(2 * n * m)
 * - We iterate through the matrix twice. The first loop iterates over each element
 * of the matrix, which takes O(n * m). The second loop also iterates over the entire matrix,
 * which also takes O(n * m).
 * ---------------------------
 * Space Complexity: O(1)
 * - No additional space is used except for the input matrix. We are modifying the matrix
 * in-place.
 */

class Solution
{
public:
  void markRow(vector<vector<int>> &matrix, int n, int m, int i)
  {
    // Set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++)
    {
      // If element is not zero, mark it as -1
      if (matrix[i][j] != 0)
      {
        matrix[i][j] = -1;
      }
    }
  }

  // Function to mark a column where 0 was found by setting non-zero elements as -1
  void markCol(vector<vector<int>> &matrix, int n, int m, int j)
  {
    // set all non-zero elements as -1 in the column j:
    for (int i = 0; i < n; i++)
    {
      // If element is not zero, mark it as -1
      if (matrix[i][j] != 0)
      {
        matrix[i][j] = -1;
      }
    }
  }

  // Function to modify the matrix by setting the entire row and column to 0 for any zero element
  void setZeroes(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int m = matrix[0].size();

    // Iterate through the matrix to identify rows and columns containing zeros
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        // If element is zero, mark the entire row and column
        if (matrix[i][j] == 0)
        {
          markRow(matrix, n, m, i);
          markCol(matrix, n, m, j);
        }
      }
    }

    // After marking, set all -1 values as zero
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        // If element is -1, set it to zero
        if (matrix[i][j] == -1)
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

/*
 * Approach-2: Better Solution using Set but Time Complexity
 * 1. Traverse the matrix to identify all the rows and columns containing zeros.
 * 2. Use two sets, `zeroRows` and `zeroCols`, to store the indices of rows and columns that contain zeros.
 * 3. Traverse the matrix again and for each element, check if its row or column is in the `zeroRows` or `zeroCols` set.
 * 4. If true, set the element to zero.
 * ----------------------------
 * Time Complexity (T.C.):
 * - O(2 * m * n) for iterating through the matrix twice. First to identify rows and columns with zeros, and second to set the necessary elements to zero.
 * So, the overall time complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix.
 * ----------------------------
 * Space Complexity (S.C.):
 * - O(m + n) for the two sets storing the row and column indices. In the worst case, these sets can store all the rows and columns.
 */
class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    set<int> zeroRows, zeroCols;

    // Step 1: Identify the rows and columns that need to be zeroed
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 0)
        {
          zeroRows.insert(i); // Mark row
          zeroCols.insert(j); // Mark column
        }
      }
    }

    // Step 2: Set entire row and column to 0
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {

        // If the Row || Col or Both are 0 hten we mark the Value in that Row / Col as Zero
        if (zeroRows.count(i) || zeroCols.count(j))
        {
          matrix[i][j] = 0; // Set the element to zero if it's in a row or column marked for zeroing
        }
      }
    }
  }
};

/*
 * Approach-3: Optimal SOlution
 * 1. Use two sets (zeroRows and zeroCols) to track which rows and columns contain zeros.
 * 2. Traverse the matrix to identify the rows and columns containing zeros and mark them in the sets.
 * 3. Traverse the matrix again and set the elements to zero if their corresponding row or column is marked.
 *
 * Time Complexity (T.C.):
 * - O(m * n) for traversing the matrix twice: once to mark the rows and columns with zeros, and once to update the matrix.
 * So, the overall time complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix.
 * ----------------------------
 * Space Complexity (S.C.):
 * - O(m + n) for storing the rows and columns in the sets `zeroRows` and `zeroCols`.
 * The space complexity is proportional to the number of rows and columns.
 * ----------------------------
 */
class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    // Get the number of rows (m) and columns (n)
    int m = matrix.size();
    int n = matrix[0].size();

    // Initialize a variable to track the first column.
    int col0 = 1;

    // Step 1: Traverse the matrix and mark the first row and first column
    // as flags to indicate the rows and columns that need to be set to 0
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        // If we find a 0 at any position, mark the row and column
        // using the first row and first column
        if (matrix[i][j] == 0)
        {
          // Mark the corresponding row (first column)
          matrix[i][0] = 0;

          // Mark the corresponding column (first row)
          // But not the first 0,0 Place as its an overlaping block
          if (j != 0)
            matrix[0][j] = 0;
          else
            col0 = 0; // Special case: if 0 is in the first column, we mark col0 as 0
        }
      }
    }

    // Step 2: Use the information from the first row and first column
    // to set the rest of the matrix to 0 where applicable
    for (int i = 1; i < m; i++)
    {
      for (int j = 1; j < n; j++)
      {
        if (matrix[i][j] != 0)
        {
          // Check if the corresponding row or column has been marked
          if (matrix[i][0] == 0 || matrix[0][j] == 0)
          {
            matrix[i][j] = 0; // Set the element to 0 if needed
          }
        }
      }
    }

    // Step 3: Handle the first row and first column
    // If the first row has been marked, set all elements in the first row to 0
    if (matrix[0][0] == 0)
    {
      for (int j = 0; j < n; j++)
      {
        matrix[0][j] = 0;
      }
    }

    // If the first column has been marked, set all elements in the first column to 0
    if (col0 == 0)
    {
      for (int i = 0; i < m; i++)
      {
        matrix[i][0] = 0;
      }
    }
  }
};

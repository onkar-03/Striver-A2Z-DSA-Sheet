#include <bits/stdc++.h>
using namespace std;

// TYPE-3: Generate the Pascal's Triangle with M Row and N Columns

/*
 * Approach: Generating Pascal's Triangle Using Combinations nCr
 * 1. Each element in Pascal's Triangle can be calculated using the combination formula nCr
 * 2. The function `nCr(int n, int r)` computes the value of combinations iteratively to avoid direct factorial calculations, using the formula:
 *      nCr(n, r) = (n * (n-1) * ... * (n-r+1)) / (r!)
 * 3. The `generate(int numRows)` function constructs Pascal's Triangle:
 *    - For each row from 1 to numRows, it calculates and stores each element using nCr.
 *    - Each row is stored in a 2D vector.
 * --------------------
 * Time Complexity: O(n * r * r) which in worst case is O(n^3) i.e Iterating through all rows and columns to calculate nCr for each element
 * --------------------
 * Space Complexity: O(n^2) is to used for storing the entire Pascal's Triangle with n rows and variable columns
 */

class Solution
{
public:
  // Function to calculate nCr (Combination formula)
  int nCr(int n, int r)
  {
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
      res = res * (n - i);
      res = res / (i + 1);
    }
    return (int)(res);
  }

  // Function to generate Pascal's Triangle
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> ans; // To store the result

    // Generate each row of Pascal's Triangle
    for (int row = 1; row <= numRows; row++)
    {
      // Temporary list for each row
      vector<int> tempLst;

      // Each Row has same number of columns as the row number
      for (int col = 1; col <= row; col++)
      {
        // Calculate element using nCr formula
        tempLst.push_back(nCr(row - 1, col - 1));
      }
      // Add the row to the result
      ans.push_back(tempLst);
    }
    // Return the entire Pascal's Triangle
    return ans;
  }
};

#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-2: Generating Pascal's Triangle Using Iterative Row Calculation
 * 1. The method `generate(int numRows)` constructs Pascal's Triangle up to numRows:
 *    - It initializes a 2D vector to store the triangle.
 *    - For each row, it calls the helper function `generateRow` to compute the elements.
 *
 * 2. The helper function `generateRow(int row)` computes a specific row of Pascal's Triangle:
 *    - It starts with the first element, which is always 1.
 *    - For subsequent elements, it uses the relationship between adjacent elements:
 *      - Each element can be derived from the previous element using:
 *        ans = ans * (row - col) / col
 *    - This avoids the need for factorial calculations and allows for efficient computation.
 * --------------------
 * Time Complexity: O(N^2) where N is the number of rows in Pascal's Triangle, as we traverse them twice to generate the overall triangle
 * --------------------
 * Space Complexity: O(N^2) a 2D vector to store the result of Pascal's Triangle Generated
 */

class Solution
{
public:
  // Function to generate a specific row of Pascal's Triangle
  vector<int> generateRow(int row)
  {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); // Inserting the first element

    // Calculate the rest of the elements:
    for (int col = 1; col < row; col++)
    {
      ans = ans * (row - col);
      ans = ans / col;
      ansRow.push_back(ans);
    }
    return ansRow;
  }

  // Function to generate Pascal's Triangle with numRows
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> ans;

    // Store the entire Pascal's Triangle:
    for (int row = 1; row <= numRows; row++)
    {
      ans.push_back(generateRow(row));
    }
    return ans;
  }
};

int main()
{
  Solution solution; // Create an instance of Solution
  int n = 5;         // Number of rows
  vector<vector<int>> ans = solution.generate(n);

  // Print each row of Pascal's Triangle
  for (auto it : ans)
  {
    for (auto ele : it)
    {
      cout << ele << " ";
    }
    cout << endl; // Print a new line after each row
  }

  return 0;
}

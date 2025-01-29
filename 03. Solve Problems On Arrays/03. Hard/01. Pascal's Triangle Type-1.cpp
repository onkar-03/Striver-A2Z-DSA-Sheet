#include <bits/stdc++.h>
using namespace std;

// TYPE-1: Print the Value of 'Rt'h Row & 'Jth' Column in the Pascals Triangle
/*
 * --------------------
 * Approach: Using the Combination Formula (nCr)
 * --------------------
 * Formula: nCr = n! / (r! * (n - r)!)
 * Where:
 *   - n! = n factorial -> this is Row - 1
 *   - r! = r factorial -> This is Column - 1
 *   - (n - r)! = (n - r) factorial
 * Instead of calculating factorial of 'n' we iterate back from n, n-1 and so on till r elements only as the rest of them are anyways going to be cancelled from (n-r)!
 * --------------------
 * Time Complexity: O(r) as we loop 'r' times
 * --------------------
 * Space Complexity: O(1) (only a few variables for computation)
 */

class Solution
{
public:
  // Function to compute nCr (Combination formula)
  int nCr(int n, int r)
  {
    // Initialize result as 1
    long long res = 1;

    // Compute nCr using iterative formula
    for (int i = 0; i < r; i++)
    {
      // Multiply numerator (n-i)
      // -> X * X-1 * X-2 and so on ...
      res = res * (n - i);

      // Divide denominator (i+1)
      // -> X/1 * X'/2 amd so on ...
      res = res / (i + 1);
    }

    // Return computed nCr value
    return res;
  }

  // Function to get element at (r, c) in Pascal's Triangle
  int getElementAt(int r, int c)
  {
    return nCr(r - 1, c - 1); // Convert 1-based index to 0-based for calculation
  }
};
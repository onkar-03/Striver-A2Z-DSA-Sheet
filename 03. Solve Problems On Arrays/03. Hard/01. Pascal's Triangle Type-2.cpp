#include <bits/stdc++.h>
using namespace std;

// TYPE-2: Print the Nth Row of the Pascal's Triangle

/*
 * Approach-1: Using previous Logic of nCr for all elements of the Nth Row of the Pascal's Triangle (Naive Approach)
 * Explanation:
 *   - Pascal's Triangle starts with a single element '1' in the first row.
 *   - Each subsequent row contains one more element than the previous row, i.e., the nth row has n elements.
 *   - For each element in the nth row, we can calculate it using the combination formula nCr, where:
 *     - `n` is the row number (1-based index),
 *     - `r` is the column number (1-based index).
 *   - Each element of the nth row is computed as the combination of (n-1) taken r-1 at a time, i.e., (n-1)C(r-1).
 * --------------------
 * EG: the 6th Row has a Total of 6 elements in it
 * --------------------
 * Time Complexity: O(r) + O(n) as we iterate for nth row having n elements and for nCr we iterate r times
 * --------------------
 * Space Complexity: O(1) as we use only a few variables for computation
 */

int nCr(int n, int r)
{
  long long res = 1; // Initialize result as 1

  // Calculating nCr using the naive factorial approach
  // O(r) time complexity
  for (int i = 0; i < r; i++)
  {
    res = res * (n - i); // Multiply numerator (n - i)
    res = res / (i + 1); // Divide by (i + 1) to get the denominator
  }
  return res; // Return the computed nCr value
}

// Function to print the nth row of Pascal's Triangle
void generateRow(int n)
{
  // Printing the entire row 'n' using nCr
  // O(n) time complexity
  for (int c = 1; c <= n; c++)
  {
    // Get the element at position (n, c) in Pascal's Triangle
    cout << nCr(n - 1, c - 1) << " ";
  }
}

int main()
{
  int n = 5;      // Row number for Pascal's Triangle
  generateRow(n); // Print the nth row
  return 0;
}

/*
 * Approach-2: Using Iterative Formula to Generate Pascal's Triangle Elements
 * Formula: Using the relationship between adjacent elements in a row:
 *   - Each element in a row can be derived from the previous element as:
 *     element[i] = prevEl * (Row - Col) / Col;
 *   - The prevEl of every row is 1
 *
 * Explanation:
 *   - We start by printing the first element, which is always 1.
 *   - Then, for each subsequent element, we use the formula:
 *     element[i] = prevEl * (n - i) / i === prevEl * (Row - Col) / Col;
 *     This allows us to compute the elements in a row iteratively without using factorials.
 *   - This approach is more efficient than calculating factorials for each element of the row.
 * --------------------
 * Time Complexity: O(n) as we are Iterating through the row to calculate each element
 * --------------------
 * Space Complexity: O(1) as we use only a few variables used for computation
 */

void generateRow(int n)
{
  // Initialize the first element as 1
  // long long as the product can go out of bound in case of big numbers
  long long ans = 1;

  // Print the first element
  cout << ans << " ";

  // Printing the rest of the elements in the row
  for (int i = 1; i < n; i++)
  {
    // Update ans by multiplying with (n - i)
    ans = ans * (n - i);

    // Divide by i to get the next element
    ans = ans / i;

    // Print the current element
    cout << ans << " ";
  }
  cout << endl; // Print a newline at the end of the row
}

int main()
{
  int n = 5;      // Row number for Pascal's Triangle
  generateRow(n); // Print the nth row
  return 0;
}

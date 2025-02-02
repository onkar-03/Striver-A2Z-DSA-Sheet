#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force to check count of each Number from 1-N
 * - Iterate through numbers from 1 to n and count their occurrences in the array.
 * - If a number appears twice, it is the repeating number.
 * - If a number does not appear, it is the missing number.
 * - Stop early if both are found.
 * ----------------------------
 * T.C: O(n^2)  // Nested loop results in quadratic time complexity
 * ----------------------------
 * S.C: O(1)    // Only a few integer variables are used.
 */
class Solution
{
public:
  vector<int> findTwoElement(vector<int> &arr)
  {
    // Get the size of the array
    int n = arr.size();

    // Variables to store results
    int repeating = -1, missing = -1;

    // Iterate through numbers from 1 to n:
    for (int i = 1; i <= n; i++)
    {
      // Counter to count occurrences of number 'i'
      int cnt = 0;

      // Count occurrences of the number in the array:
      for (int j = 0; j < n; j++)
      {
        if (arr[j] == i)
          // Increment if found
          cnt++;
      }

      // As i represent directly the number here so we assign i as the missing / repeating number
      if (cnt == 2)
        repeating = i; // Found repeating number
      else if (cnt == 0)
        missing = i; // Found missing number

      // Stop early if both are found
      if (repeating != -1 && missing != -1)
        break;
    }
    // Return the results
    return {repeating, missing};
  }
};

/*
 * Approach-2: Using Hashing
 * - Use a hash array of size (n+1) to count occurrences of each number.
 * - Iterate through the given array and update the hash array.
 * - Traverse the hash array to find:
 *   - The repeating number (count == 2).
 *   - The missing number (count == 0).
 * ----------------------------
 * T.C: O(2 * n)  // Single pass to update hash and another pass to find results
 * ----------------------------
 * S.C: O(n)  // Extra hash array of size (n+1).
 */

class Solution
{
public:
  vector<int> findTwoElement(vector<int> &arr)
  {
    int n = arr.size();         // Get the size of the array
    vector<int> hash(n + 1, 0); // Hash array to store occurrences

    // Update the hash array:
    for (int i = 0; i < n; i++)
    {
      hash[arr[i]]++; // Increment count of each element
    }

    // Find the repeating and missing number:
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
      if (hash[i] == 2)
        repeating = i; // Found repeating number
      else if (hash[i] == 0)
        missing = i; // Found missing number

      if (repeating != -1 && missing != -1)
        break; // Stop early if both are found
    }
    return {repeating, missing}; // Return the results
  }
};

/*
 * Approach:
 * - First, calculate the expected sum (SN) and sum of squares (S2N) for numbers 1 to n.
 * - Compute the actual sum (S) and sum of squares (S2) from the array.
 * - Find X - Y by subtracting expected sum from actual sum.
 * - Find X² - Y² by subtracting expected sum of squares from actual sum of squares.
 * - Solve for X (repeating number) and Y (missing number) using:
 *   - X + Y = (X² - Y²) / (X - Y)
 *   - X = (X + Y + X - Y) / 2
 *   - Y = X - (X - Y)
 * ----------------------------
 * T.C: O(n)  As we do a Single pass to compute S and S2.
 * ----------------------------
 * S.C: O(1)  We only use a few extra variables.

 */

class Solution
{
public:
  vector<int> findTwoElement(vector<int> &arr)
  {
    long long n = arr.size(); // Get the size of the array

    // Compute expected sum (SN) and sum of squares (S2N):
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Compute actual sum (S) and sum of squares (S2):
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
      // Sum of elements
      S += arr[i];

      // Sum of squares
      // Typecasting int as long long to make sure they are well in the range after summation
      S2 += (long long)arr[i] * arr[i];
    }

    // Compute X - Y (val1) and X² - Y² (val2)
    long long val1 = S - SN;
    long long val2 = S2 - S2N;

    // Compute X + Y using (X² - Y²) / (X - Y)
    val2 = val2 / val1;

    // Compute X (repeating) and Y (missing)
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y}; // Return results
  }
};
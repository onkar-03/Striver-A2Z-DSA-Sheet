#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////////////////////
// --- Given Number of Positives & Negetives are Equal ---
/*
 * Approach-1: Brute Force
 * ----------------------------
 * Time Complexity: O(2*n)
 * - We iterate over the input array twice (once to segregate and once to rearrange), resulting in O(n) time complexity, where n is the size of the array.
 * ----------------------------
 * Space Complexity: O(2*n)
 * - We use two extra vectors (positive and negative), each of size O(n/2), so the space complexity is O(n).
 *
 */

class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    // Define 2 vectors, one for storing positive
    // and the other for negative elements of the array.
    vector<int> pos;
    vector<int> neg;

    // Segregate the array into positives and negatives.
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > 0)
        pos.push_back(nums[i]);
      else
        neg.push_back(nums[i]);
    }

    // By Observation we know: Positives on even indices, negatives on odd indices
    // Hence we update the nums array with positive and negetive alternate values
    for (int i = 0; i < nums.size() / 2; i++)
    {
      // Place positive numbers at even indices
      nums[2 * i] = pos[i];

      // Place negative numbers at odd indices
      nums[2 * i + 1] = neg[i];
    }

    // Return the rearranged array.
    return nums;
  }
};

/*
 * Approach-1: Index Based Approach Better Appraoch using Sinlge Iteration
 * When we are said Number iof Positives == Number of Negetives
 * 1. Initialize two pointers, `pos` for placing positive numbers at even indices and `neg` for placing negative numbers at odd indices.
 * 2. Traverse through the given array:
 *    - If the current element is positive, place it at the position pointed by `pos` and increment `pos` by 2.
 *    - If the current element is negative, place it at the position pointed by `neg` and increment `neg` by 2.
 * ----------------------------
 * T.C: O(n)
 * - We traverse through the entire array once, where `n` is the length of the input array.
 * ----------------------------
 * S.C: O(n)
 * - We use a new array `ans` of size `n` to store the rearranged elements.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    int n = nums.size();

    int pos = 0; // Pointer for placing positive numbers
    int neg = 1; // Pointer for placing negative numbers

    vector<int> ans(n, 0); // Array to store the rearranged result

    for (int i = 0; i < n; i++)
    {
      // If the number is positive
      if (nums[i] > 0 && pos < n)
      {
        // Place positive number at the current position
        ans[pos] = nums[i];

        // Move to the next even index
        pos += 2;
      }
      // If the number is negative
      if (nums[i] < 0 && neg < n)
      {
        // Place negative number at the current position
        ans[neg] = nums[i];

        // Move to the next odd index
        neg += 2;
      }
    }
    return ans; // Return the rearranged array
  }
};

///////////////////////////////////////////////////////////////////
// --- Given Number of Positives != Number of Negtives ---

/*
 * Approach:
 * 1. Define two vectors, `pos` for storing positive numbers and `neg` for storing negative numbers.
 * 2. Traverse through the array and segregate the numbers into `pos` and `neg` vectors.
 * 3. Check if the number of positives is less than the number of negatives:
 *    - If true, alternate the placement of positives and negatives in the array, starting with the positives.
 *    - After that, place the remaining negatives at the end of the array.
 * 4. If the number of negatives is less than or equal to the number of positives:
 *    - Alternate the placement of positives and negatives, starting with the positives.
 *    - After that, place the remaining positives at the end of the array.
 * 5. Finally, return the rearranged array.
 * ----------------------------
 * T.C: O(n)
 * - We traverse the array to separate positives and negatives, then fill the array alternatively, both taking O(n) time.
 * ----------------------------
 * S.C: O(n)
 * - We use two extra arrays `pos` and `neg`, each storing a subset of the input array, thus requiring O(n) space.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &A)
  {
    int n = A.size();

    // Define 2 vectors, one for storing positive
    // and other for negative elements of the array.
    vector<int> pos;
    vector<int> neg;

    // Segregate the array into positives and negatives.
    for (int i = 0; i < n; i++)
    {
      if (A[i] > 0)
        pos.push_back(A[i]);
      else
        neg.push_back(A[i]);
    }

    // If positives are lesser than the negatives.
    if (pos.size() < neg.size())
    {
      // First, fill array alternatively till the point where positives and negatives are equal in number.
      for (int i = 0; i < pos.size(); i++)
      {
        A[2 * i] = pos[i];
        A[2 * i + 1] = neg[i];
      }

      // Fill the remaining negatives at the end of the array.
      int index = pos.size() * 2;
      for (int i = pos.size(); i < neg.size(); i++)
      {
        A[index] = neg[i];
        index++;
      }
    }
    // If negatives are lesser than the positives.
    else
    {
      // First, fill array alternatively till the point
      // where positives and negatives are equal in number.
      for (int i = 0; i < neg.size(); i++)
      {
        A[2 * i] = pos[i];
        A[2 * i + 1] = neg[i];
      }

      // Fill the remaining positives at the end of the array.
      int index = neg.size() * 2;
      for (int i = neg.size(); i < pos.size(); i++)
      {
        A[index] = pos[i];
        index++;
      }
    }
    return A;
  }
};

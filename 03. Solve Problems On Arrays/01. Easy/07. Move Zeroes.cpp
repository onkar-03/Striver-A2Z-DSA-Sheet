#include <bits/stdc++.h>
using namespace std;
/*
 * Approach-1: Brute Force usign Temp Space
 * - We iterate through the input array and store all the non-zero elements in a temporary array.
 * - After that, we copy the elements from the temporary array back to the original array.
 * - Finally, we fill the remaining positions in the original array with zeros.
 * ----------------------------
 * T.C: O(n)
 * - We iterate over the array twice: first to collect non-zero elements, then to fill the array with non-zero elements and zeros.
 * ----------------------------
 * S.C: O(k)
 * - We use an extra temporary array of size k to store the non-zero elements.
 */

class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int n = nums.size();

    // temporary array:
    vector<int> temp;

    // Step 1: Store non-zero elements in temp array
    for (int i = 0; i < n; i++)
    {
      if (nums[i] != 0)
        temp.push_back(nums[i]);
    }

    // number of non-zero elements.
    int nz = temp.size();

    // Step 2: Copy non-zero elements from temp to original array
    for (int i = 0; i < nz; i++)
    {
      nums[i] = temp[i];
    }

    // Step 3: Fill remaining positions with 0
    for (int i = nz; i < n; i++)
    {
      nums[i] = 0;
    }
  }
};

/*
 * Approach-2: Two pointer Approach
 * - Initially, move `j` forward until we find the first zero element (or reach the end).
 * - Then, iterate through the array with `i` and whenever we find a non-zero element, we swap it with the element at index `j` and increment `j`.
 * - This ensures all non-zero elements are moved to the front and zeros are moved to the end.
 * ----------------------------
 * T.C: O(n)
 * - We are iterating through the array only once using two pointers, so the time complexity is O(n).
 * ----------------------------
 * S.C: O(1)
 * - We use constant extra space, so the space complexity is O(1).
 */

class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the input array
    int j = 0;           // Initialize pointer `j` to track the next position for non-zero elements

    // Find the first zero element
    while (j < n && nums[j] != 0)
    {
      j++; // Move `j` forward until we find a zero element or reach the end
    }

    int i = j + 1; // Start `i` from the next element after `j`
    while (i < n)
    {
      // Whenever we find a non-zero element, swap it with `nums[j]`
      if (nums[i] != 0)
      {
        swap(nums[j], nums[i]);
        j++; // Increment `j` to the next available position for non-zero elements
      }
      i++; // Move `i` to the next element in the array
    }
  }
};
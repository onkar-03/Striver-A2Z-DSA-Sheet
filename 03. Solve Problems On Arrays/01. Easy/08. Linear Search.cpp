#include <bits/stdc++.h>
using namespace std;

/*
 * Approach:
 * - We iterate through the entire array from the start and compare each element with the given value `k`.
 * - If we find an element equal to `k`, we return true, indicating that the element is present in the array.
 * - If the loop finishes and no such element is found, we return false, indicating that the element is not present in the array.
 * ----------------------------
 * T.C: O(n)
 * - We are iterating through the array once, so the time complexity is O(n), where `n` is the size of the array.
 * ----------------------------
 * S.C: O(1)
 * - We only use a few extra variables (`i` and `n`), so the space complexity is O(1), constant space.
 */

class Solution
{
public:
  // Function to find element in sorted array
  // arr: input array
  // k: element to be searched
  bool searchInSorted(vector<int> &arr, int k)
  {
    int n = arr.size(); // Get the size of the input array
    // Loop through each element in the array
    for (int i = 0; i < n; i++)
    {
      // If element `arr[i]` equals `k`, return true
      if (arr[i] == k)
      {
        return true;
      }
    }
    // If element `k` is not found, return false
    return false;
  }
};

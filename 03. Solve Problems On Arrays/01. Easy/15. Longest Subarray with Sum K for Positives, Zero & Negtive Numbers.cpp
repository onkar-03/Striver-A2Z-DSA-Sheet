#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: (Using sliding window with two pointers)
 * ---------------------------
 * Time Complexity: O(n)
 * - We are using the sliding window approach where both `left` and `right` pointers move from left to right.
 * - Each element is processed at most twice (once when added to the sum and once when subtracted), making the time complexity O(n).
 * ---------------------------
 * Space Complexity: O(1)
 * - We are using only a few integer variables (`left`, `right`, `sum`, `maxLen`), so the space complexity is constant.
 */
class Solution
{
public:
  int longestSubarray(vector<int> &arr, int k)
  {
    int n = arr.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = arr[0];  // Initialize sum with the first element
    int maxLen = 0;

    // Slide the right pointer across the array
    while (right < n)
    {
      // if sum > k, reduce the subarray from left
      // until sum becomes less or equal to k:
      while (left <= right && sum > k)
      {
        sum -= arr[left]; // Subtract the element at 'left'
        left++;           // Move the left pointer forward to shrink the window
      }

      // if sum = k, update the maxLen i.e. answer:
      if (sum == k)
      {
        maxLen = max(maxLen, right - left + 1); // Update maxLen with the current window length
      }

      // Move forward the right pointer:
      // Expand the window by moving the right pointer
      right++;
      if (right < n)
        // Add the element at 'right' to the sum
        sum += arr[right];
    }

    return maxLen; // Return the length of the longest subarray found
  }
};

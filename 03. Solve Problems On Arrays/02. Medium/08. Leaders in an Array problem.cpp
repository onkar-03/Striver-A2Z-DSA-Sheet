#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force
 * - Iterate through each element in the array.
 * - For each element, check if it is greater than all elements to its right.
 * - If it is, add it to the result list.
 * T.C: O(N^2) (Nested loop checking each element against all right-side elements)* ----------------------------
 * S.C: O(N) used For storing leader elements, incase space is asked to solve the problem then i havent used any in that case its O(1)
 */

class Solution
{
public:
  vector<int> leaders(vector<int> &arr)
  {
    int n = arr.size(); // Get the size of the array
    vector<int> ans;    // Stores leader elements

    for (int i = 0; i < n; i++)
    {
      bool leader = true; // Assume current element is a leader

      // Check if arr[i] is greater than all elements to its right
      for (int j = i + 1; j < n; j++)
      {
        if (arr[j] > arr[i])
        {
          leader = false; // If a greater element is found, it's not a leader
          break;          // No need to check further
        }
      }

      if (leader)
        ans.push_back(arr[i]); // Store the leader element
    }

    return ans; // Return the list of leaders
  }
};

/*
 * Approach-2: Optimal Right to Left Traversal
 * - Traverse the array from right to left.
 * - The rightmost element is always a leader, so add it to the result.
 * - Maintain a variable `max` to track the maximum seen so far from the right.
 * - If the current element is greater than `max`, it is a leader, so add it to the result and update `max`.
 * ----------------------------
 * T.C: O(N)
 * - We traverse the array once from right to left, which takes O(N).
 * - The reversal operation takes O(N) as well.
 * - Hence, the total complexity remains **O(N) + O(N) = O(N)**.
 * ----------------------------
 * S.C: O(N)
 * - We use an extra vector to store the leaders, which can have at most O(N) elements in the worst case (strictly decreasing array).
 */

class Solution
{
public:
  vector<int> leaders(vector<int> &arr)
  {
    // Get the size of the array
    int n = arr.size();

    // Stores leader elements
    vector<int> ans;

    // The last element is always a leader
    int max = arr[n - 1];

    // Store the last element
    ans.push_back(max);

    // Traverse from second-last element to the first
    for (int i = n - 2; i >= 0; i--)
    {
      { // If the current element is greater than / equal to max Store the leader element
        // EG: 62,61,17 Ans: 61, 61, 17
        if (arr[i] >= max)
          ans.push_back(arr[i]);

        // Update max
        max = arr[i];
      }
    }

    // Reverse the result to maintain correct order
    reverse(ans.begin(), ans.end());

    // Return the list of leaders
    return ans;
  }
};

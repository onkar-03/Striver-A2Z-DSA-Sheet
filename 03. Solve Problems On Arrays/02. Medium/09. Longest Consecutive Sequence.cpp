#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force Simple Iteration
 * - We iterate through each element in the array and consider it as the start of a sequence
 * - Use linear search to check for the presence of consecutive elements `(num+1, num+2, ...)`.
 * - Maintain a variable `count` to keep track of the **length of the consecutive sequence**.
 * - Update `longest` to store the maximum length found.
 * ----------------------------
 * T.C: O(N^2)
 * - **Outer loop runs O(N) times** as we check each element.
 * - **Inner while loop does O(N) work in the worst case** (if elements are consecutive).
 * - Hence, the worst-case complexity is **O(N^2)**.
 * ----------------------------
 * S.C: O(1)
 * - No extra data structures are used apart from a few integer variables.
 * - The space complexity remains **O(1)** as no additional storage is required.
 */

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array
    if (n == 0)
      return 0; // Edge case: if array is empty, return 0

    int longest = 1; // Variable to store the longest consecutive sequence

    // Iterate through each number and check for the longest sequence
    for (int i = 0; i < n; i++)
    {
      int x = nums[i]; // Start element
      int count = 1;   // Track length of consecutive sequence

      // Check for consecutive numbers using linear search
      while (find(nums.begin(), nums.end(), x + 1) != nums.end())
      {
        x += 1;     // Move to next number in sequence
        count += 1; // Increase sequence length
      }

      longest = max(longest, count); // Update longest found sequence
    }

    return longest; // Return the longest consecutive sequence length
  }
};

/*
 * Approach:-2 : Using Sorting + Single Traversal
 * The array is first sorted to bring consecutive elements together.
 * We iterate over the sorted array and compare each element with the previous one.
 * If the current element is the next number in the sequence (i.e., current number = previous number + 1), we increment the count.
 * If it's not, we reset the count to 1.
 * We keep track of the longest sequence found and return it at the end.
 * ----------------------------
 * T.C: O(N*log N)
 * Sorting the array takes O(N log N) time. After sorting, the loop runs in O(N) time.
 * Hence, the overall time complexity is O(N log N).
 * ----------------------------
 * S.C: O(1)
 * The algorithm uses a constant amount of space apart from the input array.
 * Space complexity remains O(1) as no extra data structures are used.
 */

class Solution
{
public:
  int longestConsecutive(vector<int> &a)
  {
    // Get the size of the array
    int n = a.size();

    // Edge case: if the array is empty, return 0
    if (n == 0)
      return 0;

    // Sort the array
    sort(a.begin(), a.end());

    // Initialize variables
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    // Find the longest consecutive sequence
    for (int i = 0; i < n; i++)
    {
      // Check if the current element is the next in the sequence
      if (a[i] - 1 == lastSmaller)
      {
        // Increment count for the current sequence
        cnt += 1;

        // Update the last element in the sequence
        lastSmaller = a[i];
      }
      else if (a[i] != lastSmaller)
      {
        // Reset the count if the current element is not consecutive
        cnt = 1;

        // Update the last element in the sequence
        lastSmaller = a[i];
      }

      // Update the longest sequence found
      longest = max(longest, cnt);
    }

    // Return the longest consecutive sequence length
    return longest;
  }
};

/*
 * Approach-3: Using Hash Set & Left Neighbour Logic
 * ----------------------------
 * 1. Store all elements in an unordered_set to allow O(1) lookups.
 * 2. Iterate through each element in the set:
 *    - Check if the current number is the start of a potential sequence (i.e., `num - 1` is not in the set)
 *    - If it is, calculate the length of the sequence by checking consecutive numbers (`num + 1`, `num + 2`, ...).
 *    - Update the longest sequence length found so far.
 * 3. Return the maximum sequence length after checking all numbers.
 * ----------------------------
 * Time Complexity (T.C): O(n)
 * - Each element is visited at most twice: once for the initial iteration and once for checking consecutive elements.
 * - The unordered_set allows O(1) lookups.
 * ----------------------------
 * Space Complexity (S.C): O(n)
 * - The unordered_set stores all unique elements of the input array.
 */

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    // Step 1: Store all elements in an unordered_set for O(1) lookups
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0; // Initialize the variable to store the longest sequence length

    // Step 2: Iterate through each number in the set
    for (int num : numSet)
    {
      // Check if the current number is the start of a sequence
      // (i.e., `num - 1` is not in the set, so `num` is the smallest in its sequence)
      if (numSet.find(num - 1) == numSet.end())
      {
        int length = 1; // Initialize the length of the current sequence

        // Step 3: Find consecutive numbers in the sequence
        while (numSet.find(num + length) != numSet.end())
        {
          length++; // Increase the sequence length as we find consecutive numbers
        }

        // Step 4: Update the longest sequence length
        longest = max(longest, length);
      }
    }

    // Step 5: Return the maximum sequence length found
    return longest;
  }
};

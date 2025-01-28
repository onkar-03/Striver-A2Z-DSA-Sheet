#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force (Finding all possible permutations)
 * ----------------------------
 * - We generate all possible permutations of the given array.
 * - Sort these permutations in lexicographical order.
 * - Find the current permutation in this sorted list and return the next one.
 *
 * Steps:
 * 1. Generate all permutations using recursion.
 * 2. Store them in a set to remove duplicates and sort them.
 * 3. Locate the given permutation in this list and return the next one.
 * ----------------------------
 * T.C: O(N! * N)
 * - Generating all permutations takes O(N!), and storing/sorting takes O(N! * N).
 * - Searching for the current permutation in the sorted list takes O(N!).
 * ----------------------------
 * S.C: O(N!)
 * - Storing all permutations requires O(N!) space.
 */

class Solution
{
public:
  void generatePermutations(vector<int> &nums, int index, set<vector<int>> &permSet)
  {
    if (index == nums.size())
    {
      // Store the generated permutation
      permSet.insert(nums);
      return;
    }
    for (int i = index; i < nums.size(); i++)
    {
      // Swap elements to create a new permutation
      swap(nums[index], nums[i]);

      // Recursive call
      generatePermutations(nums, index + 1, permSet);

      // Backtrack to restore original order
      swap(nums[index], nums[i]);
    }
  }

  // Function to return the next permutation using brute force
  void nextPermutation(vector<int> &nums)
  {
    // Set to store unique permutations
    set<vector<int>> permSet;

    // Generate all permutations
    generatePermutations(nums, 0, permSet);

    auto it = permSet.find(nums); // Locate current permutation
    if (it != permSet.end() && next(it) != permSet.end())
    {
      nums = *next(it); // Get the next permutation in lexicographical order
    }
    else
    {
      nums = *permSet.begin(); // If last permutation, return the first one
    }
  }
};

/*
 * Approach-2: Using STL Library in C++
 * - We use the built-in `next_permutation` function to rearrange the given vector to its next lexicographically greater permutation.
 * - If the given sequence is the largest permutation, it rearranges it into the smallest permutation (sorted order).
 * ----------------------------
 * T.C: O(N)
 * - Finding the rightmost decreasing element and swapping takes O(N).
 * - Reversing the suffix takes O(N), leading to an overall O(N) complexity.
 * ----------------------------
 * S.C: O(1)
 * - We modify the array in place without using extra space.
 */

class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    // Built-in function to find next permutation
    next_permutation(nums.begin(), nums.end());
  }
};

/*
 * Approach-3: Build Algorithm for the next Permutation
 * - Find the rightmost index (`ind`) where `A[ind] < A[ind + 1]` (break point).
 * - If no such index exists, reverse the entire array as it is the last permutation.
 * - Otherwise, swap `A[ind]` with the smallest element on its right that is larger than `A[ind]`.
 * - Reverse the right half to get the next lexicographical permutation.
 * ----------------------------
 * T.C: O(N)
 * - Finding the break point takes O(N).
 * - Finding the next greater element takes O(N).
 * - Reversing the suffix takes O(N), leading to an overall O(N) complexity.
 * ----------------------------
 * S.C: O(1)
 * - The array is modified in place without using extra space.
 */

class Solution
{
public:
  // Function to generate the next lexicographical permutation
  void nextPermutation(vector<int> &nums)
  {
    int n = nums.size(); // Size of the array

    // Step 1: Find the break point (first decreasing element from the right)
    // Initialize break point index
    int ind = -1;

    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; i--)
    {
      { // Find the rightmost decreasing element
        // This is out Breakpoint
        if (nums[i] < nums[i + 1])
          ind = i;
        break;
      }
    }

    // If no break point exists, reverse the entire array (last permutation case)
    if (ind == -1)
    {
      // Reverse to get the first permutation
      reverse(nums.begin(), nums.end());
      return;
    }

    // Step 2: Find the smallest number on the right that is greater than nums[ind]
    for (int i = n - 1; i > ind; i--)
    {
      if (nums[i] > nums[ind])
      { // Swap with the smallest greater element
        swap(nums[i], nums[ind]);
        break;
      }
    }

    // Step 3: Reverse the right half to get the next permutation
    reverse(nums.begin() + ind + 1, nums.end());
  }
};

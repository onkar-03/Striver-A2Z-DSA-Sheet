#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Left Rotate Array by k Places Using Temp Array
 * - Save the first k elements in a temporary array.
 * - Shift the remaining elements in the original array to the left by k positions.
 * - Copy the saved elements from the temporary array to the end of the array.
 * ----------------------------
 * T.C: O(n)
 * - Storing k elements in temp takes O(k).
 * - Shifting n-k elements takes O(n-k).
 * - Copying k elements back takes O(k).
 * - Overall: O(n).
 * ----------------------------
 * S.C: O(k)
 * - A temporary array of size k is used.
 */
class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();

    // Ensure k is within bounds
    // If k is very large then we bring it back to bounds
    k = k % n;

    // Step 1: Create a temporary array to store the first k elements
    vector<int> temp(k, 0);
    for (int i = 0; i < k; i++)
    {
      temp[i] = nums[i]; // Store the first k elements in temp
    }

    // Step 2: Shift the remaining elements to the left by k positions
    for (int i = k; i < n; i++)
    {
      nums[i - k] = nums[i]; // Move elements from index k onwards to the left
    }

    // Step 3: Place the stored elements from temp at the end of the array
    for (int i = n - k; i < n; i++)
    {
      // Copy elements from temp to the end
      nums[i] = temp[i - (n - k)];
    }
  }
};

/*
 * Approach: Right Shift Array by k Places Using Temp Array
 * - Save the last k elements in a temporary array.
 * - Shift the first n-k elements of the array to the right by k positions.
 * - Place the saved elements from the temporary array at the beginning of the array.
 * ----------------------------
 * T.C: O(n)
 * ----------------------------
 * S.C: O(k)
 */
class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();

    // Ensure k is within bounds
    k = k % n;

    // Step 1: Create a temporary array to store the last k elements
    vector<int> temp(k, 0);
    for (int i = 0; i < k; i++)
    {
      temp[i] = nums[n - k + i]; // Store the last k elements in temp
    }

    // Step 2: Shift the first n-k elements to the right by k positions
    for (int i = n - k - 1; i >= 0; i--)
    {
      nums[i + k] = nums[i]; // Shift elements to the right
    }

    // Step 3: Place the stored elements from temp at the beginning of the array
    for (int i = 0; i < k; i++)
    {
      nums[i] = temp[i]; // Copy elements from temp to the start
    }
  }
};

/*
 * Approach: Left Shift by k Places Using Reverse Technique
 * - Reverse the first n-k elements.
 * - Reverse the last k elements.
 * - Reverse the entire array.
 * ----------------------------
 * T.C: O(n)
 * - Reversing the entire array and portions of it take O(n) time.
 * ----------------------------
 * S.C: O(1)
 * - No additional space is used apart from a few variables.
 */
class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();

    // Ensure k is within bounds
    k = k % n; // If k is very large, bring it within bounds

    // Step 1: Reverse the first n-k elements
    reverse(nums.begin(), nums.begin() + n - k);

    // Step 2: Reverse the last k elements
    reverse(nums.begin() + n - k, nums.end());

    // Step 3: Reverse the entire array
    reverse(nums.begin(), nums.end());
  }
};

/*
 * Approach: Right Shift by k Places Using Reverse Technique
 * - Reverse the entire array.
 * - Reverse the first k elements.
 * - Reverse the remaining n-k elements.
 * ----------------------------
 * T.C: O(n)
 * - Reversing the entire array takes O(n), reversing the first k elements takes O(k),
 *   and reversing the remaining n-k elements takes O(n-k). Therefore, the overall time complexity is O(n).
 * ----------------------------
 * S.C: O(1)
 * - No additional space is used apart from a few variables.
 */
class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();

    // Ensure k is within bounds
    k = k % n; // If k is very large, bring it within bounds

    // Step 1: Reverse the entire array
    reverse(nums.begin(), nums.end());

    // Step 2: Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Step 3: Reverse the remaining n-k elements
    reverse(nums.begin() + k, nums.end());
  }
};

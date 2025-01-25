#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force)
 * --------------------
 * Time Complexity: O(N^2)
 * - The outer loop runs N times, and for each element in the array, we count its frequency by iterating through the entire array (which takes O(N) time).
 * - Hence, the total time complexity is O(N^2).
 * --------------------
 * Space Complexity: O(1)
 * - We are not using any extra space apart from variables for iteration and counting, so the space complexity is O(1).
 */
class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array

    // Iterate through each element in the array
    for (int i = 0; i < n; i++)
    {
      int cnt = 0; // Initialize a counter for the current element

      // Count the frequency of nums[i]
      for (int j = 0; j < n; j++)
      {
        if (nums[j] == nums[i])
        {
          cnt++; // Increment the counter if nums[j] matches nums[i]
        }
      }

      // Check if the count of the current element is greater than n/2
      if (cnt > (n / 2))
      {
        return nums[i]; // If so, return the majority element
      }
    }

    return -1; // Return -1 if no majority element is found
  }
};

/*
 * Approach-2: Using Map to Count Frequencies
 * ----------------------------
 * Time Complexity: O(n)
 * - We iterate over the array to count the frequency of each element using a map.
 * - The time complexity for this step is O(n).
 * - Searching through the map also takes O(n) time, but it is done in linear time.
 * ----------------------------
 * Space Complexity: O(n)
 * - The space complexity is O(n) because we use a map to store the frequency of each element.
 */
class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {

    // Size of the given array:
    int n = nums.size();

    // Declaring a map to store the frequency of elements:
    map<int, int> mpp;

    // Storing the elements with their occurrences:
    for (int i = 0; i < n; i++)
    {
      mpp[nums[i]]++; // Increment the count for each element
    }

    // Searching for the majority element:
    for (auto it : mpp)
    {
      // See it teh freq of element is greater than 2
      if (it.second > (n / 2))
      {
        // Return the element with frequency greater than n/2
        return it.first;
      }
    }

    return -1; // Return -1 if no majority element is found
  }
};

/*
 * Approach-3: Using Boyer-Moore Voting Algorithm
 * ----------------------------
 * Time Complexity: O(2*n)
 * - We iterate through the array once to find a candidate majority element.
 * - Then, we iterate again to verify if it truly is the majority element.
 * The Second check wont be done if Question says there will always exist a majority element. Then we simply return 'el'
 * ----------------------------
 * Space Complexity: O(1)
 * - We use a constant amount of extra space (only variables for count and element).

 */
class Solution
{
public:
  int majorityElement(vector<int> &v)
  {

    // size of the given array:
    int n = v.size();

    int cnt = 0; // count of occurrences
    int el;      // potential majority element

    // First pass: finding the majority element candidate using Boyer-Moore voting algorithm
    for (int i = 0; i < n; i++)
    {
      // If count is zero, update the candidate element and reset count
      if (cnt == 0)
      {
        cnt = 1;
        el = v[i]; // Candidate element is v[i]
      }
      // If the current element is the same as the candidate, increment count
      else if (el == v[i])
      {
        cnt++;
      }
      // If current element is different, decrement count
      else
      {
        cnt--;
      }
    }

    // Second pass: verifying if the candidate is indeed the majority element
    int cnt1 = 0; // To store the count of the candidate element
    for (int i = 0; i < n; i++)
    {
      if (v[i] == el)
      {
        cnt1++; // Counting occurrences of the candidate element
      }
    }

    // If count is greater than n/2, the candidate is the majority element
    if (cnt1 > (n / 2))
    {
      return el; // Return the majority element
    }

    // If no majority element exists, return -1
    return -1;
  }
};

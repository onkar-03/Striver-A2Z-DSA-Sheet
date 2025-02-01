#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force
 * - Use four nested loops to check all possible quadruplets.
 * - For each quadruplet, calculate the sum and compare it with the target.
 * - Sort each quadruplet to ensure uniqueness and store it in a set.
 * --------------------
 * T.C: O(n^4)
 * - We have four nested loops, each iterating over the array, giving us a time complexity of O(n^4).
 * --------------------
 * S.C: O(2 * n)
 * - We store the unique quadruplets in a set. In the worst case, this could take O(2 * n) space where n is the number of quads we get and twice as we store in ans set and also the st
 */

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    int n = nums.size(); // Get array size
    set<vector<int>> st; // To store unique quadruplets

    // Checking all possible quadruplets
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        for (int k = j + 1; k < n; k++)
        {
          for (int l = k + 1; l < n; l++)
          {
            // Calculate the sum of the current quadruplet
            long long sum = nums[i] + nums[j] + nums[k] + nums[l];

            // If sum equals target, add to set (to ensure uniqueness)
            if (sum == target)
            {
              vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};

              // Sort to maintain order & Uniqueness
              sort(temp.begin(), temp.end());

              // Insert into set
              st.insert(temp);
            }
          }
        }
      }
    }

    // Convert set to vector to return the result
    vector<vector<int>> ans(st.begin(), st.end());

    // Return the result
    return ans;
  }
};

class Solution
{
public:
  /*
   * Approach-2: Using Hashing with Set
   * - Use three nested loops to check all possible triplets, and then use a hashset to find the fourth element.
   * - For each triplet, calculate the sum of the first three elements and check if the fourth element exists in the hashset.
   * - Sort each quadruplet to ensure uniqueness and store it in a set.
   * --------------------
   * T.C: O(n^3)
   * - We have three nested loops, and for each triplet, the hashset operation takes constant time.
   * --------------------
   * S.C: O(n)
   * - The hashset used for storing the third element takes O(n) space at any point.
   * --------------------
   */

  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    int n = nums.size(); // Get array size
    set<vector<int>> st; // To store unique quadruplets

    // Checking all possible quadruplets
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        set<long long> hashset; // To store third element to check for fourth
        for (int k = j + 1; k < n; k++)
        {
          // Calculate the sum of the first three elements
          long long sum = nums[i] + nums[j] + nums[k];
          long long fourth = target - sum; // Calculate the fourth element needed

          // If the fourth element exists in the hashset, it's a valid quadruplet
          if (hashset.find(fourth) != hashset.end())
          {
            vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
            sort(temp.begin(), temp.end()); // Sort to ensure uniqueness
            st.insert(temp);                // Insert into set for uniqueness
          }
          // Put the kth element into the hashset for future checks
          hashset.insert(nums[k]);
        }
      }
    }

    // Convert set to vector to return the result
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
  }
};

/*
 * Approach-3: Using 3 Pointers
 * - First, sort the array to make it easier to avoid duplicates.
 * - Use two loops (i and j) to iterate over the first two elements. For each pair, use two pointers (k and l) to find the other two elements.
 * - The sum of the four elements is calculated, and if it matches the target, add the quadruplet to the answer.
 * - Skip duplicates by checking the current and previous elements in the array.
 * --------------------
 * T.C: O(n^3)
 * - Sorting takes O(n log n), and the two nested loops combined with the two-pointer approach result in O(n^3) time complexity.
 * --------------------
 * S.C: O(n)
 * - The space complexity is O(n) due to the storage required for the result vector.
 */
class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    int n = nums.size(); // Size of the array
    vector<vector<int>> ans;

    // Sort the array to help skip duplicates and use the two-pointer technique
    sort(nums.begin(), nums.end());

    // Loop over the first element (i)
    for (int i = 0; i < n; i++)
    {
      // When we move i forward "Skip duplicate elements for the first element"
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      // Loop over the second element (j)
      for (int j = i + 1; j < n; j++)
      {
        // When we move j forward Skip duplicate elements for the second element
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;

        // Initialize the two pointers (k, l)
        int k = j + 1;
        int l = n - 1;

        // Use two-pointer technique to find pairs
        while (k < l)
        {
          /*
           * To prevent signed integer overflow when summing large numbers, we cast each of the integers
           * (nums[i], nums[j], nums[k], nums[l]) to `long long`. This ensures that the sum can hold
           * larger values that exceed the range of the `int` data type.
           * The maximum value for an int is typically 2^31 - 1 (around 2 billion), while long long can
           * hold much larger values (up to 2^63 - 1), preventing overflow.
           */
          long long sum = nums[i] + nums[j] + nums[k] + nums[l];

          // If the sum matches the target, add the quadruplet
          if (sum == target)
          {
            ans.push_back({nums[i], nums[j], nums[k], nums[l]});
            k++;
            l--;

            // Skip duplicates for the third and fourth elements
            while (k < l && nums[k] == nums[k - 1])
              k++;
            while (k < l && nums[l] == nums[l + 1])
              l--;
          }
          // If sum is less than target, move the left pointer to the right
          else if (sum < target)
          {
            k++;
          }
          // If sum is greater than target, move the right pointer to the left
          else
          {
            l--;
          }
        }
      }
    }

    return ans;
  }
};

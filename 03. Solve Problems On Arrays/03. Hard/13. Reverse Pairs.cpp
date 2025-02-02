#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force)
 * - We iterate through all pairs (i, j) where i < j and check if nums[i] > 2 * nums[j].
 * - This directly counts the number of reverse pairs in the array.
 * - Same as count inversions but witha  slight twist we want the number at 'i' to be 2X to the number at 'j'
 * --------------------
 * T.C: O(n^2)
 * - We use two nested loops to check all pairs, leading to O(n^2) complexity.
 * --------------------
 * S.C: O(1)
 * - No extra space is used apart from input storage.
 */

class Solution
{
public:
  // Function to count reverse pairs in the array
  int reversePairs(vector<int> &nums)
  {

    // Get the size of the array
    int n = nums.size();

    // Initialize the reverse pair count
    int cnt = 0;

    // Traverse all pairs (i, j) where i < j
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {

        // If nums[i] > 2 * nums[j], it's a reverse pair
        if (nums[i] > 2 * nums[j])
          cnt++;
      }
    }

    // Return the total reverse pair count
    return cnt;
  }
};

/*
 * Approach-2: (Merge Sort with Reverse Pair Counting)
 * - We use a modified merge sort algorithm to count the number of reverse pairs efficiently.
 * - Same as that of counti Inversions just we check here for nums[i] > 2X nums[j] the
 * ---------------------------
 * Time Complexity: O(n * log(n))
 * - The merge sort splits the array into halves recursively, and merging the halves takes linear time O(n).
 * - The countPairs function checks each pair within the range for the reverse pair condition (arr[i] > 2 * arr[right]).
 * ---------------------------
 * Space Complexity: O(n)
 * - We use extra space for the temporary array in merge().
 */
class Solution
{
public:
  // Function to merge two sorted halves and count reverse pairs
  void merge(vector<int> &arr, int low, int mid, int high)
  {
    vector<int> temp; // Temporary array to store merged elements
    int left = low, right = mid + 1;

    // Merging elements in sorted order
    while (left <= mid && right <= high)
    {
      if (arr[left] <= arr[right])
      {
        temp.push_back(arr[left++]); // Add smaller element to temp
      }
      else
      {
        temp.push_back(arr[right++]); // Add smaller element to temp
      }
    }

    // If there are remaining elements on the left half
    while (left <= mid)
      temp.push_back(arr[left++]);

    // If there are remaining elements on the right half
    while (right <= high)
      temp.push_back(arr[right++]);

    // Copy merged elements back to original array
    for (int i = low; i <= high; i++)
    {
      arr[i] = temp[i - low];
    }
  }

  // Function to count reverse pairs
  int countPairs(vector<int> &arr, int low, int mid, int high)
  {
    int right = mid + 1, cnt = 0;
    // Iterate over the left half and count reverse pairs
    for (int i = low; i <= mid; i++)
    {
      while (right <= high && arr[i] > 2LL * arr[right])
      {
        right++; // Increment right pointer to find valid pairs
      }
      cnt += (right - (mid + 1)); // Count reverse pairs for each element in the left half
    }
    return cnt;
  }

  // Merge Sort function to count reverse pairs recursively
  int mergeSort(vector<int> &arr, int low, int high)
  {
    if (low >= high)
      return 0; // Base case: single element or empty subarray
    int mid = (low + high) / 2, cnt = 0;

    // Recursively count reverse pairs in the left and right halves
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);

    // Count reverse pairs across the two halves
    cnt += countPairs(arr, low, mid, high);

    // Merge the two sorted halves
    merge(arr, low, mid, high);

    return cnt;
  }

  // Main function to count reverse pairs
  int reversePairs(vector<int> &nums)
  {
    return mergeSort(nums, 0, nums.size() - 1); // Start merge sort from the entire array
  }
};

#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force)
 * - We iterate through all pairs (i, j) where i < j and count how many times arr[i] > arr[j].
 * - This directly counts the number of inversions in the array.
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
  int inversionCount(vector<int> &arr)
  {

    // Get the size of the array
    int n = arr.size();

    // Initialize the inversion count
    int cnt = 0;

    // Traverse all pairs (i, j) where i < j
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        // If arr[i] > arr[j], it's an inversion
        if (arr[i] > arr[j])
          cnt++;
      }
    }

    // Return the total inversion count
    return cnt;
  }
};

/*
 * Approach-2 (Merge Sort)
 * - We use a modified merge sort algorithm to count the number of inversions efficiently.
 * - During merging, if an element from the right half is smaller than an element from the left half,
 *   all remaining elements in the left half form an inversion with it.
 * --------------------
 * T.C: O(n log n)
 * - Merge sort divides the array into halves recursively, leading to a log(n) depth.
 * - Merging takes O(n), so the overall complexity is O(n log n).
 * --------------------
 * S.C: O(n)
 * - We use a temporary array during merging, which takes O(n) extra space.
 */

class Solution
{
public:
  int merge(vector<int> &arr, int low, int mid, int high)
  {
    // Temporary array
    vector<int> temp;

    // Starting index of left half
    int left = low;

    // Starting index of right half
    int right = mid + 1;

    int cnt = 0; // Count of inversions

    // Merging in sorted order while counting inversions
    while (left <= mid && right <= high)
    {
      if (arr[left] <= arr[right])
      {
        temp.push_back(arr[left]);
        left++;
      }
      else
      {
        temp.push_back(arr[right]);
        cnt += (mid - left + 1); // All remaining elements in left half form an inversion
        right++;
      }
    }

    // If elements are left in the left half
    while (left <= mid)
    {
      temp.push_back(arr[left]);
      left++;
    }

    // If elements are left in the right half
    while (right <= high)
    {
      temp.push_back(arr[right]);
      right++;
    }

    // Copy sorted elements back to the original array
    for (int i = low; i <= high; i++)
    {
      arr[i] = temp[i - low];
    }

    // Return the inversion count
    return cnt;
  }

  int mergeSort(vector<int> &arr, int low, int high)
  {
    // Var to store the count of pairs
    int cnt = 0;

    // Base case: when the subarray has one or zero elements, it's already sorted
    if (low >= high)
      return cnt;

    int mid = (low + high) / 2;

    // Count inversions in left half
    cnt += mergeSort(arr, low, mid);

    // Count inversions in right half
    cnt += mergeSort(arr, mid + 1, high);

    // Merge both halves and count split inversions
    cnt += merge(arr, low, mid, high);

    return cnt;
  }

  // Function to count inversions in the array
  int inversionCount(vector<int> &arr)
  {
    return mergeSort(arr, 0, arr.size() - 1);
  }
};

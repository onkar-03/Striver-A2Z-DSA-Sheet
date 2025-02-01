#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force using 2 Pointers with an Extra Array
 * We will use two pointers, left and right, to traverse through nums1 and nums2.
 * A third array (arr3) will be used to merge the elements from nums1 and nums2 in sorted order.
 * Once the merging is done, we will copy the elements back into nums1 and nums2.
 * ----------------------------
 * T.C: O(2 * (m + n)) - The merging process involves a single traversal of both arrays.
 * After the merge, filling the elements back to nums1 and nums2 is also O(m + n).
 * ----------------------------
 * S.C: O(m + n) - We are using an extra array (arr3) to store the merged result.
 */
class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    // Declare a 3rd array and 2 pointers:
    vector<int> arr3(m + n); // This will store the merged result
    int left = 0;
    int right = 0;
    int index = 0;

    // Insert the elements from the 2 arrays into arr3 using left and right pointers:
    while (left < m && right < n)
    {
      if (nums1[left] <= nums2[right])
      {
        arr3[index] = nums1[left];
        left++, index++;
      }
      else
      {
        arr3[index] = nums2[right];
        right++, index++;
      }
    }

    // If left pointer reaches the end of nums1:
    while (left < m)
    {
      arr3[index++] = nums1[left++];
    }

    // If right pointer reaches the end of nums2:
    while (right < n)
    {
      arr3[index++] = nums2[right++];
    }

    // Fill back the elements from arr3[] into nums1:
    for (int i = 0; i < m + n; i++)
    {
      if (i < m)
      {
        nums1[i] = arr3[i];
      }
      else
      {
        nums2[i - m] = arr3[i];
      }
    }
  }
};

/*
 * Approach: Merging two arrays after sorting
 * 1. We use two pointers, one for each array, to swap elements if necessary to ensure that elements from nums1 and nums2 are in the correct order.
 * 2. After the necessary swaps, we individually sort nums1 and nums2 to ensure they are sorted.
 * ----------------------------
 * T.C: O(m * log(m) + n * log(n)) - Sorting both nums1 and nums2 individually.
 * ----------------------------
 * S.C: O(1) - Sorting and merging done in-place, no extra space used except the input arrays.
 */
class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {                   // Declare two pointers: one for the end of nums1 and one for the start of nums2
    int left = m - 1; // Pointer for the last valid element in nums1
    int right = 0;    // Pointer for the first element in nums2

    // Swap elements until arr1[left] is smaller than arr2[right]
    while (left >= 0 && right < n)
    {
      if (nums1[left] > nums2[right])
      {
        swap(nums1[left], nums2[right]);
        left--;
        right++;
      }
      else
      {
        break;
      }
    }

    // Sort nums1 and nums2 individually to ensure both are in non-decreasing order
    sort(nums1.begin(), nums1.begin() + m);
    sort(nums2.begin(), nums2.begin() + n);
  }
};

/*
 * Approach-3: Gap Method for Merging Two Sorted Arrays
 * -------------------------------------------------------
 * 1. We use the gap method to merge two sorted arrays.
 * 2. Initially, the gap is set to half of the total length of the combined arrays.
 * 3. We iterate and compare elements from both arrays by reducing the gap size after each iteration.
 * 4. The idea is to reduce the gap and efficiently merge elements in the right order.
 * 5. We swap the elements where necessary while considering the boundaries of nums1 and nums2.
 * -----------------------------
 * T.C: O((m + n) * log(m + n))
 * - We perform the merging process for each gap iteration.
 * - The total number of iterations is proportional to the logarithm of the combined length (log(m + n)).
 * - In each iteration, we perform comparisons for approximately m + n elements, so the complexity for each iteration is O(m + n).
 * - Hence, the overall complexity is O((m + n) * log(m + n)).
 * -----------------------------
 * S.C: O(1) - We are merging the arrays in place, so no extra space is used except the input arrays.
 * -----------------------------
 */
class Solution
{
public:
  // Function to swap if arr1[ind1] > arr2[ind2]
  void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2)
  {
    if (arr1[ind1] > arr2[ind2])
    {
      swap(arr1[ind1], arr2[ind2]);
    }
  }

  // Function to merge two sorted arrays using gap method
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    // Length of the imaginary combined array:
    int len = m + n;

    // Initial gap calculation:
    int gap = (len / 2) + (len % 2); // Gap size is halved initially and rounded up

    // Perform the gap reduction and merge the arrays:
    while (gap > 0)
    {
      // Place two pointers, left and right, to compare elements in the arrays
      int left = 0;
      int right = left + gap;

      while (right < len)
      {
        // Case 1: left in nums1[] and right in nums2[]
        if (left < m && right >= m)
        {
          swapIfGreater(nums1, nums2, left, right - m);
        }
        // Case 2: both pointers in nums2[]
        else if (left >= m)
        {
          swapIfGreater(nums2, nums2, left - m, right - m);
        }
        // Case 3: both pointers in nums1[]
        else
        {
          swapIfGreater(nums1, nums1, left, right);
        }
        left++, right++;
      }

      // If gap reaches 1, we break the loop after the last iteration
      if (gap == 1)
        break;

      // Otherwise, calculate the new gap:
      // Reduce gap
      gap = (gap / 2) + (gap % 2);
    }
  }
};

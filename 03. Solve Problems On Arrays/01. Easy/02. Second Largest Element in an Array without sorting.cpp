#include <bits/stdc++.h>
using namespace std;

/*
 * Approach:
 * - We first sort the array in non-decreasing order.
 * - The largest element will be at the last index after sorting.
 * - We then iterate backwards from the second last element to find the first element that is not equal to the largest.
 * - This element will be the second largest.
 * ----------------------------
 * Time Complexity (T.C.): O(n log n) where n is the number of elements in the array.
 * - Sorting the array takes O(n log n) time.
 * ----------------------------
 * Space Complexity (S.C.): O(1) if we assume the sort function uses in-place sorting.
 * - We are not using any additional space except for the input array.
 */

class Solution
{
public:
  // Function returns the second largest element
  int getSecondLargest(vector<int> &arr)
  {
    int n = arr.size();

    // Sort the array
    sort(arr.begin(), arr.end());

    int largest = arr[n - 1];

    int i = n - 2;
    // Iterate backwards to find the second largest distinct element
    while (arr[i] == largest)
    {
      i--;
    }

    return arr[i];
  }
};

/*
 * Approach-2: Simple Iterate Twice over Array
 * - First, we iterate through the array to find the largest element.
 * - Then, we iterate again to find the second largest element by ensuring it is not equal to the largest.
 * - If no second largest is found (i.e., all elements are the same), we return -1.
 * ----------------------------
 * Time Complexity (T.C.): 2*O(n) where n is the number of elements in the array.
 * - We perform two linear scans of the array, each taking O(n) time.
 * ----------------------------
 * Space Complexity (S.C.): O(1)
 * - We use only a few extra variables for tracking the largest and second largest elements, so the space complexity is constant.
 * ----------------------------
 */

class Solution
{
public:
  // Function returns the second largest element
  int getSecondLargest(vector<int> &arr)
  {
    int n = arr.size();
    int largest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      if (arr[i] > largest)
      {
        largest = arr[i];
      }
    }

    int secondLargest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] != largest && arr[i] > secondLargest)
      {
        secondLargest = arr[i];
      }
    }
    return secondLargest == INT_MIN ? -1 : secondLargest;
  }
};

/*
 * Approach-3: Single Pass Solution
 * - We initialize `largest` to the first element of the array and `secondLargest` to `INT_MIN`.
 * - We iterate through the array to update `largest` and `secondLargest`.
 * - If the current element is greater than `largest`, we update `secondLargest` to `largest` and `largest` to the current element.
 * - If the current element is smaller than `largest` but greater than `secondLargest`, we update `secondLargest`.
 * - If there is no valid second largest element (i.e., all elements are the same), we return -1.
 * ----------------------------
 * Time Complexity (T.C.): O(n) where n is the number of elements in the array.
 * - We perform a single iteration over the array, which takes O(n) time.
 * ----------------------------
 * Space Complexity (S.C.): O(1)
 * - We use only a constant amount of extra space for the variables `largest` and `secondLargest`.
 * ----------------------------
 */
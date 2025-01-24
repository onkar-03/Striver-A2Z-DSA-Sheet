#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force
 * - We initialize the 'max' variable with the first element of the array.
 * - Then we iterate through the array starting from the first element.
 * - For each element, we compare it with the current 'max'. If the element is greater, we update 'max'.
 * - After the loop finishes, 'max' will hold the largest element in the array.
 * ----------------------------
 * Time Complexity (T.C.): O(n) where n is the number of elements in the array.
 * - We iterate through each element of the array exactly once.
 * ----------------------------
 * Space Complexity (S.C.): O(1).
 * - We use a constant amount of extra space (only a few integer variables).
 */
class Solution
{
public:
  int largest(vector<int> &arr)
  {
    int n = arr.size(); // Get the size of the array
    int max = arr[0];   // Initialize 'max' with the first element of the array

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
      if (arr[i] > max)
      {               // Compare each element with 'max'
        max = arr[i]; // Update 'max' if the current element is larger
      }
    }
    return max; // Return the largest element
  }
};

/*
 * Approach-2: Using Sorting
 * - We sort the array in non-decreasing order using the sort function.
 * - Once the array is sorted, the largest element will be at the last index.
 * - We return the element at the last index of the array.
 *
 * Time Complexity (T.C.): O(n log n) where n is the number of elements in the array.
 * - Sorting the array takes O(n log n) time.
 *
 * Space Complexity (S.C.): O(1) if we assume the sort function uses in-place sorting.
 * - We are not using any additional space except for the input array.
 */

class Solution
{
public:
  int largest(vector<int> &arr)
  {
    // Sort the array
    sort(arr.begin(), arr.end());

    // Return the largest element (last element after sorting)
    return arr[arr.size() - 1];
  }
};

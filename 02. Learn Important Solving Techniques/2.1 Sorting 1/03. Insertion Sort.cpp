#include <bits/stdc++.h>
using namespace std;

/*
 * Insertion Sort Algorithm
 * -------------------------
 * Time Complexity:
 * - Best Case: O(n) [When the array is already sorted]
 * - Average Case: O(n^2)
 * - Worst Case: O(n^2)
 * Explanation: In the worst and average cases, each element is compared and shifted to its correct position within the already sorted portion of the array. This leads to O(n^2) comparisons and swaps.
 * In the best case (sorted array), no shifting is needed, and the algorithm runs in O(n).
 *
 * Space Complexity: O(1)
 * Explanation: Insertion sort is an in-place algorithm that requires no extra space apart from a few variables.
 */

// Function to perform insertion sort
void insertion_sort(int arr[], int n)
{
  // Outer loop iterates over the array
  for (int i = 1; i < n; i++)
  {
    int j = i;

    // Inner loop shifts elements greater than arr[j] to one position ahead
    while (j > 0 && arr[j - 1] > arr[j])
    {
      // Swap the elements to place the current element in the correct position

      // Method 1:
      // int temp = arr[j - 1];
      // arr[j - 1] = arr[j];
      // arr[j] = temp;

      // Method 2:
      swap(arr[j], arr[j - 1]);

      // Decrement the position of j
      j--;
    }
  }

  // Print the sorted array
  cout << "After Using Insertion Sort: " << "\n";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main()
{
  // Input array
  int arr[] = {13, 46, 24, 52, 20, 9};
  int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

  // Print the array before sorting
  cout << "Before Using Insertion Sort: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Perform insertion sort
  insertion_sort(arr, n);
  return 0;
}

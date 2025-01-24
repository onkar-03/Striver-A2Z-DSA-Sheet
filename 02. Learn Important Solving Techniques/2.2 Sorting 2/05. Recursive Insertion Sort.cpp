#include <bits/stdc++.h>
using namespace std;

/*
 * Recursive Insertion Sort Algorithm
 * -------------------------
 * Time Complexity:
 * - Best Case: O(n) [When the array is already sorted]
 * - Average Case: O(n^2)
 * - Worst Case: O(n^2)
 * Explanation: In the worst and average cases, each element is compared and shifted to its correct position within the already sorted portion of the array.
 * ---------------------
 * Space Complexity: O(n) [Due to the recursive call stack]
 */

// Recursive function to perform insertion sort
void recursive_insertion_sort(int arr[], int n)
{
  // Base case: If the array size is 1 or less, it is already sorted
  if (n <= 1)
    return;

  // Sort the first (n-1) elements
  recursive_insertion_sort(arr, n - 1);

  // Insert the nth element at its correct position in the sorted portion
  int last = arr[n - 1]; // The last element to be placed
  int j = n - 2;         // Pointer to compare elements from the sorted portion

  // Shift elements of the sorted portion to the right to make space for `last`
  while (j >= 0 && arr[j] > last)
  {
    // Move the larger element one position to the right
    arr[j + 1] = arr[j];

    // Decrement the pointer
    j--;
  }

  // Place the `last` element in its correct position
  arr[j + 1] = last;
}

int main()
{
  // Input array to be sorted
  int arr[] = {13, 46, 24, 52, 20, 9};

  // Calculate the size of the array
  int n = sizeof(arr) / sizeof(arr[0]);

  // Print the array before sorting
  cout << "Before Using Insertion Sort: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
    // Display each element
  }
  cout << endl;

  // Call the recursive insertion sort function
  recursive_insertion_sort(arr, n);

  // Print the sorted array
  cout << "After Using Insertion Sort: " << "\n";
  for (int i = 0; i < n; i++)
  {
    // Display each sorted element
    cout << arr[i] << " ";
  }
  cout << "\n";

  return 0; // Indicate successful program termination
}

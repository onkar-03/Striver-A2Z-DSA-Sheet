#include <bits/stdc++.h>
using namespace std;

/*
 * Selection Sort Algorithm
 * - Pushes the Minimum Element to the Start of the Array
 * ------------------------
 * Time Complexity:
 * - Best Case: O(n^2)
 * - Average Case: O(n^2)
 * - Worst Case: O(n^2)
 * Explanation: The algorithm always runs two nested loops regardless of the input, resulting in O(n^2).
 * ---------------------
 * Space Complexity: O(1)
 * Explanation: The algorithm is in-place and does not require any extra space apart from a few variables.
 */

// Recursive function to perform selection sort
void recursive_selection_sort(int arr[], int n, int start)
{
  // Base case: If the start index reaches the end, stop recursion
  if (start >= n - 1)
    return;

  // Find the index of the minimum element in the unsorted portion
  int mini = start;

  // Search for the minimum element in the unsorted portion
  for (int j = start + 1; j < n; j++)
  {
    if (arr[j] < arr[mini])
    { // Update if a smaller element is found
      mini = j;
    }
  }

  // Swap the minimum element with the first element of the unsorted portion
  swap(arr[start], arr[mini]);

  // Recursive call to sort the remaining unsorted portion
  recursive_selection_sort(arr, n, start + 1);
}

int main()
{
  // Input array
  int arr[] = {13, 46, 24, 52, 20, 9};
  int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

  // Print the array before sorting
  cout << "Before selection sort: " << "\n";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Perform recursive selection sort
  recursive_selection_sort(arr, n, 0);

  // Print the sorted array
  cout << "After selection sort: " << "\n";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n";

  return 0;
}

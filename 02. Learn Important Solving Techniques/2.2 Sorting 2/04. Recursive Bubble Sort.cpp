#include <bits/stdc++.h>
using namespace std;

/*
 * Recursive Bubble Sort Algorithm
 * - Sorts the array by recursively pushing the largest element to the end in each call.
 * ---------------------
 * Time Complexity:
 * - Best Case: O(n) [When the array is already sorted]
 * - Average Case: O(n^2)
 * - Worst Case: O(n^2)
 * Explanation: The algorithm compares adjacent elements recursively until the array is sorted.
 * ---------------------
 * Space Complexity: O(n) [Due to recursive call stack]
 */

// Function to perform recursive bubble sort
void recursive_bubble_sort(int arr[], int n)
{
  // Base case: If the size of the array is 1 or less, it is already sorted.
  if (n == 1)
    return;

  // Variable to track if any swaps are made in this pass
  bool swapped = false;

  // Loop through the array to compare adjacent elements
  { // Loop until the second last element
    for (int i = 0; i < n - 1; i++)
      // Check if the current element is greater than the next
      if (arr[i] > arr[i + 1])
      {
        // Swap the two elements to put them in the correct order
        swap(arr[i], arr[i + 1]);

        // Mark that a swap occurred
        swapped = true;
      }
  }

  // If no swaps were made in this pass, the array is already sorted
  if (!swapped)
    return;

  // Recursively call the function to sort the remaining unsorted portion
  // Reduces the size of the array being processed (n-1) in each step
  recursive_bubble_sort(arr, n - 1);
}

int main()
{
  // Input array to be sorted
  int arr[] = {13, 46, 24, 52, 20, 9};
  // Calculate the size of the array
  int n = sizeof(arr) / sizeof(arr[0]);

  // Print the array before sorting
  cout << "Before Using Bubble Sort: " << endl; // Message for clarity
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " "; // Display each element of the array
  }
  cout << endl;

  // Call the recursive bubble sort function to sort the array
  recursive_bubble_sort(arr, n);

  // Print the sorted array
  cout << "After Using Bubble Sort: " << "\n"; // Message for clarity
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " "; // Display each sorted element of the array
  }
  cout << "\n";

  return 0; // Indicate successful program termination
}

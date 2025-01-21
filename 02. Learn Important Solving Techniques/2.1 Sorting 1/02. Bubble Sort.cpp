#include <bits/stdc++.h>
using namespace std;

/*
 * Bubble Sort Algorithm
 * - Pushes the Maximum Element to the end of the Array
 * ---------------------
 * Time Complexity:
 * - Best Case: O(n) [When the array is already sorted]
 * - Average Case: O(n^2)
 * - Worst Case: O(n^2)
 * Explanation: In the worst case, the algorithm compares and swaps every adjacent pair in every pass, leading to O(n^2) complexity.
 *
 * Space Complexity: O(1)
 * Explanation: Bubble sort is an in-place algorithm that requires no extra space apart from a few variables.
 */

// Function to perform bubble sort
void bubble_sort(int arr[], int n)
{
  // Outer loop iterates over the unsorted portion of the array
  for (int i = n - 1; i >= 0; i--)
  {
    // Inner loop compares adjacent elements
    for (int j = 0; j <= i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // Swap if the current element is greater than the next

        // Method 1:
        // int temp = arr[j + 1];
        // arr[j + 1] = arr[j];
        // arr[j] = temp;

        // Method 2:
        swap(arr[j], arr[j + 1]);
      }
    }
  }

  // Print the sorted array
  cout << "After Using Bubble Sort: " << "\n";
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
  cout << "Before Using Bubble Sort: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Perform bubble sort
  bubble_sort(arr, n);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
 * Merge Sort Algorithm
 * - We Study this as it performs better than Bubble, Selection, Insetion sort algorithm
 * - Works on Divide & Conquer Principle
 * ---------------------
 * Time Complexity:
 * - Best Case: O(n log n) [Merge sort works efficiently even if the array is already sorted]
 * - Average Case: O(n log n)
 * - Worst Case: O(n log n)
 * Explanation: Merge sort divides the array into two halves recursively and then merges them in sorted order. The merging process takes linear time O(n) and since we divide the array in half at each step, the overall time complexity is O(n log n) in all cases.
 *
 * Space Complexity: O(n)
 * Explanation: Merge sort requires additional space for the temporary array used in the merging process. Thus, the space complexity is O(n).
 */

#include <bits/stdc++.h>
using namespace std;

// Function to merge two sorted halves of the array
void merge(vector<int> &arr, int low, int mid, int high)
{
  // Temporary array to store merged elements
  vector<int> temp;

  // Starting index of the left half of the array
  int left = low;

  // Starting index of the right half of the array
  int right = mid + 1;

  // Merging the elements from the left and right halves into the temporary array in sorted order
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
      right++;
    }
  }

  // If there are remaining elements in the left half, add them to the temporary array
  while (left <= mid)
  {
    temp.push_back(arr[left]);
    left++;
  }

  // If there are remaining elements in the right half, add them to the temporary array
  while (right <= high)
  {
    temp.push_back(arr[right]);
    right++;
  }

  // Transfer the merged elements from the temporary array back to the original array
  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}

// Function to recursively perform merge sort
void mergeSort(vector<int> &arr, int low, int high)
{
  // Base case: when the subarray has one or zero elements, it's already sorted
  if (low >= high)
    return;

  int mid = low + (high - low) / 2; // Find the middle index

  // Sort the left half
  mergeSort(arr, low, mid);

  // Sort the right half
  mergeSort(arr, mid + 1, high);

  // Merge the sorted halves
  merge(arr, low, mid, high);
}

int main()
{

  vector<int> arr = {9, 4, 7, 6, 3, 1, 5}; // Input array
  int n = 7;                               // Size of the array

  // Print the array before sorting
  cout << "Before Sorting Array: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Perform merge sort on the array
  mergeSort(arr, 0, n - 1);

  // Print the array after sorting
  cout << "After Sorting Array: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

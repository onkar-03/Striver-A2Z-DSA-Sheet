#include <bits/stdc++.h>
using namespace std;

/*
 * Quick Sort Algorithm
 * ---------------------
 * Time Complexity:
 * - Best Case: O(n log n) [When the pivot divides the array into nearly equal halves]
 * - Average Case: O(n log n)
 * - Worst Case: O(n^2) [When the pivot is the smallest or largest element, leading to an imbalanced division]
 * Explanation of O(n log n):
 * - The 'n' factor comes from the fact that, at each partition step, all 'n' elements are compared to the pivot.
 * - The 'log n' factor comes from the number of levels of recursion, as the array is repeatedly divided into halves.
 * - Together, 'n log n' reflects the total work done across all levels of recursion.
 * ---------------------
 * Space Complexity: O(log n)
 * Explanation: Quick Sort is an in-place algorithm. However, it uses recursive function calls, which require stack space proportional to the height of the recursion tree. The height is O(log n) in the best case and O(n) in the worst case.
 *
 * Why Quick Sort?
 * Quick Sort is preferred over algorithms like Bubble Sort, Selection Sort, and Insertion Sort because it has a better average time complexity (O(n log n)). It often outperforms Merge Sort in practice due to lower constant factors and no additional space for merging.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to partition the array based on the pivot element
int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[low]; // Choose the first element as the pivot
  int i = low;          // Initialize the pointer for the left side (elements smaller than or equal to pivot)
  int j = high;         // Initialize the pointer for the right side (elements greater than pivot)

  // Rearrange elements around the pivot
  while (i < j)
  {
    // Find an element greater than the pivot on the Left & Right Side

    // Increment the pointer `i` until we find an element greater than the pivot on the Left Side
    while (arr[i] <= pivot && i <= high - 1)
    {
      i++;
    }

    // Decrement the pointer `j` until we find an element smaller than or equal to the pivot on the Right Side
    while (arr[j] > pivot && j >= low + 1)
    {
      j--;
    }

    // If pointers `i` and `j` have not crossed, swap the elements at `i` and `j`
    if (i < j)
    {
      swap(arr[i], arr[j]);
    }
  }

  // At this point, all elements smaller than or equal to the pivot are on the left, and all elements greater than the pivot are on the right.
  // Place the pivot element in its correct sorted position by swapping it with the element at `j`.
  swap(arr[low], arr[j]);

  // Return the index of the pivot, now correctly placed in the sorted array
  return j;
}

// Recursive function to implement Quick Sort
void qs(vector<int> &arr, int low, int high)
{
  // Only when three are more than 1 elements in the Array we perform the Operation as a Single element is already sorted
  if (low < high)
  {
    // Partition the array
    int pIndex = partition(arr, low, high);

    // Sort the left half
    qs(arr, low, pIndex - 1);

    // Sort the right half
    qs(arr, pIndex + 1, high);
  }
}

// Wrapper function for Quick Sort
vector<int> quickSort(vector<int> arr)
{
  // Call the recursive Quick Sort function
  qs(arr, 0, arr.size() - 1);

  // Return the sorted array
  return arr;
}

int main()
{
  vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3}; // Input array
  int n = arr.size();                         // Size of the array

  // Print the array before sorting
  cout << "Before Using Quick Sort: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Perform Quick Sort
  arr = quickSort(arr);

  // Print the array after sorting
  cout << "After Using Quick Sort: " << "\n";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n";

  return 0;
}

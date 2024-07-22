#include <bits/stdc++.h>
using namespace std;

void reverseArray(int i, int arr[], int size)
{
  // Base case: if the index `i` is greater than or equal to half of the array size, stop recursion
  if (i >= size / 2)
    return;

  // Swap the element at index `i` with the element at index `size - i - 1`
  swap(arr[i], arr[size - i - 1]);

  // Recursively call `reverseArray` with the next index
  reverseArray(i + 1, arr, size);

  // Time Complexity: [O(N)]
}

int main()
{
  // Variable to store the size of the array
  int size;

  // Prompt the user to enter the size of the array
  cout << "Enter the Size of Array: ";
  cin >> size; // Read the size of the array from user input

  // Declare an array of size `size`
  int arr[size];

  // Prompt the user to enter the elements of the array
  cout << "Enter Elements of Array: " << endl;

  // Loop to read elements into the array
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i]; // Read each element from user input and store it in the array
  }

  // Print the original array
  cout << "Original Array: ";
  for (int i = 0; i < size; i++)
  {
    // Output each element of the array
    cout << arr[i] << " ";
  }

  // Print a newline character for better readability
  cout << endl;

  // Call the `reverseArray` function to reverse the array
  reverseArray(0, arr, size);

  // Print the reversed array
  cout << "Reversed Array: ";
  for (int i = 0; i < size; i++)
  {
    // Output each element of the reversed array
    cout << arr[i] << " ";
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{

  int maxEl;
  cout << "Enter the Maximum Element Array can have ?? ";
  cin >> maxEl;

  // Variable to store the size of the array
  int size;
  cout << "Enter the size of the Array: ";
  cin >> size;

  // Initialize the array to hold the elements
  int arr[size];
  cout << "Enter Array Elements: " << endl;

  // Loop to take input for each element of the array
  for (int i = 0; i < size; i++)
  {
    // Read each element into the array
    cin >> arr[i];
  }

  ////////////////////////////////////////////////////////////////////////////
  // Hashing Array
  // Create a hash table (array) to store the frequency of each element
  int hash[maxEl + 1] = {0}; // Initialize all elements to 0

  // Loop over Array to compute the frequency of each element in the array
  for (int i = 0; i < size; i++)
  {
    // Increment the count of the current element in the hash table
    hash[arr[i]] += 1;
  }

  ////////////////////////////////////////////////////////////////////////////
  // Variable to store the number of queries
  int q;
  cout << "Enter the number of Elements you want to Search: ";
  cin >> q;

  // Loop to process each query
  // q-- stays true until q > 0
  while (q--)
  {
    // Variable to store the number for which frequency is to be found
    int number;
    cout << "Enter the Number to Find its Frequency: ";
    cin >> number;

    // Output the frequency of the given number from the hash table
    cout << number << " appears " << hash[number] << " times in the Array !!" << endl;
  }
  return 0;
}
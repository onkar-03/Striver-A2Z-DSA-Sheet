#include <bits/stdc++.h>
using namespace std;
int main()
{

  // Array Size
  int size;
  cout << "Enter the size of the Array: ";
  cin >> size;

  // Initialize the array to hold the elements
  int arr[size];

  cout << "Enter Array Elements: " << endl;
  for (int i = 0; i < size; i++)
  {
    // Read each element into the array
    cin >> arr[i];
  }

  // Mapping using Map STL
  map<int, int> mpp;

  // Map: Stores Key,Value Pair
  // Here key = Number
  // Value = Frequency

  for (int i = 0; i < size; i++)
  {
    // Increment the Frequency counter of Array Elements on the Map
    mpp[arr[i]]++;
  }

  // Taking in Number of Elements we want to check
  int number;
  cout << "Specify how many numbers you want to check the frequency for: " << endl;
  cin >> number;

  while (number--)
  {
    int n;
    cout << "Enter the Number:" << endl;
    cin >> n;

    // Check if the number is present in the Map
    // mpp.find() return mpp.end() if no element found
    if (mpp.find(n) != mpp.end())
    {
      cout << "Frequency of " << n << " is: " << mpp[n] << endl;
    }
    else
    {
      cout << "Number not found in the Array." << endl;
    }
  }
  return 0;
}
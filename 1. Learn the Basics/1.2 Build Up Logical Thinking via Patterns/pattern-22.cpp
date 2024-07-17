#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number of Rows: " << endl;
  cin >> n;

  // Loop through rows
  for (int i = 0; i < 2 * n - 1; i++)
  {
    // Loop through columns
    for (int j = 0; j < 2 * n - 1; j++)
    {
      // Calculate the distances to the nearest edge
      int top = i;                  // Distance from the top edge
      int bottom = (2 * n - 2) - i; // Distance from the bottom edge
      int left = j;                 // Distance from the left edge
      int right = (2 * n - 2) - j;  // Distance from the right edge

      // Find the minimum distance to any edge and calculate the value to print
      int minDistance = min(min(left, right), min(top, bottom));
      cout << (n - minDistance);
    }
    // Move to the next line after printing all columns for the current row
    cout << endl;
  }

  return 0;
}

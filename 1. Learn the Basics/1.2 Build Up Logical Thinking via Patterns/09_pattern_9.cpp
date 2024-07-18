#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number of Rows: " << endl;
  cin >> n;

  // Upper Half
  // 2 Inner Loops Solution
  // Rows
  for (int i = 0; i < n; i++)
  {
    // Columns
    // 1. Forward Spaces
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    // 2. Stars
    for (int j = 0; j < 2 * i + 1; j++)
    {
      cout << "*";
    }
    cout << endl;
  }

  // Bottom Half
  // Rows
  for (int i = 0; i < n; i++)
  {
    // Columns
    // 1. Forward Spaces
    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }
    // 2. Stars
    for (int j = 0; j < (2 * n) - (2 * i + 1); j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

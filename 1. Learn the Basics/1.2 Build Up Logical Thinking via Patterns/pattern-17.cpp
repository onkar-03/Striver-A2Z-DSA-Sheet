#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number of Rows: ";
  cin >> n;

  // Loop through rows
  for (int i = 0; i < n; i++)
  {
    // Print leading spaces
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    // Print characters
    char ch = 'A'; // Start with 'A'

    // Calculate the breakpoint where characters start decreasing
    int breakpoint = ((2 * i) + 1) / 2;

    // Loop to print characters for the current row
    for (int j = 0; j < 2 * i + 1; j++)
    {
      cout << ch;

      // Adjust character 'ch' based on the position in the row
      if (j < breakpoint)
      {
        ch++; // Increment character
      }
      else
      {
        ch--; // Decrement character
      }
    }
    // Move to the next line after printing characters for the row
    cout << endl;
  }

  return 0;
}

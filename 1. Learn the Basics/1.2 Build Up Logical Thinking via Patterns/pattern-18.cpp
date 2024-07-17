#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number of Rows: " << endl;
  cin >> n;

  // Loop through rows
  for (int i = 0; i < n; i++)
  {
    // Initialize character starting from 'A' + n - 1 for each row
    char c = 'A' + n - 1;

    // Loop to print characters for the current row
    for (int j = 0; j <= i; j++)
    {
      // Print current character followed by a space
      cout << c << " ";

      // Decrement character for the next iteration
      c--;
    }
    // Move to the next line after printing characters for the row
    cout << endl;
  }

  return 0;
}

#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number of Rows: " << endl;
  cin >> n;

  // Initial Character
  char ch = 'A';

  // Rows
  for (int i = 0; i < n; i++)
  {
    // Columns
    for (int j = 0; j < i + 1; j++)
    {
      cout << ch;
    }
    ch++; // Increment 'ch' for the next row
    cout << endl;
  }
  return 0;
}

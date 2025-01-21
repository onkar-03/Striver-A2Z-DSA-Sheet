#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number of Rows: " << endl;
  cin >> n;

  // --- Left Side
  // Rows
  for (int i = 0; i < n; i++)
  {
    // Numbers
    for (int j = 0; j < i + 1; j++)
    {
      cout << j + 1;
    }

    // --- Right Side
    // Spaces
    for (int j = 0; j < (2 * (n - 1)) - 2 * i; j++)
    {
      cout << " ";
    }
    // Numbers
    for (int j = i; j >= 0; j--)
    {
      cout << j + 1;
    }
    cout << endl;
  }
  return 0;
}

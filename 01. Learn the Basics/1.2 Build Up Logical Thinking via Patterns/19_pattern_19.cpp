#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number of Rows: " << endl;
  cin >> n;
  // Rows
  // - Top Section
  for (int i = 0; i < n; i++)
  {
    // Left Side
    for (int j = 0; j <= n - i - 1; j++)
    {
      cout << "*";
    }
    // Spaces
    for (int j = 0; j < 2 * i; j++)
    {
      cout << " ";
    }

    // Right Side
    for (int j = 0; j <= n - i - 1; j++)
    {
      cout << "*";
    }
    cout << endl;
  }

  // --- Lower Half
  for (int i = 0; i < n; i++)
  {
    // Left Side
    for (int j = 0; j < i + 1; j++)
    {
      cout << "*";
    }
    // Spaces
    for (int j = 0; j < (2 * n) - 2 * i - 2; j++)
    {
      cout << " ";
    }

    // Right Side
    for (int j = 0; j < i + 1; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}

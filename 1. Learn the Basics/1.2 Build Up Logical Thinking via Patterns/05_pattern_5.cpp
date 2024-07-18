#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number of Rows: " << endl;
  cin >> n;

  // --- Method 1
  // Rows
  for (int i = 0; i < n; i++)
  {
    // Columns
    for (int j = 0; j <= n - i - 1; j++)
    {
      cout << "*";
    }
    cout << endl;
  }

  // --- Method 2
  // Rows
  // for (int i = n; i > 0; i--)
  // {
  //   // Columns
  //   for (int j = i; j > 0; j--)
  //   {
  //     cout << "*";
  //   }
  //   cout << endl;
  // }

  return 0;
}

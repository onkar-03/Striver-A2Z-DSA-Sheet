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
      cout << j + 1;
    }
    cout << endl;
  }
  return 0;
}

#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number of Rows: " << endl;
  cin >> n;
  // Rows
  for (int i = 0; i < n; i++)
  {
    // Columns
    for (int j = 0; j < i + 1; j++)
    {
      // Print Condition for 1 & 0
      if (i == j || (i + j) % 2 == 0)
      {
        cout << 1 << " ";
      }
      else
      {
        cout << 0 << " ";
      }
    }
    cout << endl;
  }
  return 0;
}

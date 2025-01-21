#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number of Rows: " << endl;
  cin >> n;

  int current = 1;

  // Rows
  for (int i = 0; i < n; i++)
  {
    // Columns
    for (int j = 0; j < i + 1; j++)
    {
      cout << current++ << " ";
    }
    cout << endl;
  }
  return 0;
}

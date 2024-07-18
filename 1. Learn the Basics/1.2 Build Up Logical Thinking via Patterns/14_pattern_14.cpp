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
    char ch = 'A';
    // Columns
    for (int j = 0; j < i + 1; j++)
    {
      cout << ch++ << " ";
    }
    cout << endl;
  }
  return 0;
}

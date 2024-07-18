#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number of Rows: " << endl;
  cin >> n;
  // Rows
  for (int i = 0; i < 2 * n - 1; i++)
  {
    // Upper Half
    int stars = i + 1;

    // Lower Half Condition
    if (i > n - 1)
    {
      stars = (2 * n) - i - 1;
    }
    for (int j = 0; j < stars; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}

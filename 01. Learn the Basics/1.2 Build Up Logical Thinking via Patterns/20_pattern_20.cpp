#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number of Rows: ";
  cin >> n;
  // Rows
  for (int i = 0; i < 2 * n - 1; i++)
  {
    // --- Left Side Stars
    // Upper Half Condition
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

    // --- Spaces
    int spaces = 2 * n - 2 * i - 2;

    if (i > n - 1)
    {
      spaces = (2 * i) - (2 * n) + 2;
    }
    for (int j = 0; j < spaces; j++)
    {
      cout << " ";
    }

    //--- Right Side Stars
    // Upper Half Condition
    stars = i + 1;

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

#include <bits/stdc++.h>
using namespace std;
int main()
{

  string str;
  cout << "Enter the String: ";
  cin >> str;

  // Mapping using Map STL
  map<char, int> mpp;

  // Map: Stores Key,Value Pair
  // Here key = Character
  // Value = Frequency

  for (int i = 0; i < str.size(); i++)
  {
    // Increment the Frequency counter of Character in Map
    mpp[str[i]]++;
  }

  // Taking in Number of Elements we want to check
  int number;
  cout << "Specify how many characters you want to check the frequency of: " << endl;
  cin >> number;

  while (number--)
  {
    char ch;
    cout << "Enter the Character:" << endl;
    cin >> ch;

    // Check if the number is present in the Map
    // mpp.find() return mpp.end() if no element found
    if (mpp.find(ch) != mpp.end())
    {
      cout << "Frequency of " << ch << " is: " << mpp[ch] << endl;
    }
    else
    {
      cout << "Character not found in the String." << endl;
    }
  }
  return 0;
}
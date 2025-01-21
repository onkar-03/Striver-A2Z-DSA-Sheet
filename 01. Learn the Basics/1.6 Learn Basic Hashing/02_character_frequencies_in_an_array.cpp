#include <bits/stdc++.h>
using namespace std;
int main()
{
  string str;
  cout << "Enter the String: ";
  cin >> str;

  // Hashing
  // As there are 256 characters in total hence map all that comes in the String
  int hash[256] = {0};

  for (int i = 0; i < str.length(); i++)
  {
    // hash[str[i] - 'a'] += 1;
    hash[str[i]] += 1;
  }

  // Variable to store the number of queries
  int q;

  // Prompt user to enter the number of queries
  cout << "Enter the characters you want to search for: ";
  cin >> q;

  // Loop to process each query
  // Continue until all queries are processed
  while (q > 0)
  {
    // Variable to store the character to be found
    char ch;

    // Prompt user to enter character to search
    cout << "Enter the Character: ";
    cin >> ch;

    // Output the frequency of the given chr from the hash table
    // cout << ch << " appears " << hash[ch - 'a'] << " times in the Array !!" << endl;
    cout << ch << " appears " << hash[ch] << " times in the Array !!" << endl;

    // Decrement the query count
    q--;
  }

  return 0;
}
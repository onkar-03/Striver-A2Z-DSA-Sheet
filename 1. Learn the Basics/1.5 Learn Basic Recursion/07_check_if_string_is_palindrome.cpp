#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, string str)
{
  // Get the length of the string
  int size = str.length();

  // Base case: if the index `i` has reached or exceeded half of the string length, the string is a palindrome
  if (i >= size / 2)
    return true;

  // Check if the characters at the `i`-th position and the symmetric position from the end are equal
  if (str[i] != str[size - i - 1])
    // If they are not equal, the string is not a palindrome
    return false;

  // Recursive case: check the next pair of characters
  return isPalindrome(i + 1, str);
}

int main()
{
  // Variable to store the string to be checked
  string check;

  // Prompt the user to enter the string
  cout << "Enter the String: ";

  // Read the string from user input
  cin >> check;

  // Call the `isPalindrome` function to check if the string is a palindrome
  if (isPalindrome(0, check))
  {
    // Output if the string is a palindrome
    cout << "The String is a palindrome !!" << endl;
  }
  else
  {
    // Output if the string is not a palindrome
    cout << "The String is not a palindrome !!" << endl;
  }
  return 0;
}
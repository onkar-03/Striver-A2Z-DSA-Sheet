#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, string str)
{
  // Get the length of the string
  int size = str.length();

  // Base case: if the index `i` has reached or exceeded half of the string length, the string is a palindrome
  if (i >= size / 2)
    return true;

  // Skip non-alphanumeric characters from the start
  if (!isalnum(str[i]))
  {
    return isPalindrome(i + 1, str);
  }

  // Skip non-alphanumeric characters from the end
  if (!isalnum(str[size - i - 1]))
  {
    return isPalindrome(i, str.substr(0, size - i - 1) + str.substr(size - i, size));

    // str.substr(start, length) involves copying parts of the string, which is O(N), where N is the length of the substring.
    // Each substring operation involves copying up to N characters in the worst case
    // Time Complexity: [O(N)]
  }

  // Check if the characters at the `i`-th position and the symmetric position from the end are equal
  // Using tolower() to avoid case sensitive comparison issues
  if (tolower(str[i]) != tolower(str[size - i - 1]))
    // If they are not equal, the string is not a palindrome
    return false;

  // Recursive case: check the next pair of characters
  return isPalindrome(i + 1, str); // Time Complexity: [O(N)]

  //  Total Time Complexity:
  // For each call where a substring is created, it can cost up to O(N) in string operations
  // Since there are up to O(N) such calls (one for each character in the string), and each call involves an O(N) substring operation, the cumulative cost becomes [O(N^2)]
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
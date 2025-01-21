#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindromeNumber(int number)
{
  int originalNumber = number;
  int reverse = 0;

  // Loop to reverse the digits of the number
  while (originalNumber != 0)
  {
    int digit = originalNumber % 10; // Get the last digit of the original number
    reverse = reverse * 10 + digit;  // Append the digit to the reversed number
    originalNumber /= 10;            // Remove the last digit from the original number
  }

  // Check if the original number is equal to its reversed version
  return (number == reverse);

  // Time Complexity: O(log10(N))
}

// Main function to execute the program
int main()
{
  int number;
  cout << "Enter the Number: ";
  cin >> number; // Input the number from the user

  // Check if the number is a palindrome and display the result
  if (isPalindromeNumber(number))
    cout << "Number is a Palindrome!" << endl;
  else
    cout << "Number is not a Palindrome!" << endl;

  return 0;
}

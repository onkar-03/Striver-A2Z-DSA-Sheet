#include <bits/stdc++.h>
using namespace std;

// Function to reverse the digits of a given number
int ReverseNumber(int number)
{
  // Variable to store the reversed number
  int reverse = 0;

  // Loop to reverse the digits of the number
  while (number != 0)
  {
    int digit = number % 10; // Get the last digit of the number
    number /= 10;            // Remove the last digit from the number

    // Check for potential overflow or underflow before updating reverse
    // Checks for potential Overflow/Underflow conditions during each iteration of the reversal process, before actually updating the reverse variable
    if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && digit > INT_MAX % 10))
    {
      return 0; // Return 0 if overflow is detected
    }
    if (reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && digit < INT_MIN % 10))
    {
      return 0; // Return 0 if underflow is detected
    }

    // Append the digit to the reversed number
    reverse = reverse * 10 + digit;
  }

  // Return the reversed number
  return reverse;

  // Time Complexity: O(log(N))
}

// Main function to execute the program
int main()
{
  int number;
  // Prompt the user to enter a number
  cout << "Enter the Number: ";
  cin >> number;

  // Reverse the number
  int reverse = ReverseNumber(number);

  // Print the reversed number
  cout << "Reversed Number for " << number << ": " << reverse << endl;

  return 0;
}

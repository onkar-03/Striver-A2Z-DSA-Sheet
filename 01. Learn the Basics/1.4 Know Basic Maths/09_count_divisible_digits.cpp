#include <bits/stdc++.h>
using namespace std;

// Question: Given a number n. Count the number of digits in n which evenly divide n. Return an integer, total number of digits of n which divides n evenly.

// Note: Evenly divides means whether n is divisible by a digit i.e. leaves a remainder 0 when divided.

// Method 1: Counting digits using loop
void countDivisibleDigits(int number)
{
  int count = 0; // Initialize count of divisible digits to zero

  // Loop through each digit of the number
  while (number != 0)
  {
    int digit = number % 10; // Get the last digit of N

    // Check if the digit is not zero and divides the original number evenly
    if (digit != 0 && number % digit == 0)
    {
      count++; // Increment count if digit divides original number evenly
    }
    number = number / 10; // Remove the last digit from N
  }

  // Output the result
  cout << "Number of Digits that Completely Divide " << number << ": " << count;
}

// Method 2: Using logarithm to count digits
void countDivisibleDigitsUsingLog(int number)
{
  int count = (int)log10(number) + 1; // Calculate the number of digits in the number

  // Output the result
  cout << "Number of Digits that Completely Divide " << number << " are: " << count;
}

int main()
{
  int number;
  cout << "Enter the Number: ";
  cin >> number; // Input the number from the user

  // Method 1: Uncomment to use Method 1
  // countDivisibleDigits(number);

  // Method 2: Uncomment to use Method 2
  countDivisibleDigitsUsingLog(number);

  return 0;
}

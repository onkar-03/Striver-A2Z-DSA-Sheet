#include <bits/stdc++.h>
using namespace std;

// Function to count the number of digits in a given number
int countDigits(int number)
{
  int count = 0;

  // Loop until number becomes 0
  while (number > 0)
  {
    int digit = number % 10; // Get the last digit of the number
    count++;                 // Increment count for each digit
    number /= 10;            // Remove the last digit from the number
  }
  return count; // Return the total count of digits
}

int main()
{
  int number;
  cout << "Enter the Number: ";
  cin >> number; // Input the number from the user

  // Count the total number of digits in the number
  int digits = countDigits(number);
  cout << "Number of Digits in " << number << " are: " << digits << endl;
  return 0;
}
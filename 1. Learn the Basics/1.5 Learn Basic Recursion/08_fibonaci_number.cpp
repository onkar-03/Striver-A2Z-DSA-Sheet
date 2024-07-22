#include <bits/stdc++.h>
using namespace std;

// Function to Print the Fibonacci Number
int fib(int number)
{
  // Base case: if the number is 0 or 1, return it as the Fibonacci number
  if (number <= 1)
  {
    return number;
  }

  // Recursive case: return the sum of the previous two Fibonacci numbers
  return fib(number - 1) + fib(number - 2);
}

int main()
{
  // Variable to store the position in the Fibonacci sequence
  int number;

  // Prompt the user to enter the position in the Fibonacci sequence
  cout << "Enter the Number: ";

  // Read the position from user input
  cin >> number;

  // Call the `fib` function to calculate the Fibonacci number at the given position
  int ans = fib(number);

  // Output the Fibonacci number at the given position
  cout << "The number at " << number << " in Fibonacci Series is: " << ans;

  return 0;
}
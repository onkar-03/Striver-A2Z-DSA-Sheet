#include <bits/stdc++.h>
using namespace std;

// Function to calculate the factorial of a number using recursion
int factorialN(int number)
{
  // Base case: if the number is 1, return 1
  if (number == 1)
    return 1;

  // Recursive call: multiply the current number by the factorial of (number - 1)
  return number * factorialN(number - 1);

  // Time Complexity: [O(N)]
}

int main()
{
  // Declare an integer variable to store the user input
  int number;

  // Prompt the user to enter a number
  cout << "Enter the Number: ";

  // Read the number input from the user and store it in the 'number' variable
  cin >> number;

  // Call the factorialN function with the provided number and store the result in 'factorial'
  int factorial = factorialN(number);

  // Print the factorial result
  cout << "Factorial of " << number << " is: " << factorial << endl;

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the sum of the first 'number' natural numbers
int sumN(int number)
{
  // Base case: if number reaches 0, return 0
  if (number == 0)
    return 0;

  // Recursive call: add current number to the sum of numbers from 1 to (number - 1)
  return (number + sumN(number - 1));
}

int main()
{
  // Declare an integer variable to store the number
  int number;

  // Prompt the user to enter a number
  cout << "Enter the Number: ";

  // Take the number input from the user
  cin >> number;

  // Call the sumN function with the provided number and store the result
  int ans = sumN(number);

  // Print the result
  cout << "Sum of Numbers from 1 to " << number << " is: " << ans;

  return 0;
}
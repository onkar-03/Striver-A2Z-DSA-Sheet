#include <bits/stdc++.h>
using namespace std;

// Function to print numbers from 1 to 'number'
void printN(int number)
{
  // Base case: if number reaches 0, stop the recursion
  if (number < 1)
    return; // Exit the function

  // Print the current number after returning from the recursive call
  cout << number << " ";

  // Recursive call: decrease number by 1 and call printN again
  printN(number - 1);

  // Time Complexity: [O(N)]
}

int main()
{
  // Declare an integer variable to store the number
  int number;

  // Prompt the user to enter a number
  cout << "Enter the Number: ";
  cin >> number; // Take the number input from the user

  printN(number); // Call the printN function with the provided number

  return 0;
}
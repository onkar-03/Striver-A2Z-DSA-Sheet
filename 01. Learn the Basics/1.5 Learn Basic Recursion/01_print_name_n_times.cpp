#include <bits/stdc++.h>
using namespace std;

// Function to print a name a certain number of times
void printName(int number, string name)
{
  // Base case: if number reaches 0, stop the recursion
  if (number == 0)
    return; // Exit the function

  // Print the name
  cout << name << endl;

  // Recursive call: Decrease number by 1 and call printName again
  printName(number - 1, name);

  // Time Complexity: [O(N)]
}

int main()
{
  // Declare a string variable to store the name
  string name;

  // Prompt the user to enter a name
  cout << "Enter Name: ";
  cin >> name; // Take the name input from the user

  // Declare an integer variable to store the number  int number;
  int number;

  // Prompt the user to enter a number
  cout << "Enter the Number of times you want to Print the Name: ";
  cin >> number; // Take the number input from the user

  printName(number, name); // Call the printName function with the provided number and name

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

// --- Method 1: Printing all divisors of a number (Brute Force)
void printDivisors(int number)
{
  // Iterate over the whole range of 1 to Number itself
  // This method checks every number from 1 to N for divisibility
  for (int i = 1; i <= number; i++) // [O(N)]
  {
    if (number % i == 0)
    {
      cout << i << " ";
    }
  }

  // Total Time Complexity: O(N)
}

// --- Method 2: Finding and printing divisors efficiently
void findAndPrintDivisors(int number)
{
  vector<int> divisors; // Vector to store the divisors

  // Iterate over the range 1 to sqrt(Number)
  // Divisors come in pairs (i, Number/i)
  for (int i = 1; i <= sqrt(number); i++) // [O(sqrt(N))]
  {
    if (number % i == 0)
    {
      divisors.push_back(i); // Store the divisor i
      if (i != number / i)   // Ensure not to duplicate the middle divisor
      {
        divisors.push_back(number / i); // Store the corresponding divisor
      }
    }
  }

  // Sort the vector of divisors
  sort(divisors.begin(), divisors.end()); // [O(N log N)]

  // Print the sorted divisors
  for (int divisor : divisors) // [O(N)]
  {
    cout << divisor << " ";
  }

  // Total Time Complexity: O(N log N) due to sorting
}

int main()
{
  int number;
  cout << "Enter the Number: ";
  cin >> number; // Input the number from the user

  // Method 1: Brute Force approach (commented out)
  // cout << "Divisors of " << number << " are: ";
  // printDivisors(number);

  // Method 2: Efficient method using square root approach
  cout << "Divisors of " << number << " are: ";
  findAndPrintDivisors(number);

  return 0;
}

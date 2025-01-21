#include <bits/stdc++.h>
using namespace std;

// Prime Number:
// A number that has exactly 2 distinct positive divisors: 1 and the number itself.

// Method 1: Brute Force Approach to check for Prime
bool isPrimeBruteForce(int number)
{
  int count = 0; // Counter for number of divisors

  // Iterate over the whole range of 1 to Number itself
  for (int i = 1; i <= number; i++) // Time Complexity: O(N)
  {
    if (number % i == 0)
      count++; // Increment count if i is a divisor of number
  }

  // If the number has more than 2 divisors, it's not prime
  if (count > 2)
    return false;
  else
    return true; // Otherwise, it's prime

  // Total Time Complexity: O(N)
}

// Method 2: Efficient Method using Square Root approach
bool isPrime(int number)
{
  int count = 0; // Counter for number of divisors

  // Iterate over the range 1 to sqrt(number) to find divisors
  for (int i = 1; i <= sqrt(number); i++)
  {
    if (number % i == 0)
    {
      count++; // Increment count for i being a divisor
      if (number / i != i)
      {
        count++; // If both divisors are different, increment count again
      }
    }
  }

  // If the number has more than 2 divisors, it's not prime
  if (count > 2)
    return false;
  else
    return true; // Otherwise, it's prime

  // Total Time Complexity: O(sqrt(N))
}

int main()
{
  int number;
  cout << "Enter the Number: ";
  cin >> number; // Input the number from the user

  // Method 1: Brute Force approach (commented out)
  /*
  if (isPrimeBruteForce(number))
  {
    cout << number << " is a Prime Number" << endl;
  }
  else
  {
    cout << number << " is not a Prime Number" << endl;
  }
  */

  // Method 2: Efficient method using sqrt approach
  if (isPrime(number))
  {
    cout << number << " is a Prime Number" << endl;
  }
  else
  {
    cout << number << " is not a Prime Number" << endl;
  }

  return 0;
}

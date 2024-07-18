#include <bits/stdc++.h>
using namespace std;

// Function to calculate the sum of all divisors of a number
int sumOfDivisors(int number)
{
  int sum = 0; // Initialize sum to zero

  // Iterate over the range 1 to Number itself
  for (int i = 1; i <= number; i++)
  {
    if (number % i == 0)
    {
      sum += i; // Add i to sum if i is a divisor of number
    }
  }

  return sum; // Return the computed sum of divisors
}

int main()
{
  int number;
  cout << "Enter the Number: ";
  cin >> number; // Input the number from the user

  // Calculate the sum of divisors using the function
  int sum = sumOfDivisors(number);

  // Output the result
  cout << "Sum of Divisors of " << number << " are: " << sum << endl;

  return 0;
}

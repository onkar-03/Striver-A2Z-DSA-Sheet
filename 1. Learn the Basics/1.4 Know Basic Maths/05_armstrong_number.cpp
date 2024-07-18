#include <bits/stdc++.h>
using namespace std;

// Function to find the Highest Common Factor (HCF) using the Brute Force method
int HCFBruteForce(int number1, int number2)
{
  int end = min(number1, number2); // Determine the smaller number between number1 and number2

  int hcf = 1;                   // Default HCF is 1
  for (int i = 1; i <= end; i++) // Iterate from 1 to the smaller number [O(min(number1, number2))]
  {
    if (number1 % i == 0 && number2 % i == 0)
    {
      hcf = i; // Update HCF if both numbers are divisible by i
    }
  }
  return hcf; // Return the computed HCF
}

// Function to find the Highest Common Factor (HCF) using the Euclidean Algorithm
int HCFEuclideanAlgorithm(int number1, int number2)
{
  while (number1 > 0 && number2 > 0)
  {
    if (number1 > number2)
      number1 = number1 % number2; // Update number1 to remainder of number1 divided by number2
    else if (number2 > number1)
      number2 = number2 % number1; // Update number2 to remainder of number2 divided by number1
  }
  if (number1 == 0)
  {
    return number2; // Return number2 when number1 becomes zero
  }
  else
  {
    return number1; // Return number1 when number2 becomes zero
  }

  // Time Complexity: O(log(min(number1, number2)))
}

int main()
{
  int number1, number2;

  // Prompt the user to enter two numbers
  cout << "Enter First Number: ";
  cin >> number1;
  cout << "Enter Second Number: ";
  cin >> number2;

  // Determine the HCF using Euclidean Algorithm
  int hcf = 1;
  if (number1 > number2)
  {
    hcf = HCFEuclideanAlgorithm(number1, number2);
  }
  else
  {
    hcf = HCFEuclideanAlgorithm(number2, number1);
  }

  // Calculate the LCM using the formula LCM(a, b) = (a * b) / HCF(a, b)
  int lcm = number1 * number2 / hcf;

  // Output the results
  cout << "HCF of " << number1 << " and " << number2 << " is: " << hcf << endl;
  cout << "LCM of " << number1 << " and " << number2 << " is: " << lcm << endl;

  return 0;
}

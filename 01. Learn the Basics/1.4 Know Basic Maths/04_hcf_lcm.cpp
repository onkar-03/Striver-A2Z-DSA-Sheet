#include <bits/stdc++.h>
using namespace std;

// Method 1
int HCFBruteForce(int number1, int number2)

{
  int end = min(number1, number2);

  // Default hcf is 1 for everyone
  int hcf = 1;
  for (int i = 1; i <= end; i++) // [O(min(number1, number2))]
  {
    if (number1 % i == 0 && number2 % i == 0)
    {
      hcf = i;
    }
  }
  return hcf;
}

// Method 2
// HCF(a,b) = HCF(a-b,b), where a > b
// Similar to saying HCF(a.b) = HCF(a%b,b), where a > b
int HCFEuclideanAlgorithm(int number1, int number2)
{
  while (number1 > 0 && number2 > 0)
  {
    if (number1 > number2)
      number1 = number1 % number2;
    else if (number2 > number1)
      number2 = number2 % number1;
  }
  if (number1 == 0)
  {
    return number2;
  }
  else
    return number1;

  // Time Complexity: O(log∅(min(a,b)))
}

int main()
{
  int number1, number2;
  cout << "Enter First Number: ";
  cin >> number1;
  cout << "Enter Second Number: ";
  cin >> number2;

  // Method 1
  // int hcf = HCFBruteForce(number1, number2);

  // Method 2
  int hcf = 1;
  if (number1 > number2)
  {
    hcf = HCFEuclideanAlgorithm(number1, number2);
  }
  else
  {
    hcf = HCFEuclideanAlgorithm(number2, number1);
  }

  int lcm = number1 * number2 / hcf;

  cout << "HCF of " << number1 << " and " << number2 << " is: " << hcf << endl;
  cout << "LCM of " << number1 << " and " << number2 << " is: " << lcm << endl;
  return 0;
}
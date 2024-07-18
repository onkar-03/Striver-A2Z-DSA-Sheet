#include <bits/stdc++.h>
using namespace std;

// Function to find the Highest Common Factor (HCF) using the Brute Force method
bool isArmstrongNumber(int number)
{
  int sum = 0;
  int originalNumber = number;
  while (originalNumber != 0)
  {
    int digit = originalNumber % 10;
    sum += pow(digit, 3);
    originalNumber /= 10;
  }
  return (sum == number);
}

int main()
{
  int number;

  // Prompt the user to enter two numbers
  cout << "Enter the Number: ";
  cin >> number;

  if (isArmstrongNumber(number))
  {
    cout << number << " is an Armstrong Number";
  }
  else
  {
    cout << number << " is not an Armstrong Number";
  }

  return 0;
}

/*
Create a C++ program to check a number is a prime number or not, using recursion
*/
#include <iostream>
using namespace std;
bool recursePrime(int n, int i = 2)
{
  if (n <= 2)
  {
    return (n == 2) ? true : false;
  }
  if (n % 2 == 0)
  {
    return false;
  }
  if (i * i > n)
  {
    return true;
  }

  return recursePrime(n, i + 1);
}
int main()
{
  cout << "Enter number to check: ";
  int input;
  cin >> input;
  if (recursePrime(input))
  {
    cout << "Number is prime" << endl;
  }
  else
  {
    cout << "Number is not prime" << endl;
  }
}
/*
Create a C++ program which takes two integers from user. Your program should also have a recursive function which will display odd numbers between the ranges given by user.
*/
#include <iostream>
using namespace std;
void recursiveOdd(int n, int m)
{
    if (n > m)
    {
        return;
    }
    else
    {
        if (n % 2 == 0)
        {
            cout << n << " ";
        }

        n++;
        recursiveOdd(n, m);
    }
}

int main()
{
    int n, m;
    cout << "Enter starting number: ";
    cin >> n;
    cout << "Enter ending number: ";
    cin >> m;
    cout << "Odd numbers between " << n << " and " << m << " are: " << endl;
    recursiveOdd(n, m);
    return 0;
}
/*
Create a C++ program to check a number is a prime number or not, using recursion
*/
#include<iostream>
using namespace std;
void recurseFunc(int x)
 {
    int n=x--;
    if (x%n==0)
    {
        cout<<"You entered Prime Number";
    }
    
    

 }
int main()
{
cout<<"Enter number to check: ";
int input;
cin>>input;
recurseFunc(input);

 return 0;
}
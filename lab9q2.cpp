/*
Create a C++ program to check a number is a prime number or not, using recursion
*/
#include<iostream>
using namespace std;
bool recurseFunc(int x)
 {
    
   if (x==1)
   {
    return true;
   }
   else
   { 
    return recurseFunc(x-1);
   
   }
   
 }
int main()
{
cout<<"Enter number to check: ";
int input;
cin>>input;
bool result=recurseFunc(input);
if (result==false)
{
    cout<<"Number is not prime";
}
else
{
    cout<<"Number is prime";
}


 return 0;
}
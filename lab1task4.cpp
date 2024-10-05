/*
Write a program to create a dynamic array of user defined size. Size should be in the range of 1 to 15. Write a function FindLarge that should ask user to enter a non-negative number. Function should find the next largest number than the input number in the list.

Sample input:
Enter size: 5

After insertion:
13 4 55 29 32

Sample output:
Enter number: 15
Next largest number from 15 is: 29

*/
#include<iostream>
using namespace std;
 
 void FindLarge(int *num,int next,int size)
 {
    int n;
   for (int i = 0; i < size; i++)
   {
    if (num[i] > next && num[i] != next)
    {
        n=num[i];
    }
   }
   for (int i = 0; i < size; i++)
   {
    if (num[i]>next &&  num[i]<n)
    {
        n=num[i];
    }
    }
    cout<<"Next largest  number from "<<next<<" is: "<<n<<endl;


   }
int main()
{
    
    int size, i, nextLarge;
     cout<<"Enter size of array (1 to 15): ";
     cin>>size;
     while (size<1 || size>15)
     {
       cout<<"Size should be greater than 0 and  less than 16."<<endl;
       cout<<"Enter size of array (1 to 15): ";
       cin>>size;
     }     
     int* num= new int[size];
     for (int i = 0; i < size; i++)
     {
        cout<<"Enter element "<<i+1<<": ";
        cin>>num[i];
     }
     cout<<"Enter number to find the next largest number: ";
     cin>>nextLarge;
     FindLarge(num, nextLarge, size);
     
 return 0;
}
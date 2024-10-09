// you are given an array containing n ditinct elements (all are unique). your task is to reverse the order of the same array and display the modified array.
#include<iostream>
using namespace std;
 
int main()
{
    int r=4;
    int arr[5]{1,2,3,4,5};
    for (int i = 0; i < 4; i++)
    {
        for (int  j = 0; j < r; j++)
        {
            int temp;
           temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
            

        }
        r--;
        
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i];
    }
    

 return 0;
}
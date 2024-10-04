/*Write a program to create a dynamic array of user defined size. Array should be of character
type. Write a function ChangeCase() that should convert all the small alphabets to capital and
vice versa. All array operations should be done using pointers.*/
#include<iostream>
using namespace std;
 void  ChangeCase(char *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 'a' && arr[i] <= 'z') {
            arr[i] = arr[i] - 32;
            }
            else if (arr[i] >= 'A' && arr[i] <= 'Z') {
                arr[i] = arr[i] + 32;
                }
                }
                }

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    
char *arr = new char[n];
for (int i = 0; i < n; i++)
{
    cout<<"Enter the character at index "<<i+1<<" : ";
    cin>>arr[i];

}
cout<<"Array before change case: ";
for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";
}
cout<<"\nArray after change case: ";
ChangeCase(arr,n);
cout<<"\nArray after change case: ";
for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";
    }
    


 return 0;
}
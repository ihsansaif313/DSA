/*
Write a C++ program to which will create a static array of size 10 now pass this array to a
function which will print the array elements using recursion
*/
#include <iostream>
using namespace std;
void recursePrint(char *arr, int index)
{
    if (arr[index] == '\0') // base case
    {
        return;
    }
    else
    {
        cout << arr[index] << endl;
        index++;
        recursePrint(arr,index);
    }
}
int main()
{
    char arr[10]{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

    int index = 0;

    recursePrint(arr, index);
    return 0;
}
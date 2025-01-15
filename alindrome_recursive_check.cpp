// Write a program to create a static character array. Write a recursive function FindPalindrome which should tell whether or not the entered set of characters is palindromic sequence
#include<iostream>
using namespace std;
bool FindPalindrome(char *arr,int LIndex ,int FIndex=0)
{
    
    if (arr[FIndex]==arr[LIndex])
    {
        if (FIndex == LIndex)
        {
            return true;
        }

        return FindPalindrome(arr,LIndex-1,FIndex+1);

    }
    else
    {
        return false;
    }
    
    
    
}
int main()
{
    string str;
    cout << "Enter a word: ";
    cin >> str;
 
char arr[str.length()];
for (int i = 0; i < str.length(); i++)
{
    arr[i] = str[i];
}
int index=sizeof(arr)-1;
if(FindPalindrome(arr,index))
{
    cout<<"Your word is a palindrome"<<endl;
}
else
{
    cout<<"Your word is not a palindrome"<<endl;
}

 return 0;
}
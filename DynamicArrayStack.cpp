/* Write a program to implement a Stack using dynamic array of Character values. Implement the
following functions in Stack with necessary checks:
a) Insert value in Stack (PUSH)
b) Delete value from Stack (POP)
c) Display the Stack
*/
#include<iostream>
using namespace std;
 class dynamic
 {
   char *stack1;
   int size1;
    int top;
 public:
 dynamic(int size)
 {
    size1=size;
    stack1 = new char [size];
    top=-1;
 }
 void push(int val)
 {
    if (top<size1)
    {
        top++;
        stack1[top]=val;

    }
 }
 void pop()
 {
    if (top>=0)
    {
    top--;
    cout<<"Last item has been poped"<<endl;
    }
    
   
 }
 void display()
 {
    for (int i = 0; i <= top; i++)
    {
        cout<<stack1[i];
    }
    
 }
 };
 
int main()
{
    int size=5;
    dynamic d(size);
    for (int i = 0; i < size; i++)
    {
        char val;
        cout<<"Enter value at "<<i+1<<" : ";
        cin>>val;
        d.push(val);
    }
   d.pop();
    d.display();
    

 return 0;
}
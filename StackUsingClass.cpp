// create stack throug class
#include<iostream>
using namespace std;
 class stackThroughClass
 {
 int *stack;
 int count,size1;

 public:
    stackThroughClass(int size)
    {
        size1=size;
        stack=new int[size];
        count=-1;
        

    }

    void push(int value1)
        {
            if(count<size1-1){
                count++;
                stack[count]= value1;
        }
        }

    void pop()
    {
        if(count>=0){
            cout<<"value to pop is : "<<stack[count];
            count--;
    }
    }
   
 };

 
int main()
{
    int size;
    cout<<"Enter size of array:  ";
    cin>>size;
    stackThroughClass s(size);
    int val;
    for (int  i = 0; i < size; i++)
    {
        cout<<"Enter value at "<<i+1<<" : ";
        cin>>val;
        s.push(val);

    }
    cout<<"want to delete item";
    s.pop();

 return 0;
}
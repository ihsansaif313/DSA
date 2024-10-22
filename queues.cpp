#include <iostream>
using namespace std;
#define size 20
class queues
{

    int *arr;
    int front, rear;

public:
    queues()
    {
        arr = new int[size];
        front = rear = -1;
    }

    bool isempty()
    {
        if (front==-1 || front>rear)
        {
            cout<<"No element in queue"<<endl;
            return true;
        }
        return false;
        
        
    }

    void enqueue(int x)
    {
        if (rear==size-1)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        rear++;
        arr[rear]=x;
        if (front==-1)
        {
            front++;
        }
    }
    
    void dequeue()
    {
        if (isempty()==true)
        {
            return;
        }
        front++;
        cout<<"One element has been dequeued as you call dequeue function"<<endl;
    }

    void peek()
    {
        if (!isempty())
        {
           cout<<arr[front];
        }
        
    }


};

int main()
{
    queues q1;
    for (int i = 0; i < 21; i++)
    { 
    q1.enqueue(i);
    }
    q1.dequeue();
    q1.peek();
}
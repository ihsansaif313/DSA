/*
Partial solution of a Linear Queue Class is given below. Complete the missing code in the functions to
run the program properly
*/
#include <iostream>

using namespace std;


class Queue
{

    int *elements;
    int size;
    int rear, front;

public:
    Queue(int maxsize)
    {
        size = maxsize;
        elements = new int[size];
        rear = 0, front = -1;
    }
    /////////////////////////////////// Destructor
    ~Queue()
    {
        delete[] elements;
    }
    /////////////////////////////////// Output the Queue structure
    void showStructure()
    {
        if (!isEmpty())
        {
            for (int i = 0; i < rear; i++)
            {
                cout << "Element:" << elements[i] << endl;
            }
        }
        else
        {
            cout << "Display: No items to be displayed. Queue is empty \n";
        }
    }
    ////////////////////////////////// Queue manipulation operations
    // Insert in queue
    void Enqueue(int newDataItem)
    {
        if (!isFull())
        {
            if (front == -1)
            {
                front = 0;
            }
            elements[rear] = newDataItem;
            rear++;
        }
        else
        {
            cout << "Insert: Cannot insert more items. List is full\n";
        }
    }
    // Remove data item
    void Dequeue()
    {
        if (!isEmpty())
        {
            
        }
        else
        {
            cout << "Remove: Cannot remove the item. List is empty \n";
        }
    }
    // Clear queue
    void clear()
    {
        // implement your logic here
        //  Removes all the data items in a queue but the queue itself
    }
    /////////////////////////////////////// Queue status operations
    // check if queue is empty
    bool isEmpty()
    {
        if (rear==front)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
    // check if queue is full
    bool isFull()
    {
        if (rear==size)
        {
            return true;
        }
        else
        return false;
    }
};
struct queue
{
    
};


int main()
{
    int queueSize;
    cout<<"Enter size of queue: ";
    cin>>queueSize;
    Queue q(queueSize);
     



}
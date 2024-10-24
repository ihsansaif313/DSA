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
            for (int i = front; i < rear; i++)
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
            if (front==-1)
            {
                front=0;
            }
            front++;
            cout<<"One element removed\n";
        }
        else
        {
            cout << "Remove: Cannot remove the item. List is empty \n";
        }
    }
    // Clear queue
    void clear()
    {
        rear=0;
        front=-1;
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
        if (rear==size-1)
        {
            return true;
        }
        else
        return false;
    }
};

int main()
{
    int queueSize;
    cout<<"Enter size of queue: ";
    cin>>queueSize;
    Queue q(queueSize);
    int choice;
    do
    {
        cout<<"1-Insert in queue\n";
        cout<<"2-POP from queue\n";
        cout<<"3-Display queue\n";
        cout<<"4-Clear the queue\n";
        cout<<"5-Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
        cout<<"Enter data to insert: ";
        int data;
        cin>>data;
            q.Enqueue(data);
            break;
        case 2:
            q.Dequeue();
            break;
        case 3:
            q.showStructure();
            break;
        case 4:
            q.clear();
            break;
        default:
            break;
        }
    } while (choice != 5);
    
    



}
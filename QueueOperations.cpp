#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class queue
{
    int queuel[5];
    int rear, front;

public:
    queue()
    {
        rear = -1;
        front = -1;
    }
    void insert(int x)
    {
        if (rear > 4)
        {
            cout << "queue over flow";
          
            
        }
        queuel[++rear] = x;
        cout << "inserted" << x;
    }
    void delet()
    {
        if (front == rear)
        {
            cout << "queue under flow";
            return;
        }
        cout << "deleted" << queuel[++front];
    }
    void display()
    {
        if (rear - front)
        {
            cout << " queue empty";
            return;
        }
        for (int i = front + 1; i <= rear; i++)
            cout << queuel[i] << " ";
    }
};
int main()
{
    int ch;
    queue qu;
    while (1)
    {
        cout << "\nl.insert 2.delet 3. display 4.exit\nEnter ur choice";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter the element";
            cin >> ch;
            qu.insert(ch);
            break;
        case 2:
            qu.delet();
            break;
        case 3:
            qu.display();
            break;
        case 4:
            exit(0);
        }
    }
   
}

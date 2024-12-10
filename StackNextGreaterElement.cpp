
/*
Create a Stack of integer using arrays. Give the following menu to the user and then implement
the given operations:
Press 1 to PUSH a value in Stack
Press 2 to POP a value from Stack
Press 3 to display the Stack
Press 4 to Show the next greater element in the Stack.
Sample Input:
Stack
3 2 6 7 8 13
Press 1 to PUSH a value in Stack
Press 2 to POP a value from Stack
Press 3 to display the Stack
Press 4 to Show the next greater element in the Stack.
4
Sample Output:
The next greater elements for the given Stack are:
3-->6
2-->6
6-->7
7-->8
8-->13
13-->-1
*/
#include <iostream>
using namespace std;
class greaternum
{
    int *arr;
    int size;
    int top = -1;

public:
    greaternum(int size1)
    {
        size = size1;
        arr = new int[size];
    }

    int menu()
    {
        int choice;
        cout << "Press 1 to PUSH a value in Stack\nPress 2 to POP a value from Stack\nPress 3 to display the Stack\nPress 4 to Show the next greater element in the Stack\nPress 0 to EXIT\nEnter your choice: ";
        cin >> choice;
        if (choice >= 0 && choice <= 4)
        {
            return choice;
        }
        else
        {
            cout << "Invilid input" << endl;
            return menu();
        }
    }

    void push()
    {
        top++;
        for (int i = top; i < size; i++)
        {
            cout << "Enter the value to be pushed at position " << i + 1 << ": ";
            cin >> arr[i];
            top++;
        }
        if (top == size)
        {
            cout << "Stack is full.  Cannot push more elements." << endl;
        }
    }

    void POP()
    {
        if (top > -1)
        {
            top--;
            cout << "Element has been Poped out from Stack\n\n"
                 << endl;
        }
        else
        {
            cout << "Stack is already empty. ";
        }
    }
    void display()
    {
        if (top > -1)
        {
            for (int i = 0; i < top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl
                 << endl;
        }
        else
        {
            cout << "Stack is empty. ";
        }
    }
    void nextgreater()
    {
        int next;
        int topp;

        if (top > -1)
        {
            cout << "Numbers already in stack is: ";
            for (int i = 0; i < top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;

            cout << "Enter num to find the next Greater number on the stack : ";
            cin >> next;
            for (int i = 0; i < top; i++)
            {
                if (next == arr[i])
                {
                    if (i != top-1)
                    {
                        topp = i;
                        break;
                    }
                    else
                    {
                        cout<<"No  greater number found.This is the last Greatest number of stack.\n Try another number"<<endl;
                        nextgreater();
                    }
                }
            }

            int bignum = 0;
            for (int i = topp + 1; i < top; i++)
            {
                if (arr[i] > bignum)
                {
                    bignum = arr[i];
                }
            }
            
            for (int i = topp + 1; i < top; i++)
            {
                if (next < arr[i] && arr[i] < bignum)
                {
                    bignum = arr[i];
                }
            }
            cout << "Next greater number in stack is : " << bignum << endl<<endl;
        }
        else
        {
            cout << "stack is empty! ";
        }
    }
};

int main()
{
    int size = 7;
    greaternum g(size);
    int choice = g.menu();
    while (choice != 0)
    {
        switch (choice)
        {
        case 0:
            cout << "Program Terminated";
            break;
        case 1:
            g.push();
            choice = g.menu();
            break;
        case 2:
            g.POP();
            choice = g.menu();
            break;
        case 3:
            g.display();
            choice = g.menu();
            break;

        case 4:
            g.nextgreater();
            choice = g.menu();
            break;
        }
    }

    return 0;
}
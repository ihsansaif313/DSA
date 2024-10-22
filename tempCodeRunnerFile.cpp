#include <iostream>
using namespace std;
class charCrush
{
    char *arr;
    int top = 0;

public:
    charCrush()
    {
        arr = new char[100];
    }
    void push(char c)
    {
        if (c != arr[top-1])
        {
            arr[top] = c;
            top++;
        }
        else
        {
            top--;
        }
    }

    void display()
    {
        for (int i = 0; i < top; i++)
        {
            cout << arr[i] << " ";
        }
    }
};


int main()
{
    char ch;
    charCrush obj;
    while (ch != 'F' && ch != 'f')
    {
        cout << "Enter a character (F/f to exit): ";
        cin >> ch;
        if (ch != 'F' && ch != 'f')
        {
            obj.push(ch);
        }
    }
    obj.display();
}

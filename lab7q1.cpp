/*
Write a program to implement a stack using linked list. Stack is of Books (Title, Author, Price).
your program should find or delete a book entered by user from the stack. Remember that to
reach a book in stack all the books above must be checked first.
*/
#include <iostream>
using namespace std;
class Node
{

public:
    string title;
    string author;
    int price;
    Node *next;
    Node(string title, string author, int price)
    {
        this->title = title;
        this->author = author;
        this->price = price;
        next = NULL;
    }
    ~Node();
};
class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    void push(string title, string author, int price)
    {
        Node *new_node = new Node(title, author, price);
        if (top == NULL)
        {
            top = new_node;
        }
        else
        {
            new_node->next = top;
            top = new_node;
        }
    }
    void findaBook(string title)
    {
        Node *temp = top;
        while (temp != NULL)
        {
            if (temp->title == title)
            {
                cout << "Title: " << temp->title << endl;
                cout << "Author: " << temp->author << endl;
                cout << "Price: " << temp->price << endl;
                return;
            }
        }
    }
    void deleteBook(string title)
    {
        Node *temp = top;
        while (temp != NULL)
        {
            if (temp->title == title)
            {
                if (temp == top)
                {
                    top = temp->next;
                }
                else
                {
                    Node *prev = top;
                    while (prev->next != temp)
                    {
                        prev = prev->next;
                    }
                    prev->next = temp->next;
                }
            }
        }
    }
    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
        }
        
    }
};
int main()
{

    return 0;
}
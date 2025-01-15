/*
Write a program which should implement a single linked list. 
Elements of this linked list should be of integer type; 
user will provide values as input for elements of this linked list. 
Your program should allow searching of a value specified by user in linked list.
*/

#include <iostream>
using namespace std;

class Node
{

public:
    int data;

    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Linkedlist
{
    Node *head;

public:
    Linkedlist()
    {
        head = NULL;
    }

    
    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *h = head;
            while (h->next != NULL)
            {
                h = h->next;
            }
            h->next = newNode;
        }
    }
    
    void search(int val)
    {
        if (head == NULL)
        {
           cout<<"Linked list is empty";
        }
        else
        {
        Node* temp =head;
        while (temp->next!=NULL)
        {
            if (temp->data==val)
            {
                cout<<val<<" has been found";
            }
            
        }
        }
        
    }


    bool isempty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
            return false;
    }

    void display()
    {
        if (!isempty())
        {
            Node *temp = head;
            int count = 0;
            while (temp->next != NULL)
            {
                count++;
                cout << count << " Node data is " << temp->data << endl;
                temp = temp->next;
            }
        }
        else
        {
            cout << "empty";
        }
    }
};

int main()
{
    
    Linkedlist llist;
    llist.insert(100);
    llist.insert(200);
    llist.insert(300);
    llist.insert(400);
    llist.search(200);
    llist.display();

    return 0;
}
/*
MAKE A LINKED LIST HAVING FOLLOWING PROPERTIES
Insertat head
Insert at tail
Insert at after rollno
Insert at before rollno
Delete at head
Delete at tail
Delete by rollno
 Display
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

    
    void insertattail(int val)
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
    void insertathead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAfterRollno(int roll, int val)
    {
        Node *newNode = new Node(val);
        Node *h = head;

        while (h != NULL && h->data != roll)
        {
            h = h->next;
        }
        if (h == NULL)
        {
            cout << "Roll no not found" << endl;
        }
        else
        {
            newNode->next = h->next;
            h->next = newNode;
        }
    }

    void insertBeforeRollno(int roll, int val)
    {
        Node *newNode = new Node(val);
        Node *h = head;
        Node *prev = NULL;
        while (h != NULL && h->data != roll)
        {
            prev = h;
            h = h->next;
        }
        if (h == NULL)
        {
            cout << "Roll no not found" << endl;
        }
        else
        {
            newNode->next = h;
            prev->next = newNode;
        }
    }

    void deleteAtHead()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtTail()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        Node *prev = head;
        Node *temp = head->next;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }

    void deleteByRollno(int val)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == val)
        {
            deleteAtHead();
        }
        Node *prev = head;
        Node *temp = head->next;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
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
            while (temp != NULL)
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
    cout<<"CODE BY: IHSAN SAIF"<<endl;
    Linkedlist llist;
    // using all properties
    llist.insertathead(5);
    llist.insertathead(2);
    llist.insertathead(3);
    llist.insertathead(5);
    llist.insertathead(4);
    llist.insertattail(6);
    llist.insertAfterRollno(4, 3);
    llist.insertBeforeRollno(2, 1);
    llist.deleteAtHead();
    llist.deleteAtTail();
    llist.deleteByRollno(1);

    llist.display();

    return 0;
}
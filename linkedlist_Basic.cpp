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
            Node *h=head;
           while (h->next!=NULL)
           {
             h=h->next;
           }
           h->next=newNode;
           
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
                cout << count << " Node data is " << temp->data<<endl;
                temp = temp->next;
                
                
            }
        }
        else
        {
            cout<<"empty";
        }
        
    }
};

int main()
{
    Linkedlist llist;
    llist.insert(6);
    llist.insert(7);
    llist.insert(8);
    llist.insert(9);
    llist.display();

    return 0;
}
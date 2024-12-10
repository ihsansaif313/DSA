#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
class LinkedList
{
public:
    node *head;

    LinkedList()
    {
        head = NULL;
    }

    void insert(int val)
    {
        node *newNode = new node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void deleteNode(int rollNo)
    {
        if (head == NULL)
            return; // List is empty

        // If the node to be deleted is the head node
        if (head->data == rollNo)
        {
            node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Search for the node to be deleted
        node *current = head;
        node *previous = NULL;
        while (current != NULL && current->data != rollNo)
        {
            previous = current;
            current = current->next;
        }

        // If the node was not found
        if (current == NULL)
            return;

        // Unlink the node from the linked list
        previous->next = current->next;
        delete current;
    }
};

int main()
{

    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Linked List: ";
    list.display();
    list.deleteNode(10); // Remove the node with value 20
    cout << "Linked List after removal: ";
    list.display();
    return 0;
}
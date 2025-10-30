/* 
MAKE A LINKED LIST HAVING FOLLOWING PROPERTIES
Insert at head
Insert at tail
Insert after rollno
Insert before rollno
Delete at head
Delete at tail
Delete by rollno
Display
*/

#include <iostream> // Include input-output stream library
using namespace std; // Use standard namespace

// Define Node class representing each element in the linked list
class Node
{
public:
    int data;       // Data stored in the node
    Node *next;     // Pointer to the next node

    // Constructor to initialize node with data
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Define Linkedlist class to manage linked list operations
class Linkedlist
{
    Node *head; // Pointer to the head of the list

public:
    // Constructor initializes head to NULL
    Linkedlist()
    {
        head = NULL;
    }

    // Insert a node at the tail of the list
    void insertattail(int val)
    {
        Node *newNode = new Node(val); // Create new node
        if (head == NULL) // If list is empty
        {
            head = newNode; // Set new node as head
        }
        else
        {
            Node *h = head; // Start from head
            while (h->next != NULL) // Traverse to the last node
            {
                h = h->next;
            }
            h->next = newNode; // Link new node at the end
        }
    }

    // Insert a node at the head of the list
    void insertathead(int val)
    {
        Node *newNode = new Node(val); // Create new node
        if (head == NULL) // If list is empty
        {
            head = newNode; // Set new node as head
        }
        else
        {
            newNode->next = head; // Point new node to current head
            head = newNode;       // Update head to new node
        }
    }

    // Insert a node after a specific roll number (data value)
    void insertAfterRollno(int roll, int val)
    {
        Node *newNode = new Node(val); // Create new node
        Node *h = head; // Start from head

        // Traverse until roll number is found
        while (h != NULL && h->data != roll)
        {
            h = h->next;
        }

        if (h == NULL) // If roll number not found
        {
            cout << "Roll no not found" << endl;
        }
        else
        {
            newNode->next = h->next; // Link new node after found node
            h->next = newNode;
        }
    }

    // Insert a node before a specific roll number (data value)
    void insertBeforeRollno(int roll, int val)
    {
        Node *newNode = new Node(val); // Create new node
        Node *h = head; // Start from head
        Node *prev = NULL; // Previous node tracker

        // Traverse until roll number is found
        while (h != NULL && h->data != roll)
        {
            prev = h;
            h = h->next;
        }

        if (h == NULL) // If roll number not found
        {
            cout << "Roll no not found" << endl;
        }
        else
        {
            newNode->next = h; // Link new node before found node
            prev->next = newNode;
        }
    }

    // Delete the node at the head of the list
    void deleteAtHead()
    {
        if (head == NULL) // If list is empty
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head; // Store current head
        head = head->next; // Move head to next node
        delete temp;       // Delete old head
    }

    // Delete the node at the tail of the list
    void deleteAtTail()
    {
        if (head == NULL) // If list is empty
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == NULL) // If only one node
        {
            delete head;
            head = NULL;
            return;
        }

        Node *prev = head; // Previous node tracker
        Node *temp = head->next; // Current node tracker

        // Traverse to second last node
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL; // Remove last node
        delete temp;
    }

    // Delete a node by its roll number (data value)
    void deleteByRollno(int val)
    {
        if (head == NULL) // If list is empty
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == val) // If head matches roll number
        {
            deleteAtHead(); // Delete head
            return;
        }

        Node *prev = head; // Previous node tracker
        Node *temp = head->next; // Current node tracker

        // Traverse to find matching node
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                prev->next = temp->next; // Remove node from list
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    // Check if the list is empty
    bool isempty()
    {
        return head == NULL;
    }

    // Display all nodes in the list
    void display()
    {
        if (!isempty()) // If list is not empty
        {
            Node *temp = head; // Start from head
            int count = 0; // Node counter

            // Traverse and print each node
            while (temp != NULL)
            {
                count++;
                cout << count << " Node data is " << temp->data << endl;
                temp = temp->next;
            }
        }
        else
        {
            cout << "empty"; // If list is empty
        }
    }
};

// Main function to demonstrate linked list operations
int main()
{
    cout << "CODE BY: IHSAN SAIF" << endl;

    Linkedlist llist; // Create linked list object

    // Perform various operations
    llist.insertathead(5);           // Insert 5 at head
    llist.insertathead(2);           // Insert 2 at head
    llist.insertathead(3);           // Insert 3 at head
    llist.insertathead(5);           // Insert another 5 at head
    llist.insertathead(4);           // Insert 4 at head
    llist.insertattail(6);           // Insert 6 at tail
    llist.insertAfterRollno(4, 3);   // Insert 3 after node with data 4
    llist.insertBeforeRollno(2, 1);  // Insert 1 before node with data 2
    llist.deleteAtHead();            // Delete head node
    llist.deleteAtTail();            // Delete tail node
    llist.deleteByRollno(1);         // Delete node with data 1

    llist.display(); // Display final list

    return 0; // End of program
}

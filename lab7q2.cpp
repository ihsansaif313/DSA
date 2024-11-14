#include <iostream>
using namespace std;

class node {
public:
    int OrderID; 
    string name, address;
    int items; 
    double payment; 
    node* next; 

    
    node(string n, string addr, int itemCount, double pay) {
        static int idCounter = 1;
        OrderID = idCounter++; 
        name = n;
        address = addr;
        items = itemCount;
        payment = pay;
        next = NULL;
    }
};

class Order {
private:
    node* head; 
public:
    Order() {
        head = NULL; 
    }

    
    void addOrder(string name, string address, int items, double payment)
     {
        node* newNode = new node(name, address, items, payment); 
        if (head == NULL) {
            head = newNode; 
        } else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next; 
            }
            temp->next = newNode; 
        }
        cout << "Order added with ID: " << newNode->OrderID << endl; 
    }

    
    void displayOrders() {
        if (head == NULL) {
            cout << "No orders available." << endl;
            return;
        }
        node* temp = head;
        while (temp != NULL) {
            cout << "Order ID: " << temp->OrderID << ", Name: " << temp->name
                 << ", Address: " << temp->address << ", Items: " << temp->items
                 << ", Payment: $" << temp->payment << endl;
            temp = temp->next; 
        }
    }
};

int main() {
    Order orderList;

    
    orderList.addOrder("IHSAN", "capital square", 2, 50.75);
    orderList.addOrder("SAMI", "b17", 1, 25);
    orderList.addOrder("RAHIM", "taxila", 3, 75.25);

    orderList.displayOrders();

    return 0;
}
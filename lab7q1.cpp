#include <iostream>
#include <string>
using namespace std;

// Node class to represent each book in the stack
class Node {
public:
    string title;
    string author;
    int price;
    Node* next;

    // Constructor to initialize the node
    Node(string title, string author, int price) {
        this->title = title;
        this->author = author;
        this->price = price;
        next = nullptr; // Initialize next pointer to nullptr
    }

    // Destructor (not strictly necessary here)
    ~Node() {
        // Cleanup code (if necessary)
    }
};

// Stack class to manage the linked list of books
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr; // Initialize top to nullptr
    }

    // Push a new book onto the stack
    void push(string title, string author, int price) {
        Node* newNode = new Node(title, author, price);
        newNode->next = top; // Link the new node to the previous top
        top = newNode; // Update the top to the new node
    }

    // Pop the top book from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next; // Move top to the next node
        delete temp; // Delete the old top node
        // cout << "Book popped from stack." << endl;
    }

    // Search for a book by title
    void search(string title) {
        Node* current = top;
        while (current != nullptr) {
            if (current->title == title) {
                cout << "Book found: " << current->title << ", " << current->author << ", $" << current->price << endl;
                return;
            }
            current = current->next; // Move to the next node
        }
        cout << "Book not found." << endl;
    }

    // Delete a book by title
    void deleteBook(string title) {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot delete." << endl;
            return;
        }

        // If the book to delete is at the top
        if (top->title == title) {
            Node* temp = top;
            top = top->next;
            delete temp;
            cout << "Book deleted from stack." << endl;
            return;
        }

        // Search for the book in the stack
        Node* current = top;
        Node* previous = nullptr;
        while (current != nullptr) {
            if (current->title == title) {
                previous->next = current->next; // Bypass the current node
                delete current; // Delete the found node
                cout << "Book deleted from stack." << endl;
                return;
            }
            previous = current;
            current = current->next; // Move to the next node
        }
        cout << "Book not found." << endl;
    }

    
    // Display all books in the stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* current = top;
        cout << "Books in stack:" << endl;
        while (current != nullptr) {
            cout << "Title: " << current->title 
                 << ", Author: " << current->author 
                 << ", Price: $" << current->price << endl;
            current = current->next; // Move to the next node
        }
    }


    // Destructor to clean up the stack
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
            cout<<"All the books has been poped out and the memory has been released."<<endl; // Pop all nodes to free memory
    }
};

// Example usage of the Stack class
int main() {
    Stack bookStack;

    bookStack.push("The Great Gatsby", "F. Scott Fitzgerald", 10);
    bookStack.push("1984", "George Orwell", 15);
    bookStack.push("book3", "author3", 158);
    bookStack.push("To Kill a Mockingbird", "Harper Lee", 12);

    bookStack.search("1984"); // Search for a book
    bookStack.deleteBook("The Great Gatsby"); // Delete a book
    bookStack.display();

    return 0;
}
#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string title;
    string author;
    int price;
    Node* next;

    
    Node(string title, string author, int price) {
        this->title = title;
        this->author = author;
        this->price = price;
        next = nullptr; 
    }

    
    ~Node() {
        
    }
};


class Stack {
private:
    Node* top; 

public:
    
    Stack() {
        top = nullptr;
    }

    
    void push(string title, string author, int price) {
        Node* newNode = new Node(title, author, price);
        newNode->next = top; 
        top = newNode;
    }

   
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next; 
        delete temp; 
        // cout << "Book popped from stack." << endl;
    }

    
    void search(string title) {
        Node* current = top;
        while (current != nullptr) {
            if (current->title == title) {
                cout << "Book found: " << current->title << ", " << current->author << ", $" << current->price << endl;
                return;
            }
            current = current->next; 
        }
        cout << "Book not found." << endl;
    }

    
    void deleteBook(string title) {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot delete." << endl;
            return;
        }

        
        if (top->title == title) {
            Node* temp = top;
            top = top->next;
            delete temp;
            cout << "Book deleted from stack." << endl;
            return;
        }

        
        Node* current = top;
        Node* previous = nullptr;
        while (current != nullptr) {
            if (current->title == title) {
                previous->next = current->next; 
                delete current; 
                cout << "Book deleted from stack." << endl;
                return;
            }
            previous = current;
            current = current->next; 
        }
        cout << "Book not found." << endl;
    }

    
    
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
            current = current->next;
        }
    }


    
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
            cout<<"All the books has been poped out and the memory has been released."<<endl; // Pop all nodes to free memory
    }
};


int main() {
    Stack bookStack;

    bookStack.push("The Great Gatsby", "F. Scott Fitzgerald", 10);
    bookStack.push("1984", "George Orwell", 15);
    bookStack.push("book3", "author3", 158);
    bookStack.push("To Kill a Mockingbird", "Harper Lee", 12);


    bookStack.search("1984"); 

    bookStack.deleteBook("The Great Gatsby"); 
    bookStack.display();
    

    return 0;
}
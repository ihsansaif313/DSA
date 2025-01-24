/* 
QUESTION 1 AND 2
.................

Question No.1 CLO-1

Write a program which should implement a Binary Search Tree. Elements of BST are objects of “student” class. “student” class contains attributes (privately defined) reg_no(int), st_name (string) and cgpa (float). “student” class should also contain member functions (publically defined); constructor, input and output functions. User will insert objects of class “student” in BST, values of attributes of objects will be provided by user. 
Program should display the objects of student class in pre order, post order and in order traversal formats.
.....................................
.....................................
Question No.2 CLO-1

Based on question 1 Program should also search an object from BST  which is provided by user as input.

*/
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int reg_no;
    string st_name;
    float cgpa;

public:
    Student() {
        reg_no = 0;
        st_name = "";
        cgpa = 0.0;
    }

    Student(int reg, string name, float grade) {
        reg_no = reg;
        st_name = name;
        cgpa = grade;
    }

    void input() {
        cout << "Enter Registration Number: ";
        cin >> reg_no;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, st_name);
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void output() const {
        cout << "Registration Number: " << reg_no << ", Name: " << st_name << ", CGPA: " << cgpa << endl;
    }

    int getRegNo() const {
        return reg_no;
    }
};

class BSTNode {
public:
    Student data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Student s) : data(s), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode* root;

    void insert(BSTNode*& node, Student s) {
        if (node == nullptr) {
            node = new BSTNode(s);
        } else if (s.getRegNo() < node->data.getRegNo()) {
            insert(node->left, s);
        } else {
            insert(node->right, s);
        }
    }

    void preOrder(BSTNode* node) const {
        if (node != nullptr) {
            node->data.output();
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(BSTNode* node) const{
        if (node != nullptr) {
            inOrder(node->left);
            node->data.output();
            inOrder(node->right);
        }
    }

    void postOrder(BSTNode* node) const {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            node->data.output();
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(Student s) {
        insert(root, s);
    }

    void displayPreOrder() const {
        preOrder(root);
    }

    void displayInOrder() const {
        inOrder(root);
    }

    void displayPostOrder() const {
        postOrder(root);
    }
    bool search(BSTNode* node, int reg_no, Student& result) const {
        if (node == nullptr) {
            return false;
        } else if (reg_no == node->data.getRegNo()) {
            result = node->data;
            return true;
        } else if (reg_no < node->data.getRegNo()) {
            return search(node->left, reg_no, result);
        } else {
            return search(node->right, reg_no, result);
        }
    }

public:
    bool search(int reg_no, Student& result) const {
        return search(root, reg_no, result);
    }
};

int main() {
    BST tree;
    int choice;
    do {
        cout << "1. Insert Student\n2. Display PreOrder\n3. Display InOrder\n4. Display PostOrder\n5. Search Student\n6. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                Student s;
                s.input();
                tree.insert(s);
                break;
            }
            case 2:
                tree.displayPreOrder();
                break;
            case 3:
                tree.displayInOrder();
                break;
            case 4:
                tree.displayPostOrder();
                break;
            case 5: {
                int reg_no;
                cout << "Enter Registration Number to search: ";
                cin >> reg_no;
                Student result;
                if (tree.search(reg_no, result)) {
                    cout << "Student found: ";
                    result.output();
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            }
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

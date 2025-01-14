#include <iostream>
using namespace std;

// Node class to represent each node in the BST
class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// BST class to represent the binary search tree
class BST {
private:
    Node* root;

    // Helper function for inserting a new node
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper function for finding the minimum value node
    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function for deleting a node
    Node* remove(Node* node, int value) {
        if (node == nullptr) return node;
        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // Helper function for in-order traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    // Insert a new node with given value
    void insert(int value) {
        root = insert(root, value);
    }

    // Remove a node with given value
    void remove(int value) {
        root = remove(root, value);
    }

    // In-order traversal
    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal: ";
    tree.inorder();

    tree.remove(20);
    cout << "After removing 20, In-order traversal: ";
    tree.inorder();

    tree.remove(30);
    cout << "After removing 30, In-order traversal: ";
    tree.inorder();

    tree.remove(50);
    cout << "After removing 50, In-order traversal: ";
    tree.inorder();

    return 0;
}

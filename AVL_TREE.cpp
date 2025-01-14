#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVL {
private:
    Node* root;

    // Helper function to get the height of the node
    int height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    // Helper function to get the balance factor of the node
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    // Right rotate
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Left rotate
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Insert a new node with given value
    Node* insert(Node* node, int value) {
        if (node == nullptr) return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && value > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Find the node with the minimum value
    Node* findMin(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // Delete a node with given value
    Node* deleteNode(Node* root, int value) {
        if (root == nullptr)
            return root;

        if (value < root->data)
            root->left = deleteNode(root->left, value);
        else if (value > root->data)
            root->right = deleteNode(root->right, value);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Search for a node with given value
    bool search(Node* root, int value) {
        if (root == nullptr)
            return false;
        if (root->data == value)
            return true;
        if (value < root->data)
            return search(root->left, value);
        return search(root->right, value);
    }

    // In-order traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    AVL() {
        root = nullptr;
    }

    // Insert a new node with given value
    void insert(int value) {
        root = insert(root, value);
    }

    // Delete a node with given value
    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    // Search for a node with given value
    bool search(int value) {
        return search(root, value);
    }

    // In-order traversal
    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVL tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "In-order traversal of the constructed AVL tree: ";
    tree.inorder();

    tree.deleteNode(30);
    cout << "In-order traversal after deletion of 30: ";
    tree.inorder();

    if (tree.search(40)) {
        cout << "Node 40 found in the AVL tree." << endl;
    } else {
        cout << "Node 40 not found in the AVL tree." << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

// Node class for Binary Tree
class Node {
public:
    int data;       // Data stored in the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// BinaryTree class
class BinaryTree {
private:
    Node* root;  // Root of the binary tree

    // Helper for In-Order Traversal (Left, Root, Right)
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Helper for Pre-Order Traversal (Root, Left, Right)
    void preOrderTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    // Helper for Post-Order Traversal (Left, Right, Root)
    void postOrderTraversal(Node* node) {
        if (node == nullptr) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

    // Recursive insert helper
    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    // Search for a value
    bool searchRecursive(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    // Insert a value into the binary tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Search for a value in the binary tree
    void search(int value) {
        if (searchRecursive(root, value)) {
            cout << "Value " << value << " found in the tree." << endl;
        } else {
            cout << "Value " << value << " not found in the tree." << endl;
        }
    }

    // Display the tree using in-order traversal
    void displayInOrder() {
        cout << "In-Order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }

    // Display the tree using pre-order traversal
    void displayPreOrder() {
        cout << "Pre-Order Traversal: ";
        preOrderTraversal(root);
        cout << endl;
    }

    // Display the tree using post-order traversal
    void displayPostOrder() {
        cout << "Post-Order Traversal: ";
        postOrderTraversal(root);
        cout << endl;
    }
};

// Main function
int main() {
    BinaryTree tree;
    int choice;

    do {
        cout << "\n----- Binary Tree Operations -----" << endl;
        cout << "1. Insert a Node" << endl;
        cout << "2. Search for a Value" << endl;
        cout << "3. Display In-Order Traversal" << endl;
        cout << "4. Display Pre-Order Traversal" << endl;
        cout << "5. Display Post-Order Traversal" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            cout << "Value " << value << " inserted into the tree." << endl;
            break;
        }
        case 2: {
            int value;
            cout << "Enter value to search for: ";
            cin >> value;
            tree.search(value);
            break;
        }
        case 3:
            tree.displayInOrder();
            break;
        case 4:
            tree.displayPreOrder();
            break;
        case 5:
            tree.displayPostOrder();
            break;
        case 6:
            cout << "Exiting the program. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

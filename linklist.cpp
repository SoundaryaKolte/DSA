#include <iostream>
using namespace std;

// Node class to represent each node of the linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class to manage the linked list
class LinkedList {
private:
    Node* head;     // Pointer to the head of the list

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to append a new node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {  // If the list is empty
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {  // Traverse to the end
            current = current->next;
        }
        current->next = newNode;
    }

    // Function to display the list
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Function to delete a node by value
    void deleteNode(int value) {
        if (!head) {  // If the list is empty
            cout << "List is empty." << endl;
            return;
        }

        // If the head node is to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Search for the node to be deleted
        Node* current = head;
        Node* prev = nullptr;
        while (current && current->data != value) {
            prev = current;
            current = current->next;
        }

        // If the value is not found
        if (!current) {
            cout << "Value not found in the list." << endl;
            return;
        }

        // Unlink the node
        prev->next = current->next;
        delete current;
    }
};

// Example usage
int main() {
    LinkedList ll;
    ll.append(10);
    ll.append(20);
    ll.append(30);
    ll.display();  // Output: 10 -> 20 -> 30 -> NULL

    ll.deleteNode(20);
    ll.display();  // Output: 10 -> 30 -> NULL

    return 0;
}

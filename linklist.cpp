#include <iostream>
using namespace std;

// Node class to represent each element in the linked list
class Node {
public:
    int data;     // Data stored in the node
    Node* next;   // Pointer to the next node

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList {
private:
    Node* head; // Pointer to the head of the list

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert a node at a specific position
    void insertAtPosition(int position, int value) {
        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; i++) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of range." << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete a node by value
    void deleteByValue(int value) {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted node with value: " << value << endl;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (!temp->next) {
            cout << "Value not found in the list!" << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Deleted node with value: " << value << endl;
    }

    // Display the linked list
    void displayList() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function
int main() {
    LinkedList list;
    int choice;

    do {
        cout << "\n----- Linked List Operations -----" << endl;
        cout << "1. Insert at End" << endl;
        cout << "2. Insert at Position" << endl;
        cout << "3. Delete by Value" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        }
        case 2: {
            int position, value;
            cout << "Enter position to insert: ";
            cin >> position;
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtPosition(position, value);
            break;
        }
        case 3: {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteByValue(value);
            break;
        }
        case 4:
            cout << "Current List: ";
            list.displayList();
            break;
        case 5:
            cout << "Exiting the program. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

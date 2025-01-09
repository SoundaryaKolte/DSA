#include <iostream>
#include <vector>
using namespace std;

// Stack class
class Stack {
private:
    vector<int> elements; // Vector to store stack elements

public:
    // Push an element onto the stack
    void push(int value) {
        elements.push_back(value);
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    // Pop the top element from the stack
    void pop() {
        if (elements.empty()) {
            cout << "Stack underflow! The stack is empty." << endl;
        } else {
            int topValue = elements.back();
            elements.pop_back();
            cout << "Popped " << topValue << " from the stack." << endl;
        }
    }

    // Peek at the top element of the stack
    void peek() {
        if (elements.empty()) {
            cout << "The stack is empty. No top element to display." << endl;
        } else {
            cout << "Top element is: " << elements.back() << endl;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return elements.empty();
    }

    // Display the stack
    void display() {
        if (elements.empty()) {
            cout << "The stack is empty." << endl;
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = elements.size() - 1; i >= 0; i--) {
                cout << elements[i] << " ";
            }
            cout << endl;
        }
    }
};

// Main function
int main() {
    Stack stack;
    int choice;

    do {
        cout << "\n----- Stack Operations -----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek (Top Element)" << endl;
        cout << "4. Check if Stack is Empty" << endl;
        cout << "5. Display Stack" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;
        }
        case 2:
            stack.pop();
            break;
        case 3:
            stack.peek();
            break;
        case 4:
            if (stack.isEmpty()) {
                cout << "The stack is empty." << endl;
            } else {
                cout << "The stack is not empty." << endl;
            }
            break;
        case 5:
            stack.display();
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

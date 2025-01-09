#include <iostream>
#include <string>
using namespace std;

// Queue class to simulate the order processing system
class PizzaQueue {
private:
    string* arr;         // Array to store orders (customer names)
    int front;           // Index of the front element
    int rear;            // Index of the rear element
    int capacity;        // Maximum capacity of the queue
    int size;            // Current size of the queue

public:
    // Constructor to initialize the queue
    PizzaQueue(int cap) {
        capacity = cap;
        arr = new string[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor to free allocated memory
    ~PizzaQueue() {
        delete[] arr;
    }

    // Enqueue operation: Add an order to the queue
    void enqueue(string order) {
        if (size == capacity) {
            cout << "Queue is full! Cannot take more orders." << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = order;
        size++;
        cout << "Order placed: " << order << endl;
    }

    // Dequeue operation: Process an order from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "No orders to process! The queue is empty." << endl;
            return;
        }
        cout << "Processing order: " << arr[front] << endl;
        front = (front + 1) % capacity; // Circular increment
        size--;
    }

    // Peek operation: Show the current front order
    void peek() {
        if (isEmpty()) {
            cout << "No orders to process! The queue is empty." << endl;
            return;
        }
        cout << "Current order at the front: " << arr[front] << endl;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Display all orders in the queue
    void display() {
        if (isEmpty()) {
            cout << "No orders in the queue." << endl;
            return;
        }
        cout << "Orders in the queue: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity; // Circular indexing
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    int capacity;
    cout << "Enter the maximum number of orders the queue can hold: ";
    cin >> capacity;

    PizzaQueue queue(capacity);
    int choice;

    do {
        cout << "\n----- Pizza Parlour Order Operations -----" << endl;
        cout << "1. Place a new order (Enqueue)" << endl;
        cout << "2. Process an order (Dequeue)" << endl;
        cout << "3. Check the next order (Peek)" << endl;
        cout << "4. Check if the queue is empty" << endl;
        cout << "5. Display all orders in the queue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string customerName;
            cout << "Enter customer name for the order: ";
            cin >> customerName;
            queue.enqueue(customerName);
            break;
        }
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.peek();
            break;
        case 4:
            if (queue.isEmpty()) {
                cout << "The queue is empty. No orders to process." << endl;
            } else {
                cout << "There are orders in the queue." << endl;
            }
            break;
        case 5:
            queue.display();
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

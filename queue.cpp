#include <iostream>
using namespace std;

// Queue class
class Queue {
private:
    int* arr;      // Array to store queue elements
    int front;     // Index of the front element
    int rear;      // Index of the rear element
    int capacity;  // Maximum capacity of the queue
    int size;      // Current size of the queue

public:
    // Constructor to initialize the queue
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Enqueue operation: Add an element to the rear
    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue overflow! Cannot enqueue " << value << "." << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = value;
        size++;
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    // Dequeue operation: Remove an element from the front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! The queue is empty." << endl;
            return;
        }
        cout << "Dequeued " << arr[front] << " from the queue." << endl;
        front = (front + 1) % capacity; // Circular increment
        size--;
    }

    // Peek operation: Get the front element without removing it
    void peek() {
        if (isEmpty()) {
            cout << "The queue is empty. No front element to display." << endl;
            return;
        }
        cout << "Front element is: " << arr[front] << endl;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "The queue is empty." << endl;
            return;
        }
        cout << "Queue elements (front to rear): ";
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
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    Queue queue(capacity);
    int choice;

    do {
        cout << "\n----- Queue Operations -----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek (Front Element)" << endl;
        cout << "4. Check if Queue is Empty" << endl;
        cout << "5. Display Queue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
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
                cout << "The queue is empty." << endl;
            } else {
                cout << "The queue is not empty." << endl;
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

#include <iostream>
using namespace std;

// Node class to represent each seat
class Seat {
public:
    int seatNumber;       // Seat number
    bool isBooked;        // Booking status
    Seat* next;           // Pointer to the next seat

    Seat(int number) {
        seatNumber = number;
        isBooked = false; // Initially, the seat is available
        next = nullptr;
    }
};

// LinkedList class to represent the row of seats
class SeatRow {
private:
    Seat* head;  // Head pointer to the first seat in the row

public:
    SeatRow() {
        head = nullptr;
    }

    // Add a seat to the row
    void addSeat(int seatNumber) {
        Seat* newSeat = new Seat(seatNumber);
        if (!head) {
            head = newSeat;
            return;
        }
        Seat* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newSeat;
    }

    // Display seat status
    void displaySeats() {
        if (!head) {
            cout << "No seats available!" << endl;
            return;
        }

        Seat* current = head;
        while (current) {
            cout << "Seat " << current->seatNumber << " - ";
            if (current->isBooked)
                cout << "Booked";
            else
                cout << "Available";
            cout << endl;
            current = current->next;
        }
    }

    // Book a seat
    void bookSeat(int seatNumber) {
        Seat* current = head;
        while (current) {
            if (current->seatNumber == seatNumber) {
                if (current->isBooked) {
                    cout << "Seat " << seatNumber << " is already booked!" << endl;
                } else {
                    current->isBooked = true;
                    cout << "Seat " << seatNumber << " has been successfully booked." << endl;
                }
                return;
            }
            current = current->next;
        }
        cout << "Seat " << seatNumber << " does not exist!" << endl;
    }

    // Cancel a booking
    void cancelBooking(int seatNumber) {
        Seat* current = head;
        while (current) {
            if (current->seatNumber == seatNumber) {
                if (!current->isBooked) {
                    cout << "Seat " << seatNumber << " is not booked yet!" << endl;
                } else {
                    current->isBooked = false;
                    cout << "Booking for seat " << seatNumber << " has been successfully canceled." << endl;
                }
                return;
            }
            current = current->next;
        }
        cout << "Seat " << seatNumber << " does not exist!" << endl;
    }
};


int main() {
    SeatRow row;

    
    for (int i = 1; i <= 30; i++) {
        row.addSeat(i);
    }

    

    int choice;

    do {
        cout << "\n----- Cinemax Theater Booking System -----" << endl;
        cout << "1. Display Seats" << endl;
        cout << "2. Book a Seat" << endl;
        cout << "3. Cancel Booking" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Seat Status:" << endl;
            row.displaySeats();
            break;
        case 2: {
            int seatNumber;
            cout << "Enter seat number to book: ";
            cin >> seatNumber;
            row.bookSeat(seatNumber);
            break;
        }
        case 3: {
            int seatNumber;
            cout << "Enter seat number to cancel booking: ";
            cin >> seatNumber;
            row.cancelBooking(seatNumber);
            break;
        }
        case 4:
            cout << "Exiting the system. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

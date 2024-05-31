#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
    int getId() { return id; }
private:
    int id;
    int capacity;
    int reserved;
    const double maxOverbookRatio = 1.05;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
    : id(id), capacity(capacity) {
    if (reserved < 0) {
        this->reserved = 0;
    }
    else if (reserved > static_cast<int>(capacity * maxOverbookRatio)) {
        this->reserved = static_cast<int>(capacity * maxOverbookRatio);
    }
    else {
        this->reserved = reserved;
    }
}

FlightBooking::FlightBooking() : id(0), capacity(0), reserved(0) {}

void FlightBooking::printStatus() {
    double percentage = static_cast<double>(reserved) / capacity * 100;
    cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << percentage << "%) seats taken" << endl;
}

bool FlightBooking::reserveSeats(int number_of_seats) {
    if (number_of_seats < 0 || reserved + number_of_seats > static_cast<int>(capacity * maxOverbookRatio)) {
        return false;
    }
    reserved += number_of_seats;
    return true;
}

bool FlightBooking::cancelReservations(int number_of_seats) {
    if (number_of_seats < 0 || reserved - number_of_seats < 0) {
        return false;
    }
    reserved -= number_of_seats;
    return true;
}

int findFlight(FlightBooking flights[], int size, int id) {
    for (int i = 0; i < size; ++i) {
        if (flights[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    FlightBooking flights[10];
    string command;

    while (true) {
        cout << "What would you like to do?: ";
        getline(cin, command);
        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "quit") {
            break;
        }
        else if (action == "create") {
            int id, capacity;
            ss >> id >> capacity;
            if (findFlight(flights, 10, id) != -1) {
                cout << "Cannot perform this operation: Flight with ID " << id << " already exists." << endl;
            }
            else {
                bool created = false;
                for (int i = 0; i < 10; ++i) {
                    if (flights[i].getId() == 0) {
                        flights[i] = FlightBooking(id, capacity, 0);
                        flights[i].printStatus();
                        created = true;
                        break;
                    }
                }
                if (!created) {
                    cout << "Cannot perform this operation: Maximum number of flights reached." << endl;
                }
            }
        }
        else if (action == "delete") {
            int id;
            ss >> id;
            int index = findFlight(flights, 10, id);
            if (index == -1) {
                cout << "Cannot perform this operation: Flight with ID " << id << " does not exist." << endl;
            }
            else {
                flights[index] = FlightBooking();
                cout << "Flight " << id << " deleted." << endl;
            }
        }
        else if (action == "add") {
            int id, number_of_seats;
            ss >> id >> number_of_seats;
            int index = findFlight(flights, 10, id);
            if (index == -1) {
                cout << "Cannot perform this operation: Flight with ID " << id << " does not exist." << endl;
            }
            else if (!flights[index].reserveSeats(number_of_seats)) {
                cout << "Cannot perform this operation: Exceeds maximum capacity." << endl;
            }
            else {
                flights[index].printStatus();
            }
        }
        else if (action == "cancel") {
            int id, number_of_seats;
            ss >> id >> number_of_seats;
            int index = findFlight(flights, 10, id);
            if (index == -1) {
                cout << "Cannot perform this operation: Flight with ID " << id << " does not exist." << endl;
            }
            else if (!flights[index].cancelReservations(number_of_seats)) {
                cout << "Cannot perform this operation: Not enough seats to cancel." << endl;
            }
            else {
                flights[index].printStatus();
            }
        }
        else {
            cout << "Unknown command" << endl;
        }
    }

    return 0;
}
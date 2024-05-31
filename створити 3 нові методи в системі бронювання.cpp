#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <Windows.h>

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool addReservations(int n);
    bool cancelReservations(int n);

private:
    int id;
    int capacity;
    int reserved;
    int maxReservations;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
    : id(id), capacity(capacity) {
    maxReservations = static_cast<int>(capacity * 1.05);
    if (reserved > maxReservations) {
        this->reserved = maxReservations;
    }
    else if (reserved < 0) {
        this->reserved = 0;
    }
    else {
        this->reserved = reserved;
    }
}

void FlightBooking::printStatus() {
    double percentage = static_cast<double>(reserved) / capacity * 100;
    std::cout << "Рейс " << id << " : " << reserved << "/" << capacity
        << " (" << std::fixed << std::setprecision(1) << percentage
        << "%) місць зарезервовано" << std::endl;
}

bool FlightBooking::addReservations(int n) {
    if (reserved + n > maxReservations) {
        return false;
    }
    reserved += n;
    return true;
}

bool FlightBooking::cancelReservations(int n) {
    if (reserved - n < 0) {
        return false;
    }
    reserved -= n;
    return true;
}

int main() {
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    int reserved = 0, capacity = 0;
    std::cout << "Вкажіть місткість рейсу: ";
    std::cin >> capacity;
    std::cout << "Вкажіть кількість зарезервованих місць: ";
    std::cin >> reserved;

    FlightBooking booking(1, capacity, reserved);
    booking.printStatus();

    std::string command;
    std::cin.ignore(); 

    while (true) {
        std::cout << "Команда: ";
        std::getline(std::cin, command);

        if (command == "quit") {
            break;
        }

        std::istringstream iss(command);
        std::string action;
        int n;
        iss >> action >> n;

        if (action == "add") {
            if (!booking.addReservations(n)) {
                std::cout << "Не вдається виконати цю операцію" << std::endl;
            }
        }
        else if (action == "cancel") {
            if (!booking.cancelReservations(n)) {
                std::cout << "Не вдається виконати цю операцію" << std::endl;
            }
        }
        else {
            std::cout << "Невідома команда" << std::endl;
        }

        booking.printStatus();
    }

    return 0;
}
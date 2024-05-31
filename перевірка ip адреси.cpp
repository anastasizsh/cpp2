#include <iostream>
#include <iomanip> 
#include <Windows.h>

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
    : id(id), capacity(capacity), reserved(reserved) {}

void FlightBooking::printStatus() {
    double percentage = static_cast<double>(reserved) / capacity * 100;
    std::cout << "Рейс " << id << " : " << reserved << "/" << capacity
        << " (" << std::fixed << std::setprecision(1) << percentage
        << "%) місць зарезервовано" << std::endl;
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

    return 0;
}
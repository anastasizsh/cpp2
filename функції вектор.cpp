#include <iostream>
#include <vector>
#include <Windows.h>

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

int monthLength(int year, int month) {
    std::vector<int> daysInMonth = { 31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month < 1 || month > 12) {
        return 0;
    }
    return daysInMonth[month - 1];
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 

    int year, month;
    std::cout << "Введіть рік: ";
    std::cin >> year;
    std::cout << "Введіть місяць (1-12): ";
    std::cin >> month;

    int days = monthLength(year, month);
    if (days == 0) {
        std::cout << "Неправильний місяць!" << std::endl;
    }
    else {
        std::cout << "Кількість днів у місяці: " << days << std::endl;
    }

    return 0;
}
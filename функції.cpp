#include <iostream>
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
    switch (month) {
    case 1: return 31;
    case 2: return isLeapYear(year) ? 29 : 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    default: return 0; 
    }
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
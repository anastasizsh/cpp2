#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

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

Date today() {
    time_t t = time(NULL);
    tm tl;
    localtime_s(&tl, &t);
    Date current_date;
    current_date.year = tl.tm_year + 1900;
    current_date.month = tl.tm_mon + 1;
    current_date.day = tl.tm_mday;
    return current_date;
}

int daysPassedSinceBirthday(const Date& birthday) {
    Date current_date = today();
    int daysPassed = 0;

    
    for (int year = birthday.year; year < current_date.year; ++year) {
        for (int month = 1; month <= 12; ++month) {
            daysPassed += monthLength(year, month);
        }
    }

    
    for (int month = 1; month < current_date.month; ++month) {
        daysPassed += monthLength(current_date.year, month);
    }
    daysPassed += current_date.day;

    
    for (int month = 1; month < birthday.month; ++month) {
        daysPassed -= monthLength(birthday.year, month);
    }
    daysPassed -= birthday.day;

    return daysPassed;
}

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    Date birthday;
    cout << "Введіть свій день народження (рік, місяць, день): ";
    cin >> birthday.year >> birthday.month >> birthday.day;

    int daysPassed = daysPassedSinceBirthday(birthday);
    cout << "Кількість днів, що пройшли від вашого дня народження: " << daysPassed << endl;

    return 0;
}
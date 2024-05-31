#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <Windows.h>

bool isValidPassword(const std::string& password) {
    bool validLength = password.length() >= 8;
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    for (char ch : password) {
        if (isupper(ch)) {
            hasUpperCase = true;
        }
        else if (islower(ch)) {
            hasLowerCase = true;
        }
        else if (isdigit(ch)) {
            hasDigit = true;
        }
        else if (!isalnum(ch)) {
            hasSpecialChar = true;
        }
    }

    return validLength && hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar;
}

int main() {
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    std::string пароль;
    std::cout << "Введіть ваш пароль: ";
    std::getline(std::cin, пароль);

    if (isValidPassword(пароль)) {
        std::cout << "Пароль є валідним" << std::endl;
    }
    else {
        std::cout << "Пароль не валідний. Причини:" << std::endl;
        if (пароль.length() < 8) {
            std::cout << "- Пароль повинен бути довжиною не менше 8 символів" << std::endl;
        }
        if (!std::any_of(пароль.begin(), пароль.end(), ::isupper)) {
            std::cout << "- Пароль повинен містити принаймні одну літеру верхнього регістру" << std::endl;
        }
        if (!std::any_of(пароль.begin(), пароль.end(), ::islower)) {
            std::cout << "- Пароль повинен містити принаймні одну літеру нижнього регістру" << std::endl;
        }
        if (!std::any_of(пароль.begin(), пароль.end(), ::isdigit)) {
            std::cout << "- Пароль повинен містити принаймні одну цифру" << std::endl;
        }
        if (!std::any_of(пароль.begin(), пароль.end(), ::ispunct)) {
            std::cout << "- Пароль повинен містити принаймні один спеціальний символ" << std::endl;
        }
    }

    return 0;
}
#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
  
    cout << "Прості числа від 0 до 21:" << endl;
    for (int i = 0; i <= 21; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
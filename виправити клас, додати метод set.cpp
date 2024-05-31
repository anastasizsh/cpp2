#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Square {
private:
    double side;
    double area;

    void updateArea() {
        area = side * side;
    }

public:
    Square(double side) {
        set_side(side);
    }

    void set_side(double side) {
        if (side >= 0) {
            this->side = side;
            updateArea();
        }
    }

    void print() const {
        cout << "Квадрат: сторона=" << side << ", площа=" << area << endl;
    }
};

int main() {
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    Square s(4);
    s.print();
    s.set_side(2.0);
    s.print();
    s.set_side(-33.0);
    s.print();
    return 0;
}
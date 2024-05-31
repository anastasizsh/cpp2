#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class AdHocSquare {
public:
    AdHocSquare(double side) : side(side) {}

    void set_side(double side) {
        if (side >= 0) {
            this->side = side;
        }
    }

    double get_area() const {
        return side * side;
    }

private:
    double side;
};

class LazySquare {
public:
    LazySquare(double side) : side(side), area(side* side), side_changed(false) {}

    void set_side(double side) {
        if (side >= 0) {
            this->side = side;
            side_changed = true;
        }
    }

    double get_area() {
        if (side_changed) {
            area = side * side;
            side_changed = false;
        }
        return area;
    }

private:
    double side;
    double area;
    bool side_changed;
};

int main() {
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    AdHocSquare adHocSquare(4);
    cout << "AdHocSquare: сторона = " << 4 << ", площа = " << adHocSquare.get_area() << endl;
    adHocSquare.set_side(2.0);
    cout << "AdHocSquare: сторона = " << 2 << ", площа = " << adHocSquare.get_area() << endl;
    adHocSquare.set_side(-33.0);
    cout << "AdHocSquare: сторона = " << 2 << ", площа = " << adHocSquare.get_area() << endl;

    LazySquare lazySquare(4);
    cout << "LazySquare: сторона = " << 4 << ", площа = " << lazySquare.get_area() << endl;
    lazySquare.set_side(2.0);
    cout << "LazySquare: сторона = " << 2 << ", площа = " << lazySquare.get_area() << endl;
    lazySquare.set_side(-33.0);
    cout << "LazySquare: сторона = " << 2 << ", площа = " << lazySquare.get_area() << endl;

    return 0;
}
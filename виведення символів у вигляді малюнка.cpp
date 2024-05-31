#include <iostream>
#include <Windows.h>
using namespace std;


class Tree {
public:
    virtual void draw() const = 0; 
    virtual ~Tree() {} 
};


class Tree1 : public Tree {
public:
    void draw() const override {
        cout << "Малюнок 1:" << endl;
        cout << "  /\\  " << endl;
        cout << " //\\\\" << endl;
    }
};


class Tree2 : public Tree {
public:
    void draw() const override {
        cout << "Малюнок 2:" << endl;
        cout << "  /\\  " << endl;
        cout << " /**\\" << endl;
    }
};


class Tree3 : public Tree {
public:
    void draw() const override {
        cout << "Малюнок 3:" << endl;
        cout << "  /\\  " << endl;
        cout << " /++\\" << endl;
    }
};

int main() {
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    
    Tree* trees[3];

    
    Tree1 tree1;
    Tree2 tree2;
    Tree3 tree3;

    
    trees[0] = &tree1;
    trees[1] = &tree2;
    trees[2] = &tree3;

    
    for (int i = 0; i < 3; ++i) {
        trees[i]->draw();
    }

    return 0;
}
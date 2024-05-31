#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Person {
public:
    string name;
    int age;
    string address;   
    string phoneNumber; 
    
    void print() const {
        cout << name << " йому " << age << " років, проживає  " << address << ", можна зв'язатися за: " << phoneNumber << "." << endl;
    }
};

int main() {
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення

    Person person;
    person.name = "Олександр";
    person.age = 26;
    person.address = "Солом'янська 24, Київ, Україна"; 
    person.phoneNumber = "123-456-7890"; 

    cout << "Знайомтесь " << person.name << endl;
    person.print();

    return 0;
}
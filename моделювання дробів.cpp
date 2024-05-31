#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
private:
    int numerator;
    int denominator;
    int gcd(int a, int b);  
};

Fraction::Fraction(int numerator, int denominator) {
    
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    this->numerator = numerator;
    this->denominator = denominator;

    
    int divisor = gcd(abs(numerator), denominator);
    this->numerator /= divisor;
    this->denominator /= divisor;
}

int Fraction::gcd(int a, int b) {
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

string Fraction::toString() {
    int wholePart = numerator / denominator;
    int remainder = abs(numerator % denominator);

    stringstream ss;
    if (wholePart != 0) {
        ss << wholePart;
        if (remainder != 0) {
            ss << " " << remainder << "/" << denominator;
        }
    }
    else {
        ss << numerator << "/" << denominator;
    }
    return ss.str();
}

double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

int main() {
    int num, den;
    string input;

    cout << "Enter a fraction (numerator / denominator): ";
    getline(cin, input);

    
    stringstream ss(input);
    char slash;
    ss >> num >> slash >> den;

    if (den == 0) {
        cout << "Denominator cannot be zero." << endl;
        return 1;
    }

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    return 0;
}
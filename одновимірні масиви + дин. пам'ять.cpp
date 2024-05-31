#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned int>(time(0)));

    int n;
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    float* array = new float[n];


    for (int i = 0; i < n; ++i) {
        array[i] = -2.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 4.0f)); 
    }


    cout << "Масив: ";
    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(2) << array[i] << " ";
    }
    cout << endl;


    int positiveCount = 0;
    int negativeCount = 0;

    for (int i = 0; i < n; ++i) {
        if (array[i] > 0) {
            ++positiveCount;
        }
        else if (array[i] < 0) {
            ++negativeCount;
        }
    }

    cout << "Кількість додатних чисел: " << positiveCount << endl;
    cout << "Кількість від'ємних чисел: " << negativeCount << endl;


    delete[] array;

    return 0;
}
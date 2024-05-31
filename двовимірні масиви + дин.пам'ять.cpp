#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>


using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned int>(time(0)));

    const int rows = 3;
    const int cols = 3;

   
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100; 
        }
    }

    
    cout << "Масив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    
    cout << "Головна діагональ: ";
    for (int i = 0; i < rows; ++i) {
        cout << matrix[i][i] << " ";
    }
    cout << endl;

    
    cout << "Побічна діагональ: ";
    for (int i = 0; i < rows; ++i) {
        cout << matrix[i][cols - 1 - i] << " ";
    }
    cout << endl;

    
    int evenCount = 0;
    int oddCount = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] % 2 == 0) {
                ++evenCount;
            }
            else {
                ++oddCount;
            }
        }
    }

    cout << "Кількість парних елементів: " << evenCount << endl;
    cout << "Кількість непарних елементів: " << oddCount << endl;

    
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
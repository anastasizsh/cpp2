#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale> 

using namespace std;

int main() {
    setlocale(LC_ALL, ""); 
    wcout.imbue(locale("")); 

    srand(time(0)); 

    const int rows = 5;
    const int cols = 5;
    int matrix[rows][cols];

    
    for (int(*rowPtr)[cols] = matrix; rowPtr < matrix + rows; ++rowPtr) {
        for (int* colPtr = *rowPtr; colPtr < *rowPtr + cols; ++colPtr) {
            *colPtr = rand() % 100; 
        }
    }

    
    wcout << L"Масив:" << endl;
    for (int(*rowPtr)[cols] = matrix; rowPtr < matrix + rows; ++rowPtr) {
        for (int* colPtr = *rowPtr; colPtr < *rowPtr + cols; ++colPtr) {
            wcout << *colPtr << L"\t";
        }
        wcout << endl;
    }

    
    wcout << L"Головна діагональ: ";
    for (int i = 0; i < rows; ++i) {
        wcout << *(*(matrix + i) + i) << L" ";
    }
    wcout << endl;

    
    wcout << L"Побічна діагональ: ";
    for (int i = 0; i < rows; ++i) {
        wcout << *(*(matrix + i) + (cols - 1 - i)) << L" ";
    }
    wcout << endl;

    
    int evenCount = 0;
    int oddCount = 0;

    for (int(*rowPtr)[cols] = matrix; rowPtr < matrix + rows; ++rowPtr) {
        for (int* colPtr = *rowPtr; colPtr < *rowPtr + cols; ++colPtr) {
            if (*colPtr % 2 == 0) {
                ++evenCount;
            }
            else {
                ++oddCount;
            }
        }
    }

    wcout << L"Кількість парних елементів: " << evenCount << endl;
    wcout << L"Кількість непарних елементів: " << oddCount << endl;

    return 0;
}
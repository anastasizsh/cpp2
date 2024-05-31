#include <iostream>
using namespace std;

int main(void) {
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int n = sizeof(vector) / sizeof(vector[0]);

    int* ptr = vector;
    int min = *ptr;
    for (int* p = vector + 1; p < vector + n; ++p) {
        if (*p < min) {
            min = *p;
        }
    }

    cout << "Smallest number: " << min << endl;

    return 0;
}
#include <iostream>
#include "ArrayUtility.h"
using namespace std;

void doStuff();

int main() {
    doStuff();
    return 0;
}

void doStuff() {
    ArrayUtility au;
    const int SIZE = 10;
    int numbers[SIZE];

    if (!au.readNumbers(numbers, SIZE)) {
        cout << "Cannot read file. "
             << "Something went wrong." << endl;
        return;
    }

    au.selectionSort(numbers, SIZE);
    au.displayNumbers(numbers, SIZE);

    if (!au.writeNumbers(numbers, SIZE)) {
        cout << "Cannot write file. "
             << "Something went wrong." << endl;
        return;
    }

    cout << endl;
    cout << "Average: " << au.calcAvg(numbers, SIZE);
}
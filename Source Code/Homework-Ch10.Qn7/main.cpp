#include "MovieStats.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    MovieStats ms;
    int count;

    cout << "Hi!" << endl;
    cout << "Please enter the number of students surveyed." << endl << endl;

    cout << "  N: ";
    cin >> count;
    ms.setNumRecords(count);

    cout << endl;
    cout << "Please enter the number of movies " << endl
         << "each student has seen as prompted." << endl << endl;

    for (int i = 0; i < count; i++) {
        int temp;
        cout << "  Student " << i + 1 << ": ";
        cin >> temp;
        ms.setRecordByIndex(i, temp);
    }

    cout << endl;
    cout << "Statistical Data: "
         << endl << endl;

    cout << "  "; ms.printMean();
    cout << "  "; ms.printMedian();
    cout << "  "; ms.printMode();

    cout << endl;
    cout << "The program is done." << endl;

    return 0;
}
#include "TestList.h"
#include <iostream>
using namespace std;

int main() {
    TestList tl;
    int listLength = 0;

    cout << "Please enter the number of scores: ";
    cin >> listLength;
    while (listLength <= 0) {
        cout << "  Enter a positive integer: ";
        cin >> listLength;
    }
    tl.setListLength( listLength );
    cout << endl;

    cout << "You will now be prompted for test scores. " << endl;
    tl.promptTestScores();
    tl.sortTestScores();
    cout << endl;

    cout << "Here are the data." << endl;
    tl.printTestScores();
    tl.printAverage();

    return 0;
}
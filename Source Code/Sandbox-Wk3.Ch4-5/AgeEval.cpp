#include <iostream>
#include "AgeEval.h"
using namespace std;

void AgeEval::getAgeFromUser() {
    cout << "What is your age? ";
    cin >> age;

    return;
}

void AgeEval::printMessage() {
    if (age > 60) {
        if (age > 100) {
            cout << "How are you still alive?!";
        } else {
            cout << "Wow, you are old!";
        }
    } else {
        cout << "You're young. Get a job!";
    }

    cout << endl;
    return;
}

void AgeEval::executeCode() {
    getAgeFromUser();
    printMessage();
}
#include <iostream>
#include <iomanip>
#include "ProceduralSandbox.h"
using namespace std;

void ProceduralSandbox::toggleCase() {
    char input, toggledInput;

    cout << "Enter any character: ";
    cin.get(input);

    cout << "The character you entered is: " << input << endl;
    cout << "Its ASCII code is: " << static_cast<int>(input) << endl << endl;

    if (islower(input)) {
        cout << "The letter you entered is lowercase.\n";
        toggledInput = toupper(input);
        cout << "In uppercase, that is: " << toggledInput << endl;
        cout << "Its ASCII code is: " << static_cast<int>(toggledInput) << endl;
    }

    if (isupper(input)) {
        cout << "The letter you entered is uppercase.\n";
        toggledInput = tolower(input);
        cout << "In lowercase, that is: " << toggledInput << endl;
        cout << "Its ASCII code is: " << static_cast<int>(toggledInput) << endl;
    }

    return;
}

void ProceduralSandbox::conditionalOp() {
    const double PAY_RATE = 50.0;
    const int MIN_HOURS = 5;
    double hours,
            charges;

    cout << "How many hours were worked? ";
    cin >> hours;

    if (hours < MIN_HOURS) hours = MIN_HOURS;
    // hours = hours < MIN_HOURS ? MIN_HOURS : hours;

    charges = PAY_RATE * hours;
    cout << fixed << showpoint << setprecision(2)
         << "The charges are $" << charges << endl;

    return;
}

void ProceduralSandbox::birthdayEnumeration() {
    enum Roster { Tom = 608, Sharon = 271, Bill = 689, Teresa = 543, John = 807 };

    int who;

    cout << "This program will give you a student's birthday.\n";
    cout << "Whose birthday do you want to know?\n";
    cout << Tom << " = Tom\n";
    cout << Sharon << " = Sharon\n";
    cout << Bill << " = Bill\n";
    cout << Teresa << " = Teresa\n";
    cout << John << " = John\n";
    cin  >> who;

    switch (who)
    {
        case Tom	:	cout << "\nTom's birthday is January 3.\n";
            break;
        case Sharon	:	cout << "\nSharon's birthday is April 22.\n";
            break;
        case Bill	:	cout << "\nBill's birthday is December 19.\n";
            break;
        case Teresa	:	cout << "\nTeresa's birthday is February 2.\n";
            break;
        case John	:	cout << "\nJohn's birthday is June 17.\n";
            break;
        default		:	cout << "\nInvalid selection\n";
    }
    return;
}
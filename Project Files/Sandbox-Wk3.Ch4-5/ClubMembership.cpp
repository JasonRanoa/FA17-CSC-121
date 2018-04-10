#include <iostream>
#include <iomanip>
#include "ClubMembership.h"
using namespace std;

void ClubMembership::showMenu() {
    cout << "   Health Club Membership Menu\n\n";
    cout << "1. Standard Adult Membership\n";
    cout << "2. Child Membership\n";
    cout << "3. Senior Citizen Membership\n";
    cout << "4. Quit the Program\n\n";
    cout << "Enter your choice: ";
    cin  >> choice;

    return;
}

void ClubMembership::askMonths() {
    cout << "For how many months? ";
    cin >> months;

    return;
}

void ClubMembership::calculateCharges() {
    switch (choice) {
        case 1:
            charges = months * ADULT_RATE;
            break;
        case 2:
            charges = months * CHILD_RATE;
            break;
        case 3:
            charges = months * SENIOR_RATE;
            break;
        default:
            charges = 0;
    }

    return;
}

void ClubMembership::printCharges() {
    cout << fixed << showpoint << setprecision(2);
    cout << "\nThe total charges are $" << charges << endl;

    return;
}

void ClubMembership::runMe() {
    showMenu();
    if ( choice >= 1 && choice <= 3 ) {
        askMonths();
        calculateCharges();
        printCharges();
    } else if (choice != 4) {
        cout << "\nThe valid choices are 1 through 4.\n"
             << "Run the program again and select one of those.\n";
    }

    return;
}

void ClubMembership::proceduralClub() {
    // Constants for membership rates
    const double ADULT_RATE  = 120.0;
    const double CHILD_RATE  =  60.0;
    const double SENIOR_RATE = 100.0;

    int choice;           // Menu choice
    int months;           // Number of months
    double charges;       // Monthly charges

    // Display the menu and get the user's choice
    cout << "   Health Club Membership Menu\n\n";
    cout << "1. Standard Adult Membership\n";
    cout << "2. Child Membership\n";
    cout << "3. Senior Citizen Membership\n";
    cout << "4. Quit the Program\n\n";
    cout << "Enter your choice: ";
    cin  >> choice;

    // Set the numeric output formatting
    cout << fixed << showpoint << setprecision(2);

    // Use the menu selection to execute the correct set of actions
    switch (choice) {
        case 1:
            cout << "For how many months? ";
            cin >> months;
            charges = months * ADULT_RATE;
            cout << "\nThe total charges are $" << charges << endl;
            break;
        case 2:
            cout << "For how many months? ";
            cin >> months;
            charges = months * CHILD_RATE;
            cout << "\nThe total charges are $" << charges << endl;
            break;
        case 3:
            cout << "For how many months? ";
            cin >> months;
            charges = months * SENIOR_RATE;
            cout << "\nThe total charges are $" << charges << endl;
            break;
        case 4:
            break;
        default:
            cout << "\nThe valid choices are 1 through 4.\n"
                 << "Run the program again and select one of those.\n";
    }

    return;
}
#include "Inventory.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool safeGetInteger(int&);
bool safeGetDouble(double&);
void printStuff(Inventory);

int main() {
    Inventory inv;
    int tempN;
    double tempD;

    cout << "Hi! Please enter information as prompted." << endl << endl;

    cout << "  Item Number : ";
    while ( !safeGetInteger(tempN) ) {
        cout << "    Invalid input. Try again: ";
    }
    inv.setItemNumber(tempN);

    cout << "  Quantity    : ";
    while ( !safeGetInteger(tempN) ) {
        cout << "    Invalid input. Try again: ";
    }
    inv.setQuantity(tempN);

    cout << "  Cost        : ";
    while ( !safeGetDouble(tempD) ) {
        cout << "    Invalid input. Try again: ";
    }
    inv.setCost(tempD);

    cout << endl;
    printStuff(inv);

    return 0;
}

bool safeGetInteger(int &n) {
    string raw_input;
    getline(cin, raw_input);
    try {
        n = stoi(raw_input);
        return true;
    } catch (exception &e) { return false; }
}

bool safeGetDouble(double &d) {
    string raw_input;
    getline(cin, raw_input);
    try {
        d = stod(raw_input);
        return true;
    } catch (exception &e) { return false; }
}

void printStuff(Inventory inv) {
    string border;
    border.assign(35, '-');

    cout << border << endl << endl;
    cout << " INVENTORY INFORMATION" << endl << endl;
    cout << " Item Number : " << inv.getItemNumber() << endl;
    cout << " Quantity    : " << inv.getQuantity() << " items" << endl;
    cout << " Cost        : $ " << fixed << showpoint << setprecision(2)
         << inv.getCost() << " per item" << endl;
    cout << " Total Cost  : $ " << fixed << showpoint << setprecision(2)
         << inv.getTotalCost() << endl;

    cout << endl << border << endl;
}
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "RsBillCalculator.h"

void RsBillCalculator::retrieveMealCharge() {
    cout << "Meal Cost? ";
    cin >> mealCost;

    cout << endl;
    return;
}

void RsBillCalculator::doBreakdown() {
    taxAmount = mealCost * taxRate;
    tipCost = (mealCost + taxAmount) * tipRate;
    totalAmount = taxAmount + tipCost + mealCost;

    return;
}

void RsBillCalculator::printResults() {
    int headerWidth = 15;
    int valueWidth = 8;

    string border;
    border.assign( headerWidth + 1 + valueWidth, '-');
    cout << fixed << showpoint << setprecision(2);

    cout << border << endl << endl;

    cout << left << setw(headerWidth) << "Meal Cost: ";
    cout << "$" << right << setw(valueWidth) << mealCost << endl;

    cout << left << setw(headerWidth) << "Tax Amount: ";
    cout << "$" << right << setw(valueWidth) << taxAmount << endl;

    cout << left << setw(headerWidth) << "Tip Amount: ";
    cout << "$" << right << setw(valueWidth) << tipCost << endl;

    cout << left << setw(headerWidth) << "Total Charge: ";
    cout << "$" << right << setw(valueWidth) << totalAmount << endl;

    cout << endl << border << endl << endl;

    return;
}

void RsBillCalculator::run() {
    retrieveMealCharge();
    doBreakdown();
    printResults();

    return;
}
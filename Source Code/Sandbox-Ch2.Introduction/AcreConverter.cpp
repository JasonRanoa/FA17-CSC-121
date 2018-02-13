#include <iostream>
#include <iomanip>
#include "AcreConverter.h"
using namespace std;

void AcreConverter::getAcres() {
    valAcre = .5;

    return;
}

void AcreConverter::calculateStuff() {
    valSqFeet = valAcre * sqFeet_perAcre;
    valSqMeters = valSqFeet / sqFeet_perSqMeter;

    return;
}

void AcreConverter::printResults() {
    cout << fixed << showpoint << setprecision(2);

    cout << "Given Acres: " << valAcre << " acres. " << endl;
    cout << "Calculated Values. " << endl;

    cout << "    " << valSqMeters << " square meters. " << endl;
    cout << "    " << valSqFeet << " square feet. " << endl;

    cout << endl;
    return;
}

void AcreConverter::run() {
    getAcres();
    calculateStuff();
    printResults();
}
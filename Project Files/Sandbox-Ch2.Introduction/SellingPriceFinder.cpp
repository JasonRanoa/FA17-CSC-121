#include <iostream>
#include <iomanip>
using namespace std;

#include "SellingPriceFinder.h"

void SellingPriceFinder::getStartingData() {
    productionCost = 14.95;
    profitPercentage = .35;

    return;
}

void SellingPriceFinder::determinePrice() {
    profitVal = productionCost * profitPercentage;
    sellingPrice = profitVal + productionCost;

    return;
}

void SellingPriceFinder::printResults() {
    cout << "For you to make a ";
    cout << fixed << setprecision(0) << (profitPercentage * 100) << "% profit margin, " << endl;

    cout << "  given that production costs per item is $";
    cout << setprecision(2) << productionCost << ", " << endl;
    cout << "  you would need to sell the product at ..." << endl << endl;

    cout << setprecision(2);
    cout << "      " << "$" << sellingPrice << endl;

    cout << endl;
    return;
}

void SellingPriceFinder::run() {
    getStartingData();
    determinePrice();
    printResults();
}
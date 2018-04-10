#include <iostream>
#include <string>
#include <iomanip>
#include "BoxOffice.h"
using namespace std;

void BoxOffice::getInfo() {
    cout << "Hi!" << endl;
    cout << "Please enter the following information: " << endl << endl;

    cout << "Movie Name? ";
    getline( cin, movieName );
    cout << "Adult Tickets Sold? ";
    cin >> adultTickets;
    cout << "Child Tickets Sold? ";
    cin >> childTickets;

    cout << endl;
    return;
}

void BoxOffice::calculateRevenue() {
    grossRevenue  = adultTickets * adultCost;
    grossRevenue += childTickets * childCost;

    distributorCut = grossRevenue * distributorRate;
    netRevenue = grossRevenue - distributorCut;

    return;
}

void BoxOffice::printReport() {
    // Width for the money-related info.
    int costWidth = 7;
    string border;

    border.assign( firstColWidth + movieName.length() + 2, '-');

    cout << border << endl << endl;

    // User input information
    cout << left << setw(firstColWidth) << "Movie Name: ";
    cout << "\"" << movieName << "\"" << endl;

    cout << left << setw(firstColWidth) << "Adult Tickets Sold: ";
    cout << adultTickets << endl;

    cout << left << setw(firstColWidth) << "Child Tickets Sold: ";
    cout << childTickets << endl;

    // Calculated Information

    cout << fixed << showpoint << setprecision(2);

    cout << left << setw(firstColWidth - 1) << "Gross Box Office Revenue: ";
    cout << " $ " << right << setw(costWidth) << grossRevenue << endl;

    cout << left << setw(firstColWidth - 1) << "Amount Paid to Distributor: ";
    cout << "-$ " << right << setw(costWidth) << distributorCut << endl;

    cout << left << setw(firstColWidth - 1) << "Net Box Office Revenue: ";
    cout << " $ " << right << setw(costWidth) << netRevenue << endl;

    cout << endl << border << endl;

    return;
}
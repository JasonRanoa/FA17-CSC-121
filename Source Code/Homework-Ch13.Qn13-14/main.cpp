#include "Driver.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    Driver d;
    string source = "hwdata.dat";

    cout << "Loading all records from " << source << "..." << endl;
    d.deserializeAll(source);
    if (!d.good()) {
        cout << endl;
        cout << "This program cannot use " << source << endl;
        cout << "That file, if it exists, will be overwritten. " << endl << endl;
        cout << "Please enter the information for the new file.";
        d.getInput();
        d.serializeAll(source);
        cout << "The file, " << source << ", has been saved. Please restart the program.";
        return -1;
    }

    d.doCalculations();
    cout << "Doing analysis. Here are the results." << endl << endl;

    cout << "The total yearly sales per quarter across all divisions: " << endl << endl;
    cout << "  Q  Sales " << endl;
    cout << "  -  ------------" << endl;
    cout << fixed << showpoint;
    for (numValuePair nv : d.getTotalQuarterlySales()) {
        cout << "  ";
        cout << setw(1) << setprecision(0) << nv.num << "  ";
        cout << setw(12) << setprecision(2) << right << nv.value << endl;
    }
    cout << endl;

    cout << "The total yearly sales per division across all quarters: " << endl << endl;
    cout << "  Division  Sales " << endl;
    cout << "  --------  ------------" << endl;
    cout << fixed << showpoint;
    for (nameValuePair nv : d.getTotalDivisionSales()) {
        cout << "  ";
        cout << setw(8) << left << nv.name << "  ";
        cout << setw(12) << setprecision(2) << right << nv.value << endl;
    }
    cout << endl;

    cout << "The following are aggregate stats. " << endl << endl;
    cout << "  Total Yearly Sales: " << setprecision(2) << d.getTotalSales() << endl;
    cout << "  Average Yearly Sales: " << setprecision(2) << d.getAverageSales() << endl;
    cout << "  Highest Corporate Quarter: "
            << "Quarter " << d.getHighestCorporateQuarter().num
            << " with $" << d.getHighestCorporateQuarter().value << endl;
    cout << "  Lowest Corporate Quarter: "
         << "Quarter " << d.getLowestCorporateQuarter().num
         << " with $" << d.getLowestCorporateQuarter().value << endl;
    cout << endl;

    cout << "The program is done." << endl;
    // cout << "For reference, here are all the records saved in " << source << endl << endl;
    // d.printAll();

    return 0;
}
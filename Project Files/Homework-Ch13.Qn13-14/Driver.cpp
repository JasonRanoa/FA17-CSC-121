//
// Created by TheLoneWoof on 11/14/17.
//

#include "Driver.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Driver::serializeAll(std::string filename) {
    ofstream file(filename, ios::binary);
    if (file) {
        for (CorporateSales cs : records) {
            cs.serialize(file);
        }
    }
}

void Driver::deserializeAll(std::string filename) {
    ifstream file(filename, ios::binary);
    if (file) {
        while(file.good() && file.peek() != EOF) {
            CorporateSales cs;
            cs.deserialize(file);
            records.push_back(cs);
        }
        isGood = true;
    } else isGood = false;
}

void Driver::getInput() {
    vector<string> divisions = {
        "North", "South", "East", "West"
    };
    vector<int> quarters = {
        1, 2, 3, 4
    };
    double temp;

    records.clear();
    cout << "Please enter information as prompted." << endl;
    for (string div : divisions) {
        cout << "  Division: " << div << endl;
        for (int q : quarters) {
            cout << "  |  Enter sales for Quarter " << q << ": ";
            cin >> temp;
            records.push_back(CorporateSales(div, q, temp));
        }
        cout << endl;
    }
}

void Driver::printAll() {
    cout << "  "
         << "Division " // 9
         << "Q " // 2
         << "Sales     " << endl; // 10
    cout << "  "
         << "-------- "
         << "- "
         << "----------" << endl;

    cout << fixed << showpoint;
    for (CorporateSales cs : records ) {
        cout << "  ";
        cout << setw(8) << left << cs.getName() << " ";
        cout << setw(1) << cs.getQuarter() << " ";
        cout << setw(10) << setprecision(2) << right << cs.getSales();
        cout << endl;
    }
}

void Driver::randomize() {
    vector<string> divs = { "North", "South", "East", "West" };
    vector<int> qs = {1, 2, 3, 4};

    srand(time(NULL));
    for (string div : divs) {
        for (int q : qs) {
            records.push_back(
                CorporateSales(div, q, rand() % 1000 + 1)
            );
        }
    }
}

void Driver::doCalculations() {
    calcTotalQuarterlySales();
    calcTotalDivisionSales();
    calcTotalnAverageSales();
    findExtrema();
}

void Driver::calcTotalQuarterlySales() {
    totalQuarterlySales = {
        {1, 0}, {2, 0}, {3, 0}, {4, 0}
    };

    for (CorporateSales cs : records) {
        switch (cs.getQuarter()) {
            case 1:
                totalQuarterlySales[0].value += cs.getSales();
                break;
            case 2:
                totalQuarterlySales[1].value += cs.getSales();
                break;
            case 3:
                totalQuarterlySales[2].value += cs.getSales();
                break;
            case 4:
                totalQuarterlySales[3].value += cs.getSales();
                break;
        }
    }
}

void Driver::calcTotalDivisionSales() {
    totalDivisionSales = {
        {"North", 0}, {"South", 0}, {"East", 0}, {"West", 0}
    };

    for (CorporateSales cs : records) {
        for (int i = 0; i < totalDivisionSales.size(); i++) {
            if (cs.getName().compare(totalDivisionSales[i].name) == 0) {
                totalDivisionSales[i].value += cs.getSales();
                break;
            }
        }
    }
}

void Driver::calcTotalnAverageSales() {
    totalSales = 0;
    for (CorporateSales cs : records) {
        totalSales += cs.getSales();
    }
    averageSales = totalSales / records.size();
}

void Driver::findExtrema() {
    lowestCQuarter = highestCQuarter = totalQuarterlySales[0];
    for (int i = 1; i < totalQuarterlySales.size(); i++) {
        if (totalQuarterlySales[i].value < lowestCQuarter.value) {
            lowestCQuarter = totalQuarterlySales[i];
        } else if (totalQuarterlySales[i].value > highestCQuarter.value) {
            highestCQuarter = totalQuarterlySales[i];
        }
    }
}
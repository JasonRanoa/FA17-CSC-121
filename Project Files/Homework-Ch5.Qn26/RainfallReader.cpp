#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "RainfallReader.h"
using namespace std;

void RainfallReader::extractData() {
    ifstream source;
    int rain_count = 0;
    double temp_rain;
    rainfall_total = 0;

    source.open("Rainfall.txt");
    source >> month_start;
    source >> month_end;

    while (source >> temp_rain) {
        rainfall_total += temp_rain;
        rain_count++;
    }

    rainfall_average = rainfall_total / rain_count;
    source.close();

    return;
}

void RainfallReader::printOutput() {
    cout << "During the months of "
         << month_start << "-"
         << month_end << ", " << endl;

    cout << fixed << showpoint << setprecision(2);
    cout << "the total rainfall was " << rainfall_total << " inches " << endl
         << "and the average monthly rainfall was "
         << rainfall_average << " inches " << endl;

    return;
}
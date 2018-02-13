#include <string>
using namespace std;

class RainfallReader {

public:
    string month_start, month_end;
    double rainfall_total, rainfall_average;

    void extractData();
    void printOutput();

};
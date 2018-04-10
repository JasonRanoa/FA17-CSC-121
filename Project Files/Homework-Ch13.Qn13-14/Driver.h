//
// Created by TheLoneWoof on 11/14/17.
//

#ifndef HOMEWORK_CH13_QN13_14_DRIVER_H
#define HOMEWORK_CH13_QN13_14_DRIVER_H

#include "CorporateSales.h"
#include <vector>

struct numValuePair {
    int num;
    double value;
};

struct nameValuePair {
    std::string name;
    double value;
};

class Driver {

private:
    bool isGood = false;
    std::vector<CorporateSales> records;
    std::vector<numValuePair> totalQuarterlySales;
    std::vector<nameValuePair> totalDivisionSales;
    double totalSales;
    double averageSales;
    numValuePair lowestCQuarter;
    numValuePair highestCQuarter;

public:
    void serializeAll(std::string filename);
    void deserializeAll(std::string filename);
    bool good() { return isGood; }
    void printAll();

    void randomize();

    void getInput();
    void doCalculations();
    void calcTotalQuarterlySales();
    void calcTotalDivisionSales();
    void calcTotalnAverageSales();
    void findExtrema();

    std::vector<CorporateSales> getRecords() { return records; };
    std::vector<numValuePair> getTotalQuarterlySales() {
        return totalQuarterlySales;
    };
    std::vector<nameValuePair> getTotalDivisionSales() {
        return totalDivisionSales;
    };
    double getTotalSales() { return totalSales; };
    double getAverageSales() { return averageSales; };
    numValuePair getLowestCorporateQuarter() { return lowestCQuarter; };
    numValuePair getHighestCorporateQuarter() { return highestCQuarter; };
};


#endif //HOMEWORK_CH13_QN13_14_DRIVER_H

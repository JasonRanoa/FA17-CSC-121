//
// Created by TheLoneWoof on 11/14/17.
//

#ifndef HOMEWORK_CH13_QN13_14_CORPORATESALES_H
#define HOMEWORK_CH13_QN13_14_CORPORATESALES_H

#include <string>
#include <fstream>

class CorporateSales {

private:
    std::string divisionName;
    int quarter;
    double sales;

public:
    CorporateSales() {
        divisionName = "North";
        quarter = 1;
        sales = 0.0;
    }
    CorporateSales(std::string d, int q, double s) {
        divisionName = d;
        quarter = q;
        sales = s;
    }

    // Getters
    std::string getName() const { return divisionName; }
    int getQuarter() const { return quarter; }
    double getSales() const { return sales; }

    // Setters
    void setName(std::string n) { divisionName = n; }
    void setQuarter(int q) { quarter = q; }
    void setSales(double s) { sales = s; }

    void serialize(std::ofstream&);
    void deserialize(std::ifstream&);
    void print();
};


#endif //HOMEWORK_CH13_QN13_14_CORPORATESALES_H

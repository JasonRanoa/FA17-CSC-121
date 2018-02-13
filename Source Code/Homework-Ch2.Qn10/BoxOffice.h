#include <string>

class BoxOffice {

public:
    // User Input
    int adultTickets, childTickets;
    std::string movieName;

    // Constants, defined by the problem.
    const double adultCost = 10.0;
    const double childCost = 6.0;
    const double distributorRate = .20;

    // Placeholders.
    double grossRevenue;
    double distributorCut;
    double netRevenue;

    // Display Modifiers
    const int firstColWidth = 30;

    void getInfo();
    void calculateRevenue();
    void printReport();

};
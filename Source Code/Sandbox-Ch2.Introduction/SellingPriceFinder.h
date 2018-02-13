class SellingPriceFinder {

public:
    // User Data
    double productionCost;
    double profitPercentage;

    // Calculated Data
    double profitVal;
    double sellingPrice;

    void getStartingData();
    void determinePrice();
    void printResults();

    void run();
};
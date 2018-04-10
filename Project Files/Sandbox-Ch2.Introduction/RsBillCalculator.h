class RsBillCalculator {
public:
    double mealCost;

    const double taxRate = .0675;
    const double tipRate = .15;

    double taxAmount;
    double tipCost;
    double totalAmount;

    void retrieveMealCharge();
    void doBreakdown();
    void printResults();

    void run();
};
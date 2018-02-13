#include <string>

class HospitalBill {

private:
    int num_days;
    double daily_rate;
    double service_charges;
    double medication_charges;
    double total_charges;

public:
    // Constructor
    HospitalBill() {
        num_days = 0;
        daily_rate = service_charges = medication_charges = total_charges = 0;
    }

    // Calculation Methods
    double getTotalCharges(int, double, double, double);
    double getTotalCharges(double, double);

    // Interface Methods
    void runInterface();
    char getUserOption();
    bool askForNumbers(double&); // Returns true if successful. False if not.
    bool askForIntegers(int&);
    std::string printTextBlock(std::string, int, bool = true);
    std::string printCurrency(std::string, double, int, int = 2);
    std::string makeReport();
    void printReport();

    // File Making Methods
    bool makeFile(std::string, std::string);

    // Calculation Methods
    void getInpatientData();
    void getOutpatientData();
};
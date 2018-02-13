class ClubMembership {

public:
    const double ADULT_RATE = 120.0,
                 CHILD_RATE = 60.0,
                 SENIOR_RATE = 100.0;

    int choice;
    int months;
    double charges;

    void showMenu();
    void askMonths();
    void calculateCharges();
    void printCharges();

    void runMe();

    // Here's the procedural code.
    void proceduralClub();
};
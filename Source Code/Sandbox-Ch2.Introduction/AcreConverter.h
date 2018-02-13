
class AcreConverter {

public:
    double valAcre;

    const double sqFeet_perAcre = 43560.0;
    const double sqFeet_perSqMeter = 10.7639;

    double valSqMeters;
    double valSqFeet;

    void getAcres();
    void calculateStuff();
    void printResults();

    void run();
};
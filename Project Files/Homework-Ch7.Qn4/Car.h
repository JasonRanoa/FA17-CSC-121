#include <string>

class Car {

private:
    int year;
    std::string make;
    int speed;

public:
    // Constructor
    Car(int, std::string);

    // Accessors
    int getYear();
    std::string getMake();
    int getSpeed();

    // Methods
    void accelerate();
    void brake();
};
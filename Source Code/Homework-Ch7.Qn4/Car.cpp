#include "Car.h"

// Constructor
Car::Car(int y, std::string m) {
    year = y;
    make = m;
    speed = 0;
}

// Accessors
int Car::getYear() {
    return year;
}

std::string Car::getMake() {
    return make;
}

int Car::getSpeed() {
    return speed;
}

// Methods
void Car::accelerate() {
    speed += 5;
}

void Car::brake() {
    if (speed - 5 < 0) {
        speed = 0;
    } else speed -= 5;
}
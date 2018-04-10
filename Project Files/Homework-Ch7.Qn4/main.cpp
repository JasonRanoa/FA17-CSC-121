#include <iostream>
#include "Car.h"
using namespace std;

int main() {
    Car c = Car(1996, "Something");

    cout << "Make: " << c.getMake() << endl;
    cout << "Year: " << c.getYear() << endl;

    for (int i = 5; i > 0; i--) {
        c.accelerate();
        cout << "Accelerating... ";
        cout << c.getSpeed() << endl;
    }

    for (int i = 5; i > 0; i--) {
        c.brake();
        cout << "Braking...      ";
        cout << c.getSpeed() << endl;
    }
}
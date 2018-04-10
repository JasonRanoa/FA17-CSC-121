#include <iostream>
#include <iomanip>
#include "GeometryCalculator.h"
using namespace std;

void GeometryCalculator::runZeCalculator() {
    switch (getMenuFeedback()) {
        case CIRCLE:
            doCircleMethod();
            sayBye();
            break;
        case RECTANGLE:
            doRectangleMethod();
            sayBye();
            break;
        case TRIANGLE:
            doTriangleMethod();
            sayBye();
            break;
        case EXIT:
            sayBye();
            break;
        default:
            goNuts();
    }

    return;
}

void GeometryCalculator::goNuts() {
    cout << "Whoops!" << endl;
    cout << "The program doesn't know what to do now. " << endl;
    cout << "You must have entered an invalid input. " << endl << endl;

    cout << "Please close this program and try again. " << endl;
    return;
}

void GeometryCalculator::sayBye() {
    cout << "Goodbye! " << endl;
    cout << "This program has done its job. " << endl;

    return;
}

int GeometryCalculator::getMenuFeedback() {
    int choice;

    cout << "Geometry Calculator." << endl << endl;

    cout << "     1. Calculate the Area of a Circle" << endl;
    cout << "     2. Calculate the Area of a Rectangle" << endl;
    cout << "     3. Calculate the Area of a Triangle" << endl;
    cout << "     4. Quit" << endl;

    cout << endl << "Enter your choice (1-4): ";
    cin >> choice;

    cout << endl;
    return choice;
}

bool GeometryCalculator::isMeasureValid(double input) {
    if (input >= 0) return true;
    else return false;
}

void GeometryCalculator::doCircleMethod() {
    double radius;

    cout << "To calculate the area of a circle, "
         << "we need the radius. " << endl;
    cout << "Please enter the value as prompted." << endl << endl;

    cout << "    Radius? ";
    cin >> radius;
    cout << endl;

    if (isMeasureValid(radius)) {
        cout << fixed << showpoint << setprecision( AREA_PRECISION );
        cout << "Yay! The area of the circle is " << getCircleArea(radius) << " square units!" << endl << endl;
    } else goNuts();

    return;
}

double GeometryCalculator::getCircleArea(double radius) {
    return PI * radius * radius;
}

void GeometryCalculator::doRectangleMethod() {
    double length, width;

    cout << "To calculate the area of a rectangle, "
         << "we need the length and width. " << endl;
    cout << "Please enter the value as prompted." << endl << endl;

    cout << "    Length? ";
    cin >> length;
    cout << "    Width? ";
    cin >> width;
    cout << endl;

    if (isMeasureValid(length) && isMeasureValid(width)) {
        cout << fixed << showpoint << setprecision( AREA_PRECISION );
        cout << "Yay! The area of the rectangle is "
             << getRectArea(length, width)
             << " square units!" << endl << endl;
    } else goNuts();

    return;
}

double GeometryCalculator::getRectArea(double length, double width) {
    return length * width;
}

void GeometryCalculator::doTriangleMethod() {
    double base, height;

    cout << "To calculate the area of a triangle, "
         << "we need the base and height. " << endl;
    cout << "Please enter the value as prompted." << endl << endl;

    cout << "    Base? ";
    cin >> base;
    cout << "    Height? ";
    cin >> height;
    cout << endl;

    if (isMeasureValid(base) && isMeasureValid(height)) {
        cout << fixed << showpoint << setprecision( AREA_PRECISION );
        cout << "Yay! The area of the triangle is "
             << getTriangleArea(base, height)
             << " square units!" << endl << endl;
    } else goNuts();

    return;
}

double GeometryCalculator::getTriangleArea(double base, double height) {
    return (base * .5) * height;
}

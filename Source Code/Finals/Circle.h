#ifndef FINALS_CIRCLE_H
#define FINALS_CIRCLE_H


class Circle {

private:
    double radius;
    double pi = 3.12159;

public:
    // Constructors
    Circle() { radius = 0; }
    Circle(double r) { radius = r; }

    // Mutators and Accessors
    void setRadius(double r) { radius = r; }
    double getRadius() { return radius; }
    double getArea();
    double getDiameter();
    double getCircumference();

};


#endif //FINALS_CIRCLE_H

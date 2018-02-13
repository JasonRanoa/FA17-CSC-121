//
// Created by TheLoneWoof on 12/7/17.
//

#include "Circle.h"

double Circle::getArea() {
    return pi * radius * radius;
}

double Circle::getDiameter() {
    return radius * 2;
}

double Circle::getCircumference() {
    return 2 * pi * radius;
}
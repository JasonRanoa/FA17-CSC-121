//
// Created by TheLoneWoof on 10/24/17.
//

#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() {
    width = height = 0;
}

Rectangle::Rectangle(int w, int h) {
    width = w;
    height = h;
}

int Rectangle::getWidth() {
    return width;
}

int Rectangle::getHeight() {
    return height;
}

void Rectangle::setWidth(int w) {
    width = w;
}

void Rectangle::setHeight(int h) {
    height = h;
}

void Rectangle::magnify(int mFactor) {
    height *= mFactor;
    width *= mFactor;
}

void Rectangle::output() {
    std::cout << "width: " << width
              << " height: " << height
              << std::endl;
}

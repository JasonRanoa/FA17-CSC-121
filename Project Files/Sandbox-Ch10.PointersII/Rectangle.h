//
// Created by TheLoneWoof on 10/24/17.
//

#ifndef SANDBOX_CH10_POINTERSII_RECTANGLE_H
#define SANDBOX_CH10_POINTERSII_RECTANGLE_H


class Rectangle {

private:
    int width, height;

public:
    Rectangle();
    Rectangle(int, int);

    int getWidth();
    int getHeight();
    void setWidth(int);
    void setHeight(int);

    void magnify(int);
    void output();
};


#endif //SANDBOX_CH10_POINTERSII_RECTANGLE_H

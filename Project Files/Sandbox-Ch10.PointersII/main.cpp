#include "Rectangle.h"
#include "Person.h"
#include <iostream>
using namespace std;

int main() {
    Rectangle *r = new Rectangle();
    r->setWidth(4);
    r->setHeight(2);
    cout << "Initial size of rectangle is ";
    r->output();
    r->magnify(3);
    cout << "Size of rectangle after magnification is ";
    r->output();

    delete r;
    r = nullptr;

    cout << endl;

    Person *p = new Person("Anna Milton", 21);
    cout << "The name " << p->getName()
         << " has length " << p->lengthOfName() << endl;

    delete p;
    p = nullptr;

    return 0;
}
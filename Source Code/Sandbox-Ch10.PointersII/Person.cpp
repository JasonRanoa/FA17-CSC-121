//
// Created by TheLoneWoof on 10/24/17.
//

#include "Person.h"

Person::Person() {
    name = "";
    age = 0;
}

Person::Person(std::string n, int a) {
    name = n;
    age = a;
}

std::string Person::getName() {
    return name;
}

int Person::getAge() {
    return age;
}

void Person::setName(std::string newName) {
    name = newName;
}

void Person::setAge(int newAge) {
    age = newAge;
}

int Person::lengthOfName() {
    return name.length();
}
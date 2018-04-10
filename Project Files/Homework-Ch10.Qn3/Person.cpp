//
// Created by TheLoneWoof on 10/24/17.
//

#include "Person.h"

Person::Person() {
    name = "";
    age = 0;
}

Person::Person(std::string s, int i) {
    name = s;
    age = i;
}

std::string Person::getName() {
    return name;
}

std::string Person::getUppercaseName() {
    std::string uName = name;
    for (int i = 0; i < uName.length(); i++) {
        uName[i] = toupper(uName[i]);
    }
    return uName;
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

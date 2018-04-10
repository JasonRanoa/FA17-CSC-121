//
// Created by TheLoneWoof on 10/24/17.
//

#ifndef HOMEWORK_CH10_QN3_PERSON_H
#define HOMEWORK_CH10_QN3_PERSON_H

#include <string>

class Person {

private:
    std::string name;
    int age;

public:
    Person();
    Person(std::string, int);

    std::string getName();
    std::string getUppercaseName();
    int getAge();

    void setName(std::string);
    void setAge(int);
};

#endif //HOMEWORK_CH10_QN3_PERSON_H

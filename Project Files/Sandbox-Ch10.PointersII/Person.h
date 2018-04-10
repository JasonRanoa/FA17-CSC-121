//
// Created by TheLoneWoof on 10/24/17.
//

#ifndef SANDBOX_CH10_POINTERSII_PERSON_H
#define SANDBOX_CH10_POINTERSII_PERSON_H

#include <string>

class Person {

private:
    std::string name;
    int age;

public:
    Person();
    Person(std::string, int);

    int getAge();
    std::string getName();
    void setAge(int);
    void setName(std::string);

    int lengthOfName();

};


#endif //SANDBOX_CH10_POINTERSII_PERSON_H

//
// Created by TheLoneWoof on 10/20/17.
//

#ifndef HOMEWORK_CH10_QN3_PERSONLIST_H
#define HOMEWORK_CH10_QN3_PERSONLIST_H

#include <string>
#include <vector>
#include "Person.h"

class PersonList {

private:
    Person* people;
    int size = 0;

public:
    PersonList();
    PersonList(int);
    ~PersonList();

    int getSize();
    std::vector<Person> getEasyList();
    Person getPersonByIdx(int);

    void setSize(int);
    void setPersonByIdx(int, Person);

    void sortListByName();
};


#endif //HOMEWORK_CH10_QN3_PERSONLIST_H

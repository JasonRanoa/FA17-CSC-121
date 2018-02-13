//
// Created by TheLoneWoof on 10/20/17.
//

#include "PersonList.h"
#include <iostream>
using namespace std;

PersonList::PersonList() {
    size = 0;
    people = nullptr;
}

PersonList::PersonList(int listLength) {
    size = listLength;
    people = new Person[size];
}

PersonList::~PersonList() {
    delete [] people;
    people = nullptr;
    size = 0;
}

int PersonList::getSize() {
    return size;
}

vector<Person> PersonList::getEasyList() {
    vector<Person> l;
    for (int i = 0; i < size; i++) {
        l.push_back(people[i]);
    }
    return l;
}

Person PersonList::getPersonByIdx(int idx) {
    if (idx >= size || idx < 0) return Person();
    else return people[idx];
}

void PersonList::setSize(int listLength) {
    Person* temp_people = new Person[listLength];
    for (int i = 0; i < listLength && i < size; i++) {
        temp_people[i] = people[i];
    }
    delete [] people;
    people = temp_people;
    size = listLength;
    temp_people = nullptr;
}

void PersonList::setPersonByIdx(int idx, Person p) {
    if (idx < size && idx >= 0) {
        people[idx] = p;
    } else; // throw a fit.
}

void PersonList::sortListByName() {
    // Customized version of the Selection Sort
    Person** temp_PointerList;
    temp_PointerList = new Person*[size];
    for (int i = 0; i < size; i++) {
        temp_PointerList[i] = people + i;
    }

    Person* min_person;
    int min_index;

    for (int i = 0; i < size; i++) {
        min_index = i;
        min_person = temp_PointerList[i];
        for (int j = i + 1; j < size; j++) {
            if (temp_PointerList[j]->getUppercaseName() < min_person->getUppercaseName()) {
            // if ((*temp_PointerList[j]).name < (*min_person).name) {
                min_index = j;
                min_person = temp_PointerList[j];
            }
        }
        if (min_person != temp_PointerList[i]) {
            temp_PointerList[min_index] = temp_PointerList[i];
            temp_PointerList[i] = min_person;
        }
    }

    // Make a cache of the proper list of objects.
    // I can't directly assign temp_PointerList to people.
    // since they're referring to the same addresses.
    Person* temp_PersonList = new Person[size];
    for (int i = 0; i < size; i++) {
        temp_PersonList[i] = *(temp_PointerList[i]);
    }
    for (int i = 0; i < size; i++) {
        people[i] = temp_PersonList[i];
    }

    delete [] temp_PersonList;
    delete [] temp_PointerList;
    temp_PersonList = nullptr;
    temp_PointerList = nullptr;
}
#include "PersonList.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    PersonList pl;

    // TEST DATA.
    srand(time(NULL));
    string testNames[] = {
        "Ed", "Cara", "Bob", "Geoffrey", "Anna", "Faye", "Derek"
    };
    int size = sizeof(testNames) / sizeof(testNames[0]);
    pl.setSize(size);
    for (int i = 0; i < pl.getSize(); i++) {
        pl.setPersonByIdx(i, Person(testNames[i], (rand() % 40) + 10));
    }
    // End Test Data

    cout << "UNSORTED LIST: " << endl;
    for (Person p : pl.getEasyList()) {
        cout << "  ";
        cout << "Name: " << setw(10) << left << p.getName();
        cout << "Age: " << p.getAge() << endl;
    }
    cout << endl;

    pl.sortListByName();

    // Another way of accessing members.
    cout << "SORTED LIST: "<< endl;
    for (int i = 0; i < pl.getSize(); i++) {
        cout << "  ";
        cout << "Name: " << setw(10) << left << pl.getPersonByIdx(i).getName();
        cout << "Age: " << pl.getPersonByIdx(i).getAge() << endl;
    }


    return 0;
}
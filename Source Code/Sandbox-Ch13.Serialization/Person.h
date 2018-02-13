//
// Created by TheLoneWoof on 11/14/17.
//

#ifndef SANDBOX_CH13_SERIALIZATION_PERSON_H
#define SANDBOX_CH13_SERIALIZATION_PERSON_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person
{

private:
    string fname, lname;
    char mi;
    int age;

public:
    string getFname(){return fname;}
    string getLname(){return lname;}
    char getMi(){return mi;}
    int getAge(){return age;}

    void setFname(string name){fname = name;}
    void setLname(string name){lname = name;}
    void setMi(char ch){mi = ch;}

    // Read data from file
    void load(ifstream &inFile);
    // Store data to file
    void store(ofstream  &outFile);

    // Constructor
    Person(string fname = "", char mi = 0,
           string lname = "", int age = 0);

    void display()
    {
        cout << fname << " " << mi << " " << lname << endl
             << "Age : " << age << endl;
    }

};

#endif //SANDBOX_CH13_SERIALIZATION_PERSON_H
